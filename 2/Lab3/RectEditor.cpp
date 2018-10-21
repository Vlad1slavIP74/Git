#include "stdafx.h"
#include "RectEditor.h"
#include "RectShape.h"


void RectEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt_start);
	ScreenToClient(hWnd, &pt_start);
	pt_old = pt_start;
	isDown = true;
}

void RectEditor::OnLBup(HWND hWnd)
{
	isDown = false;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[count] = new RectShape();
	pcshape[count]->Set(pt_start.x, pt_start.y, pt_old.x, pt_old.y);
	count++;
}

void RectEditor::OnMouseMove(HWND hWnd)
{
	if (isDown)
	{
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc;
		COLORREF color = RGB(20,0,225) ;
		hdc = GetDC(hWnd); 
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(0, 1, color);
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		Rectangle(hdc, pt_start.x, pt_start.y, pt_old.x, pt_old.y); 
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pt_old = pt;
		Rectangle(hdc, pt_start.x, pt_start.y, pt_old.x, pt_old.y);
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}

void RectEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	pcshape[count - 1]->Show(hdc);
	EndPaint(hWnd, &ps);

}