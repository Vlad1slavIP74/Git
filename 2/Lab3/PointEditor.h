#pragma once

#include "ShapeEditor.h"
#include "PointShape.h"

class PointEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};