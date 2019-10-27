#include "arrayOfFractions.h"

void arrayOfFractions::load(const char* path)
{
	ifstream input;
	input.open(path);
	fraction addition;
	int num;
	int x, y;
	input >> num;
	for (int i = 0; i < num; ++i)
	{
		input >> x >> y;
		addition.setFraction(x, y);
		this->ar.push_back(addition);
	}
	input.close();
}

fraction arrayOfFractions::maximum()
{
	fraction max = ar.at(0);
	for (int i = 1; i < ar.size(); ++i)
	{
		if (max.compare(ar.at(i)) == 0)
		{
			max = ar.at(i);
		}
	}
	return max;
}

fraction arrayOfFractions::minimum()
{
	fraction min = ar.at(0);
	for (int i = 1; i < ar.size(); ++i)
	{
		if (min.compare(ar.at(i)) == 1)
		{
			min = ar.at(i);
		}
	}
	return min;
}

fraction arrayOfFractions::sum()
{
	fraction res = ar.at(0);
	for (int i = 1; i < ar.size(); ++i)
	{
		res = res.add(ar.at(i));
	}
	res.reduce();
	return res;
}

void arrayOfFractions::sort()
{
	for (int i = 0; i < ar.size() - 1; ++i)
	{
		for (int j = i + 1; j < ar.size(); ++j)
		{
			if (ar.at(i).compare(ar.at(j)) == 1)
			{
				swap(ar.at(i), ar.at(j));
			}
		}
	}
}

void arrayOfFractions::swap(fraction& first, fraction& second)
{
	fraction temp = first;
	first = second;
	second = temp;
}

void arrayOfFractions::save(const char* path)
{
	ofstream output;
	output.open(path);
	for (int i = 0; i < ar.size(); ++i)
	{
		output << ar.at(i).getNumerator() << "/" << ar.at(i).getDenominator() << '\n';
	}
	output.close();
}

void arrayOfFractions::display()
{
	for (int i = 0; i < ar.size(); ++i)
	{
		cout << ar.at(i).getNumerator() << "/" << ar.at(i).getDenominator() << "  ";
	}
}