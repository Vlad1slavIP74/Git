#include "stdafx.h"
#include "module1.h"
#include "Lab.rc"
static char buff1[80];
static BOOL CALLBACK Work(HWND, UINT, WPARAM, LPARAM);

int MyWork(HINSTANCE hInst, HWND hwnd)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, Work);
}


static BOOL CALLBACK Work(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
//			MyWork2(hDlg);
		}
		if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
		break;
	default: break;
	}
	return FALSE;
}
