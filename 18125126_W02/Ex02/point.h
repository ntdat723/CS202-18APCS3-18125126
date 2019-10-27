#pragma once
#ifndef _point_
#define _point_

#include <iostream>
#include <fstream>
#include <math.h>
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

	int isLarger(float currentDistance, float anotherDistance);
	float calculateDistance(Point destination);
};

#endif // !_point_
