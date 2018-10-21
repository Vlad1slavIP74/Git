#include "stdafx.h"
#include "LineEditor.h"
#include "LineShape.h"

void LineEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt_start);
	ScreenToClient(hWnd, &pt_start); //
//Функція ScreenToClient перетворює координати екрана вказаної точки на екрані в координати області клієнта.
	pt_old = pt_start;
	isDown = true;
}

void LineEditor::OnLBup(HWND hWnd)
{
	isDown = false;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[count] = new LineShape();
	pcshape[count]->Set(pt_start.x, pt_start.y, pt.x, pt.y);
	count++;
}

void LineEditor::OnMouseMove(HWND hWnd)
{
	if (isDown)
	{
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc;
		COLORREF color = RGB(255,255,255) ;
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_DOT, 1, color); // створення лінії
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
		LineTo(hdc, pt_old.x, pt_old.y);
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pt_old = pt;
		MoveToEx(hdc, pt_start.x, pt_start.y, NULL);
		LineTo(hdc, pt.x, pt.y); 
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);

	}
}

void LineEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	pcshape[count -1 ]->Show(hdc);
	EndPaint(hWnd, &ps);
}