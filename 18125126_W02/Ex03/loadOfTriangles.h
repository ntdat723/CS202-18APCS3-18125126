#pragma once
#ifndef _loadOfTriangles_
#define _loadOfTriangles_

#include "triangle.h"
#include <vector>

class LoadOfTriangles
{
private:
	vector<Triangle> ar;
public:
	void load(const char* path);
	int eliminate();
	int firstNum();
	int equilateral();
	int rIsosceles();
	int isosceles();
	int rightTriangles();
	int acute();
	int obtuse();
};

#endif // !_loadOfTriangles_
