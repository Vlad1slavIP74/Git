#include "stdafx.h"
#include "module2.h"
#include "module2.rh"

static BOOL CALLBACK Work3(HWND, UINT, WPARAM, LPARAM);
static int indx;

char *buff1 = new char[1];

char MyWork3(HINSTANCE hInst, HWND hWnd, char* &buff)
{
	
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, Work3) && (buff = buff1);
}

 BOOL CALLBACK Work3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	 switch (message)
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
			 
			 indx = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
			 SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, indx, (long)buff1);
			 RedrawWindow(NULL, NULL, NULL, RDW_INTERNALPAINT | RDW_UPDATENOW | RDW_ALLCHILDREN | RDW_INVALIDATE);
			 EndDialog(hDlg, 1);
			 break;
		 }
		 if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDCANCEL) EndDialog(hDlg, 0);
		 break;
	 default: break;
	 }
	 return FALSE;
}