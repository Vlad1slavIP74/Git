#include "stdafx.h"
#include "RectShape.h"

void RectShape::Show(HDC hdc)
{
	COLORREF colorfill = RGB(255,255,255);
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(colorfill);	
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);	
	//Rectangle(hdc, xs1, ys1, xs2, ys2);
	Rectangle(hdc, xs1 - (xs2 - xs1), ys1 - (ys2 - ys1), xs2, ys2);
	SelectObject(hdc, hBrushOld);					
	DeleteObject(hBrush);							
}