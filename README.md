# COM-Hijacking

An example of COM hijacking using a proxy DLL.

## Demo using getmac/wbemprox.dll

In this demo, we use the fact that the `getmac.exe` command looks for a COM object located at `HKCU\Software\Classes\CLSID\{4234d49b-0245-4df3-b780-3893943456e1}\InProcServer32`. It doesn't find it, so it moves on to HKEY_ROOT_CLASSES location for the same object. If we create the original registry key and point it to a proxied DLL, `getmac.exe` will execute the "payload" in our DLL and still allow the command to work.

- Generate the forward exports for MinGW or MSVC
  - Copy wbemprox DLL to current directory
  - `python3 ./generate-exports.py .\wbemprox.dll 'C:\\Windows\\System32\\wbem\\wbemprox.Dll'`
  - Copy MSVC output to `com_hijacking.cpp` or MinGW output to `exports.def`
- Compile with script for MinGW or MSVC
- Create registry entry from low or medium privilege user by running `modify-registry.reg`
- Copy the DLL to the path in `modify-registry.reg`, in this case `C:\Windows\Temp`
- Run `getmac` and see message box

## References

- https://attackiq.com/2020/03/26/component-object-model-hijacking/
- https://github.com/tothi/dll-hijack-by-proxying
