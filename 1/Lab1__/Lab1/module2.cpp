#include "stdafx.h"
#include "module2.h"
#include "module2.rh"

static BOOL CALLBACK Work2(HWND, UINT, WPARAM, LPARAM);
static char temp1[4];
static int pos;


int Func_MOD2(HINSTANCE hInst, HWND hWnd, char*& n, int* pox)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Work2) && (n = temp1) && (pox=&pos);
}

static BOOL CALLBACK Work2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage)
	{
	case WM_HSCROLL:
		SetScrollRange(GetDlgItem(hDlg, IDC_SCROLLBAR), SB_CTL, 0, 100, FALSE);
		pos = GetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR), SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			pos--;
			break;
		case SB_LINERIGHT:
			pos++;
			break;
		case SB_THUMBPOSITION: break;
		case SB_THUMBTRACK:
			pos = HIWORD(wParam);
			break;
		default: break;
		}
		SetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR), SB_CTL, pos, TRUE);
		_ltoa_s(pos, temp1, 10);
		SetDlgItemText(hDlg, IDC_STATIC, temp1);
		break;
	case WM_INITDIALOG: return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, 1);
			break;
		}
		if (LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
		break;
	default: break;
	}
	return FALSE;
}