#include "stdafx.h"
#include "module1.h"
#include "module1.rh"


static char buff1[80];

static BOOL CALLBACK Work1(HWND, UINT, WPARAM, LPARAM);

int Func_MOD1(HINSTANCE hInst, HWND hWnd, char*& tex)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1) && (tex = buff1);
}

static BOOL CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			for (int i = 0; i < 80; i++) buff1[i] = 0;
			GetDlgItemText(hDlg, IDC_EDIT, buff1, 80);
			EndDialog(hDlg, 1);
			break;
		}
		if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
		break;
	default: break;
	}
	return FALSE;
}