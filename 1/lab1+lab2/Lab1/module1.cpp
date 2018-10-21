#include "module1.h"

#define SIZE 100

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_N0_DEPRECATE

static HINSTANCE hInst;
static int position = 0;
static char row[4] = "";
static int weScroll(WPARAM wParam, int position);
INT_PTR CALLBACK Dialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SetScrollPos(hDlg, SB_HORZ, position, TRUE);
		return (INT_PTR)TRUE;
		if (lParam == IDC_SCROLLBAR1) {
	case WM_HSCROLL:
		SetScrollRange(hDlg, SB_HORZ, 1, 100, TRUE);
		position = weScroll(wParam, position);
		SetScrollPos(hDlg, SB_HORZ, position, TRUE);
		if (position > 100) position = 100;
		if (position < 1) position = 1;
		_itoa_s(position, row, 10);
		wchar_t* w = new wchar_t[100];
		mbstowcs(w, row, 10);
		SetDlgItemText(hDlg, IDC_STATIC, w);
		SetScrollPos(hDlg, SB_HORZ, position, TRUE);
		delete(w);

		}
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			if (position > 100) position = 100;
			if (position < 1) position = 1;
			_itoa_s(position, row, 10);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDCANCEL:
			strcpy_s(row, "   ");
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}

void MyWork(HWND hWnd, char* row2) {
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dialog);
	strcpy(row2, row);
}

int weScroll(WPARAM wParam, int position)
{
	switch (LOWORD(wParam)) {
	case SB_PAGERIGHT:
		position += 15;
		return position;
		break;
	case SB_PAGELEFT:
		position -= 15;
		return position;
		break;
	case SB_LINERIGHT:
		position++;
		return position;
		break;
	case SB_LINELEFT:
		position--;
		return position;
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK: {
		position = HIWORD(wParam);
		return position;
		break;
	}
	}
	return position;
}
