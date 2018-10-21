#pragma once
#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void ChangeX(Point &value)
{
	value.x = -1;
}