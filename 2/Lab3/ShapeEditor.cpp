#include "stdafx.h"
#include "ShapeEditor.h"

Shape *ShapeEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int ShapeEditor::count = 0;

ShapeEditor::ShapeEditor()
{
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
}

void ShapeEditor::OnLBup(HWND hWnd)
{
}
void ShapeEditor::OnMouseMove(HWND hWnd)
{
}


void ShapeEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i<MY_SHAPE_ARRAY_SIZE; i++)
	if (pcshape[i])
		pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}