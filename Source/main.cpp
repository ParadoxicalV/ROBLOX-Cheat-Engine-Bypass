#include <Windows.h>
#include <iostream>

#include "util.h"

DWORD WINAPI Main() {
	OpenConsole(NULL);
	printf("Disables the roblox Cheat Engine check.\n");

	int GetWindowTextAddress = FindFunctionByModule("User32.dll", "GetWindowTextA");
	WriteMemory(GetWindowTextAddress, "\xC3", 1);

	return 0;
}

BOOL DllMain(HMODULE Dll, DWORD Reason, PVOID Reserved) {
	switch (Reason) {
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)Main, NULL, 0, NULL);
		break;
	}

	return TRUE;
}
