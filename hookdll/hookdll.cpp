// hookdll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "hookdll.h"

HANDLE hInstance = NULL;
HHOOK hHook = NULL;

LRESULT WINAPI MouseProc(int nCode, WPARAM wparam, LPARAM lparam)
{
	LPMOUSEHOOKSTRUCT hMouseHook = (MOUSEHOOKSTRUCT *)lparam;
	HWND hWnd = FindWindow(NULL, L"钩子");
	if (nCode >= 0 && hWnd) {
		SendMessage(hWnd, WM_MOUSE_HOOK, hMouseHook->pt.x, hMouseHook->pt.y);

	}

	return CallNextHookEx(hHook, nCode, wparam, lparam);
}

BOOL APIENTRY StartHook()
{
	if (!hHook) {
		hHook = SetWindowsHookEx(WH_MOUSE, (HOOKPROC)MouseProc, (HINSTANCE)hInstance, NULL);
	}
	return (bool)hHook;
}

BOOL APIENTRY EndHook()
{
	if (hHook && UnhookWindowsHookEx(hHook)) {
		hHook = NULL;
		return true;
	}
	else return false;
}
