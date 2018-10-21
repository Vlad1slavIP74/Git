#pragma once


class Point {
private:
	int x;
	int y;

public:
	Point();
	int getX();
	int getY();

	friend void ChangeX(Point &value);
};