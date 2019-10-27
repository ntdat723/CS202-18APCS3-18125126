#pragma once
#ifndef _triangle_
#define _triangle_

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

class Point
{
private:
	float x, y;
public:
	Point();

	void setX(float input);
	void setY(float input);

	float getX();
	float getY();

	float pDistance(Point destination);
	bool ifConcur(Point input);
};

class Triangle : public Point
{
private:
	Point first, second, third;
public:
	void setFirst(Point input);
	void setSecond(Point input);
	void setThird(Point input);
	bool validTriangle();
	int typeOf();
};

#endif // !_triangle_
