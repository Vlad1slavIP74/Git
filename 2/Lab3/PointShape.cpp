#include "stdafx.h"
#include "PointShape.h"

void PointShape::Show(HDC hdc)
{
	SetPixel(hdc, xs1, ys1, RGB(0, 0, 0));
}