#include "point.h"
#include "setOfPoints.h"

int main()
{
	Point current;
	SetOfPoints ex02;
	ex02.load("ex02.txt");

	float inputX, inputY;

	cout << "Enter x: ";
	cin >> inputX;
	current.setX(inputX);

	cout << "Enter y: ";
	cin >> inputY;
	current.setY(inputY);

	cout << "Set of points: ";
	ex02.display();
	cout << endl;

	Point res = ex02.farthestDestination(current);
	cout << "The farthest point from " << "(" << current.getX() << ", " << current.getY() << ") " << "is " << "(" << res.getX() << ", " << res.getY() << ").";

	return 0;
}