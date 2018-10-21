#include "stdafx.h"
#include "module1.h"
#include "resource1.h"

static int indx;
static BOOL CALLBACK Work1(HWND, UINT, WPARAM, LPARAM);
static char buff1[1];

char Func_MOD1(HINSTANCE hInst, HWND hWnd, char* &buff)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_WORK1), hWnd, Work1) && (buff = buff1);
}



BOOL CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage)
	{
	case WM_INITDIALOG:
		SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)_T("IP-71"));
		SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)_T("IP-72"));
		SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)_T("IP-73"));
		SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)_T("IP-74"));
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			//... можливо, щось ще
			//зчитуємо вибраний елементу списку у буфер
			indx = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, indx, (long)buff1);
			//... можливо, щось ще
			EndDialog(hDlg, 1);
			break;
		}
		if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
		break;
	default: break;
	}
	return FALSE;
}
