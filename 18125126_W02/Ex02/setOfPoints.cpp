#include "setOfPoints.h"

void SetOfPoints::load(const char* path)
{
	ifstream input;
	input.open(path);
	int num;
	input >> num;

	for (int i = 0; i < num; ++i)
	{
		Point added;
		float temp;

		input >> temp;
		added.setX(temp);

		input >> temp;
		added.setY(temp);

		ar.push_back(added);
	}
	input.close();
}

Point SetOfPoints::farthestDestination(Point start)
{
	Point farthestPoint = ar.at(0);
	float farthest = farthestPoint.calculateDistance(start);
	for (int i = 0; i < ar.size(); ++i)
	{
		float getCompared = ar.at(i).calculateDistance(start);
		if (farthestPoint.isLarger(farthest, getCompared) == 0)
		{
			farthest = getCompared;
			farthestPoint = ar.at(i);
		}
	}
	return farthestPoint;
}

void SetOfPoints::display()
{
	for (int i = 0; i < ar.size(); ++i)
	{
		if (i != ar.size() - 1)
		{
			cout << "(" << ar.at(i).getX() << ", " << ar.at(i).getY() << ");  ";
		}
		else
		{
			cout << "(" << ar.at(i).getX() << ", " << ar.at(i).getY() << ").";
		}
	}
}