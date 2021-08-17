# COM-Hijacking

An example of COM hijacking using a proxy DLL.

## Demo using getmac/wbemprox.dll

- Generate the forward exports for MinGW or MSVC
  - Copy wbemprox DLL to current directory
  - `python3 ./generate-exports.py .\wbemprox.dll 'C:\\Windows\\System32\\wbem\\wbemprox.Dll'`
  - Copy MSVC output to `com_hijacking.cpp` or MinGW output to `exports.def`
- Compile with script for MinGW or MSVC
- Create registry entry from low or medium privilege user by running `modify-registry.reg`
- Copy the DLL to the path in `modify-registry.reg`, in this case `C:\Windows\Temp`
- Run `getmac` and see message box

## Reference

- https://attackiq.com/2020/03/26/component-object-model-hijacking/
- https://github.com/tothi/dll-hijack-by-proxying
