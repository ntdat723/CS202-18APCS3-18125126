#include "point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

void Point::setX(float input)
{
	x = input;
}

void Point::setY(float input)
{
	y = input;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

int Point::isLarger(float currentDistance, float anotherDistance)
{
	return (currentDistance > anotherDistance) ? 1 : 0;
}

float Point::calculateDistance(Point destination)
{
	return sqrt(pow((destination.getX() - this->getX()), 2) + pow((destination.getY() - this->getY()), 2));
}