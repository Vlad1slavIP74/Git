#include "stdafx.h"
#include "PointEditor.h"
#include "PointShape.h"

void PointEditor::OnLBdown(HWND hWnd)
{

}

void PointEditor::OnLBup(HWND hWnd)
{
	pcshape[count] = new PointShape();
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[count]->Set(pt.x, pt.y, 0, 0);
	count++;
}


void PointEditor::OnMouseMove(HWND hWnd)
{

}

void PointEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	pcshape[count-1]->Show(hdc);
	EndPaint(hWnd, &ps);
}