#include "stdafx.h"
#include "module1.h"
#include "module1.rh"


static BOOL CALLBACK Work1(HWND, UINT, WPARAM, LPARAM);


static HWND h;
static HINSTANCE hI;

int MyWork1(HINSTANCE hInst, HWND hWnd) 
{
	h = hWnd;
	hI = hInst;
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}


static BOOL CALLBACK Work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			MyWork1_1();
		}
		if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, -1);

		break;
	default: break;
	}
	return FALSE;
}
