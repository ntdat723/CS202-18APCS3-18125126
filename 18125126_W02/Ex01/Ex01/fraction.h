#pragma once
#ifndef _fraction_
#define _fraction_

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

class fraction
{
private:
	int numerator, denominator;

	int GCD(int first, int second);
public:
	fraction();
	void setFraction(int x, int y);
	int getNumerator();
	int getDenominator();
	void getFraction();
	fraction add(fraction added);
	int compare(fraction getCompared);
	void reduce();
};

#endif // !_fraction_
