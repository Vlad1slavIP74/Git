#pragma once
#include <Windows.h>
#include "ShapeEditor.h"
#include "PointEditor.h"
#include "LineEditor.h"
#include "RectEditor.h"
#include "EllipseEditor.h"
class ShapeObjectsEditor
{
private:
	ShapeEditor *pse;
	ShapeEditor *shapeEditor;
public:
	ShapeObjectsEditor(void)
	{
		pse = NULL;
		shapeEditor = new ShapeEditor();
	}
	virtual ~ShapeObjectsEditor();
	void StartPointEditor();
	void StartLineEditor(HWND);
	void StartRectEditor(HWND);
	void StartEllipseEditor(HWND);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM); //відповідно варіанту завдання
};