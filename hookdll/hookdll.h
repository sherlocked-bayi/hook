#define WM_MOUSE_HOOK    WM_USER+1001  //�Զ�����Ϣ
extern "C" {
	__declspec(dllexport)  BOOL APIENTRY StartHook(); //��װ��깳��
	__declspec(dllexport)  BOOL APIENTRY EndHook();   //ɾ������
	LRESULT WINAPI MouseProc(int nCode, WPARAM wparam, LPARAM lparam);
}

extern HANDLE hInstance;
extern HHOOK hHook;