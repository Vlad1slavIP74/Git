#include "module1_1.h"
#include "module1.rh"


static BOOL CALLBACK Work1_1(HWND, UINT, WPARAM, LPARAM);

static HWND h;
static HINSTANCE hI;


int MyWork1_1()
{
	return DialogBox(hI, MAKEINTRESOURCE(IDD_DIALOG2), h, Work1_1);
}


static BOOL CALLBACK Work1_1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{

		}
		if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDC_BUTTON1) EndDialog(hDlg, -1);

		break;
	default: break;
	}
	return FALSE;
}