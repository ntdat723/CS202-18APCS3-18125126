#include "triangle.h"

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

float Point::pDistance(Point destination)
{
	return sqrt(pow((destination.getX() - this->getX()), 2) + pow((destination.getY() - this->getY()), 2));
}

bool Point::ifConcur(Point input)
{
	if (this->getX() == input.getX() && this->getY() == input.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------------

void Triangle::setFirst(Point input)
{
	first.setX(input.getX());
	first.setY(input.getY());
}

void Triangle::setSecond(Point input)
{
	second.setX(input.getX());
	second.setY(input.getY());
}

void Triangle::setThird(Point input)
{
	third.setX(input.getX());
	third.setY(input.getY());
}

bool Triangle::validTriangle()
{
	if (first.ifConcur(second) == 1 || second.ifConcur(third) == 1 || third.ifConcur(first) == 1)
	{
		return false;
	}

	float firstDistance = first.pDistance(second);
	float secondDistance = second.pDistance(third);
	float thirdDistance = third.pDistance(first);

	if (((firstDistance + secondDistance) < thirdDistance) || ((firstDistance + thirdDistance) < secondDistance) || ((secondDistance + thirdDistance) < firstDistance))
	{
		return false;
	}
	else
	{
		return true;
	}
}


int Triangle::typeOf()
{
	float firstDistance = first.pDistance(second);
	float secondDistance = second.pDistance(third);
	float thirdDistance = third.pDistance(first);

	if (firstDistance == secondDistance && secondDistance == thirdDistance)
	{
		return 0;
	}
	else if (firstDistance == secondDistance && pow(thirdDistance, 2) == pow(firstDistance, 2) + pow(secondDistance, 2)
		|| firstDistance == thirdDistance && pow(secondDistance, 2) == pow(firstDistance, 2) + pow(thirdDistance, 2)
		|| secondDistance == thirdDistance && pow(firstDistance, 2) == pow(secondDistance, 2) + pow(thirdDistance, 2))
	{
		return 1;
	}
	else if (firstDistance == secondDistance || firstDistance == thirdDistance || secondDistance == thirdDistance)
	{
		return 2;
	}
	else if (pow(thirdDistance, 2) == pow(firstDistance, 2) + pow(secondDistance, 2)
		|| pow(secondDistance, 2) == pow(firstDistance, 2) + pow(thirdDistance, 2)
		|| pow(firstDistance, 2) == pow(secondDistance, 2) + pow(thirdDistance, 2))
	{
		return 3;
	}
	else if (pow(firstDistance, 2) + pow(secondDistance, 2) > pow(thirdDistance, 2)
		|| pow(secondDistance, 2) + pow(thirdDistance, 2) > pow(firstDistance, 2)
		|| pow(firstDistance, 2) + pow(thirdDistance, 2) > pow(secondDistance, 2))
	{
		return 4;
	}
	else if (pow(firstDistance, 2) + pow(secondDistance, 2) < pow(thirdDistance, 2)
		|| pow(secondDistance, 2) + pow(thirdDistance, 2) < pow(firstDistance, 2)
		|| pow(firstDistance, 2) + pow(thirdDistance, 2) < pow(secondDistance, 2))
	{
		return 5;
	}
	else
	{
		return 6;
	}
}

