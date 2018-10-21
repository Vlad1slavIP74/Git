#include "stdafx.h"
#include "EllipseShape.h"

void EllipseShape::Show(HDC hdc)
{
	COLORREF colorfill = RGB(0, 255, 255);
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(colorfill);	
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);	
	Ellipse(hdc, xs1, ys1, xs2, ys2);
	SelectObject(hdc, hBrushOld);					
	DeleteObject(hBrush);	
}