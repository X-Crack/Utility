﻿#include <debuger\debuger.h>
#include <process\processenv.hpp>
#include <iostream>
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	using namespace Cry;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{
		DisableThreadLibraryCalls(hModule);
		OutputMessage("Loading Completed\r\n");
		#ifndef _DEBUG
		ProcessBasic::HideBreakpoint(GetCurrentThread());
		#endif
		break;
	}
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}