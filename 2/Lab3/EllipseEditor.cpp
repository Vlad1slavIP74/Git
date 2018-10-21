#include "stdafx.h"
#include "EllipseEditor.h"
#include "EllipseShape.h"


void EllipseEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt_start);
	ScreenToClient(hWnd, &pt_start);
	pt_old = pt_start;
	isDown = true;
}

void EllipseEditor::OnLBup(HWND hWnd)
{
	pcshape[count] = new EllipseShape();
	isDown = false;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[count]->Set(pt_start.x, pt_start.y, pt.x, pt.y);
	count++;
}

void EllipseEditor::OnMouseMove(HWND hWnd)
{
	if (isDown)
	{
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc;
		COLORREF color = RGB(0,0,225) ;
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(0, 1, color);
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		Arc(hdc, pt_start.x - (pt_old.x - pt_start.x), pt_start.y - (pt_old.y - pt_start.y), pt_old.x, pt_old.y, 0, 0, 0, 0);
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pt_old = pt;
		Arc(hdc, pt_start.x - (pt_old.x - pt_start.x), pt_start.y - (pt_old.y - pt_start.y), pt.x, pt.y, 0, 0, 0, 0);
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);

	}
}

void EllipseEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	pcshape[count - 1]->Show(hdc);
	EndPaint(hWnd, &ps);
}