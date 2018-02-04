#include "util.h"

VOID WriteMemory(int Address, PVOID Patch, size_t Size) {
	DWORD OldProtection;
	VirtualProtect((PVOID)Address, Size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy((PVOID)Address, Patch, Size);
	VirtualProtect((PVOID)Address, Size, OldProtection, &OldProtection);
}

VOID OpenConsole(PCHAR Title) {
	WriteMemory((int)FreeConsole, "\xC3", 1);
	AllocConsole();
	SetConsoleTitle(Title);
	freopen("conout$", "w", stdout);
}

DWORD FindFunctionByModule(PCHAR ModuleName, PCHAR Function) {
	HMODULE Module = GetModuleHandle(ModuleName);
	if (Module == NULL)
		printf("Invalid handle to the specified module.");

	return (DWORD)GetProcAddress(Module, Function);
}