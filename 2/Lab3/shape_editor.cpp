#include "stdafx.h"
#include "shape_editor.h"

ShapeObjectsEditor::~ShapeObjectsEditor()
{
	if (pse)
		delete pse;
}

void ShapeObjectsEditor::StartPointEditor()
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		delete pse;
	pse = new PointEditor;
}

void ShapeObjectsEditor::StartLineEditor(HWND hWnd)
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		delete pse;
	pse = new LineEditor();
	SetWindowText(hWnd, (LPCSTR)"Ë³í³ÿ");
}
void ShapeObjectsEditor::StartRectEditor(HWND hWnd)
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		delete pse;
	pse = new RectEditor();
	SetWindowText(hWnd, "Rect");
}

void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd)
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		delete pse;
	pse = new EllipseEditor();
	SetWindowText(hWnd, "Ellipse");
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd)
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd)
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		pse->OnLBup(hWnd);
	InvalidateRect(hWnd, 0, TRUE);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd)
{
	if (pse && shapeEditor->count<MY_SHAPE_ARRAY_SIZE)
		pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd)
{
	shapeEditor->OnPaint(hWnd);
}



/*
void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	if (pse && pse->count < MY_SHAPE_ARRAY_SIZE)
	{
		pse->OnInitMenuPopup(hWnd, wParam);
	}
}
*/