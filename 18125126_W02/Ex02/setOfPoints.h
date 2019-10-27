#pragma once
#ifndef _setOfPoints_
#define _setOfPoints_

#include "point.h"
#include <vector>

class SetOfPoints
{
private:
	vector<Point> ar;
public:
	void load(const char* path);
	Point farthestDestination(Point start);
	void display();
};

#endif // !_setOfPoints_
