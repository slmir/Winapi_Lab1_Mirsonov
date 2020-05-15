#include <Windows.h>
#include <Windowsx.h>
#include <tchar.h>
#include <iostream>
const int x = 1000;
const int y = 700;
LRESULT CALLBACK HelloWordWndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	WNDCLASS WndClass;
	MSG Msg;
	TCHAR szClassName[] = _T("MainWindow");
	TCHAR szTitel[] = _T("Мирсонов Лаб.1");
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = HelloWordWndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(245, 173, 103));
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = szClassName;
	if (!RegisterClass(&WndClass))
	{
		MessageBox(NULL, _T("Cannot register class"), _T("Error"), MB_OK);
		return 0;
	}
	hWnd = CreateWindow(szClassName, szTitel, WS_OVERLAPPEDWINDOW, 20,20,x,y, NULL, NULL, hInstance, NULL);
	if (!hWnd)
	{
		MessageBox(NULL, _T("Cannot create window"), _T("Error"), MB_OK);
		return 0;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&Msg, NULL, 0, 0))
	{		
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

LRESULT CALLBACK HelloWordWndProc(HWND hWnd, UINT Message, UINT wParam, LONG lParam)
{
	HDC hDC;
	TCHAR szText[] = _T("Мирсонов Вячеслав, группа РТ5-41Б");
	PAINTSTRUCT PaintStruct;
	RECT Rect;
	HFONT hFont;
	TCHAR szTitel1[] = _T("Мирсонов Лаб.1");
	switch (Message)
	{	
	case WM_LBUTTONDOWN:
		InvalidateRect(hWnd,&Rect,TRUE);
		break;
	case WM_PAINT:	
			hDC = BeginPaint(hWnd, &PaintStruct);
			GetClientRect(hWnd, &Rect);
			SetTextColor(hDC, RGB(rand()%200 + 0, rand() % 200 + 0, rand() % 200 + 0));
			SetBkColor(hDC, RGB(245, 173, 103));
			hFont = CreateFont(30, 14, -450, -450, 0, 0, 0, 0,
				DEFAULT_CHARSET,
				0, 0, 0, 0,
				L"Arial Bold");
			SelectObject(hDC, hFont);
			TextOut(hDC, Rect.left + 20, Rect.bottom-400, szText, 34);
			EndPaint(hWnd, &PaintStruct);
		break;
	case WM_RBUTTONDOWN:
		ShowWindow(hWnd,SW_MINIMIZE);
		InvalidateRect(hWnd, &Rect, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, Message, wParam, lParam);
}