#define WM_MOUSE_HOOK    WM_USER+1001  //自定义消息
extern "C" {
	__declspec(dllexport)  BOOL APIENTRY StartHook(); //安装鼠标钩子
	__declspec(dllexport)  BOOL APIENTRY EndHook();   //删除钩子
	LRESULT WINAPI MouseProc(int nCode, WPARAM wparam, LPARAM lparam);
}

extern HANDLE hInstance;
extern HHOOK hHook;