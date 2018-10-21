#include "stdafx.h"
#include "module2.h"
#include "resource2.h"

static BOOL CALLBACK Work2(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst1;
HWND hWnd1;


int Func_MOD2(HINSTANCE hInst, HWND hWnd)
{
	hInst1 = hInst;
	hWnd1 = hWnd;
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_WORK2_1), hWnd, Work2);
}

BOOL CALLBACK Work2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDNEXT)
		{	
			DialogBox(hInst1, MAKEINTRESOURCE(IDD_WORK2_2), hWnd1, Work2);
			EndDialog(hDlg, 0);
			break;
		}
		if (LOWORD(wParam) == IDBACK)
		{
			DialogBox(hInst1, MAKEINTRESOURCE(IDD_WORK2_1), hWnd1, Work2);
			EndDialog(hDlg, 0);
			break;
		}
		if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDOK) EndDialog(hDlg, 0);
		break;
	default: break;
	}
	return FALSE;
}