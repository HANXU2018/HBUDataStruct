#pragma comment(linker,"/SUBSYSTEM:Windows  /ENTRY:mainCRTStartup")
#include <windows.h>
/* ʹ������Ϊȫ�ֱ��� */
TCHAR szClassName[ ] = TEXT("WindowsApp");
/* ���������Windows�ڲ�����DispatchMessage()���� */
LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc ;
    PAINTSTRUCT ps ;
    RECT rect ;
    switch (message)  /* ������Ϣ */
    {
        case WM_DESTROY:
            PostQuitMessage (0);  /* ����WM_QUIT����Ϣ���� */
            break;
        case WM_PAINT:
            hdc = BeginPaint (hWnd, &ps) ;
            GetClientRect (hWnd, &rect) ;
            DrawText (hdc, TEXT("Hello, Windows NT!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;
            EndPaint (hWnd, &ps) ;
            break ;
        default:  /* ���������Ϣ */
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
    return 0;
}
/* ������������ */
int main ( void )
{
    HINSTANCE hThisInstance = GetModuleHandle(NULL) ;
    int nFunsterStil = SW_SHOW ;
    HWND hWnd; /* ���Ǵ��ڵľ�� */
    MSG messages;/* Ӧ�ó������Ϣ���������� */
    WNDCLASSEX wincl;/* ����������ݽṹ */
    /* ���ڽṹ */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;/* ���������Windows����ϵͳ���� */
    wincl.style = CS_DBLCLKS; /* ��ȡ˫��ָ�� */
    wincl.cbSize = sizeof (WNDCLASSEX);
    /* ʹ��Ĭ��ͼ������ָ�� */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL; /* û�в˵� */
    wincl.cbClsExtra = 0;/* ���������û�ж�����ֽ� */
    wincl.cbWndExtra = 0;/* �ṹ���ߴ���ʵ�� */
    /* ʹ�ô��ڵ�Ĭ����ɫ��Ϊ���ڵı���ɫ */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    /* ע�ᴰ���ࡣ���ע��ʧ�ܣ���ô���˳����� */
    if (!RegisterClassEx (&wincl))
        return 0;
    /* �������ѱ�ע�ᡣ�������ĳ��� */
    hWnd = CreateWindowEx (
            0,
            szClassName,    /* ���� */
            TEXT("Windows App"),    /* ���ڱ����������� */
            WS_OVERLAPPEDWINDOW, /* Ĭ�ϴ��� */
            CW_USEDEFAULT, /* �������Ͻǵ�λ�� */
            CW_USEDEFAULT, /* �������½ǵ�λ�� */
            300, /* ���ڿ�ȣ��ԡ����ء�λ��λ�� */
            300, /* ���ڸ߶ȣ��ԡ����ء�λ��λ�� */
            HWND_DESKTOP,/* ������������Ӵ��� */
            NULL,/* �ô����޲˵� */
            hThisInstance, /* ����ʵ���ľ�� */
            NULL /* û�д��ڴ��������� */
            );
    /* ��ʾ���� */
    ShowWindow (hWnd, nFunsterStil);
    /* �ػ洰�� */
    UpdateWindow(hWnd);
    /* ������Ϣѭ����ѭ����GetMessage()��������0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* ��������Ϣ������ַ���Ϣ */
        TranslateMessage(&messages);
        /* ������Ϣ�����ڹ��� */
        DispatchMessage(&messages);
    }
    /* ����PostQuitMessage()�����ķ���ֵ */
    return messages.wParam;
}

