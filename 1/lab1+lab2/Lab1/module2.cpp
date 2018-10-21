#include "module2.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_N0_DEPRECATE
static HINSTANCE hInst;
static LPTSTR STR;
static HWND hWnd;
static wchar_t buffer[255];
static char res[255] = "";
static int index;

INT_PTR CALLBACK MyWork2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			//strcpy(res, "     ");   хочу обнулить строку
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDOK)
		{
			GetDlgItemText(hDlg, IDC_EDIT1, buffer, 100);

			InvalidateRect(hWnd, NULL, TRUE);
			EndDialog(hDlg, LOWORD(wParam));
			//return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void MyWork2(HWND hWnd, char* res2)
{
	DialogBox(hInst, MAKEINTRESOURCE(IDD_WORK), hWnd, MyWork2);

	sprintf(res2, "%S", buffer);
	
}