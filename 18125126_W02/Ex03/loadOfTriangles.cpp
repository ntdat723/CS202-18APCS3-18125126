#include "loadOfTriangles.h"

void LoadOfTriangles::load(const char* path)
{
	ifstream input;
	input.open(path);
	int num;
	input >> num;

	for (int i = 0; i < num; ++i)
	{
		Triangle temp;
		Point tmp;
		float a, b;

		input >> a >> b;
		tmp.setX(a);
		tmp.setY(b);
		temp.setFirst(tmp);

		input >> a >> b;
		tmp.setX(a);
		tmp.setY(b);
		temp.setSecond(tmp);

		input >> a >> b;
		tmp.setX(a);
		tmp.setY(b);
		temp.setThird(tmp);

		ar.push_back(temp);
	}
	input.close();
}

int LoadOfTriangles::eliminate()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).validTriangle() == false)
		{
			ar.erase(ar.begin() + i);
			--i;
			++count;
		}
	}
	return count;
}

int LoadOfTriangles::firstNum()
{
	return ar.size();
}

int LoadOfTriangles::equilateral()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).typeOf() == 0)
		{
			++count;
		}
	}
	return count;
}

int LoadOfTriangles::rIsosceles()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).typeOf() == 1)
		{
			++count;
		}
	}
	return count;
}

int LoadOfTriangles::isosceles()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).typeOf() == 2)
		{
			++count;
		}
	}
	return count;
}

int LoadOfTriangles::rightTriangles()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).typeOf() == 3)
		{
			++count;
		}
	}
	return count;
}

int LoadOfTriangles::acute()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).typeOf() == 4)
		{
			++count;
		}
	}
	return count;
}

int LoadOfTriangles::obtuse()
{
	int count = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		if (ar.at(i).typeOf() == 5)
		{
			++count;
		}
	}
	return count;
}