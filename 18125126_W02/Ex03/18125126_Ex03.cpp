#include "triangle.h"
#include "loadOfTriangles.h"

int main()
{
	LoadOfTriangles ex;
	ex.load("ex03.txt");

	cout << "Total triangles in the array at first: " << ex.firstNum() << endl;
	cout << "Number of invalid triangles in the array: " << ex.eliminate() << endl;
	cout << "Remaining triangles in the array: " << ex.firstNum() - ex.eliminate() << endl;

	cout << "Number of equilateral triangles in the array: " << ex.equilateral() << endl;
	cout << "Number of isosceles triangles in the array: " << ex.isosceles() << endl;
	cout << "Number of right isosceles triangles in the array: " << ex.rIsosceles() << endl;
	cout << "Number of right triangles in the array: " << ex.rightTriangles() << endl;
	cout << "Number of acute triangles in the array: " << ex.acute() << endl;
	cout << "Number of obtuse triangles in the array: " << ex.obtuse() << endl;

	return 0;
}