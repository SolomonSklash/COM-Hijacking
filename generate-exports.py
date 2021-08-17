#!/usr/bin/python3

# Borrowed from https://github.com/tothi/dll-hijack-by-proxying

import pefile, sys

if len(sys.argv) != 3:
    print('Missing args! need the DLL path and the file path to it in Windows.')
    exit(1)

dll_name = sys.argv[1]
dll = pefile.PE(dll_name)
path = sys.argv[2]

print("MinGW:\nEXPORTS")
for export in dll.DIRECTORY_ENTRY_EXPORT.symbols:
    if export.name:
        print('\t{}="{}".{} @{}'.format(export.name.decode(), path, export.name.decode(), export.ordinal))

print("MSVC:\nEXPORTS")
for export in dll.DIRECTORY_ENTRY_EXPORT.symbols:
    if export.name:
        print('\t#pragma comment(linker, "/export:{}=\\"{}.{}\\"")'.format(export.name.decode(), path, export.name.decode()))
