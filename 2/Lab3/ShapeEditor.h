#include "Editor.h"
#include "Shape.h"
#define MY_SHAPE_ARRAY_SIZE 118
#pragma once



class ShapeEditor : public Editor
{
public:
	static Shape *pcshape[MY_SHAPE_ARRAY_SIZE];
	POINT pt_start;
	bool isDown;
	POINT pt_old;
	static int count;
	ShapeEditor(void);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};

