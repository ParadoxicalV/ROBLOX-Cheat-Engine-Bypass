#include <Windows.h>
#include <iostream>

VOID WriteMemory(int Address, PVOID Patch, size_t Size);
VOID OpenConsole(PCHAR Title);
DWORD FindFunctionByModule(PCHAR ModuleName, PCHAR Function);