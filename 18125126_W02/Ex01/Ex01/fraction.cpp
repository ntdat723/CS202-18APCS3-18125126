#include "fraction.h"

fraction::fraction()
{
	numerator = 0;
	denominator = 1;
}

void fraction::setFraction(int x, int y)
{
	numerator = x;
	while (y == 0)
	{
		cout << "Invalid value of denominator (must not be 0). Re-enter: ";
		cin >> y;
	}
	denominator = y;
}

void fraction::getFraction()
{
	cout << numerator << "/" << denominator;
}

int fraction::GCD(int first, int second)
{
	int chosen = (first < second) ? first : second;
	int max = 1;
	for (int i = 1; i <= chosen; ++i)
	{
		if (first % i == 0 && second % i == 0)
		{
			max = i;
		}
	}
	return max;
}

void fraction::reduce()
{
	int divided = GCD(numerator, denominator);
	numerator /= divided;
	denominator /= divided;
}

fraction fraction::add(fraction added)
{
	fraction res;
	res.numerator = this->numerator * added.denominator + added.numerator * this->denominator;
	res.denominator = this->denominator * added.denominator;
	res.reduce();
	return res;
}

int fraction::getNumerator()
{
	return numerator;
}

int fraction::getDenominator()
{
	return denominator;
}

int fraction::compare(fraction getCompared)
{
	float first = (1.0 * this->numerator) / (1.0 * this->denominator);
	float second = (1.0 * getCompared.numerator) / (1.0 * getCompared.denominator);
	return (first > second) ? 1 : 0;
}

