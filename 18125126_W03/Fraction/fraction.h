#pragma once
#ifndef _fr_
#define _fr_

#include <iostream>
using namespace std;

class fraction
{
private:
	int numerator, denominator;
public:
	fraction() : numerator(0), denominator(1) {}
	fraction(int x, int y) : numerator(x), denominator(y) {}
	fraction(int d) : numerator(d), denominator(1) {}
	//
	fraction operator+(const fraction& x);
	fraction operator-(const fraction& x);
	fraction operator*(const fraction& x);
	fraction operator/(const fraction& x);
	//
	bool operator==(const fraction& x);
	bool operator!=(const fraction& x);
	bool operator<=(const fraction& x);
	bool operator>=(const fraction& x);
	bool operator>(const fraction& x);
	bool operator<(const fraction& x);
	//
	fraction operator+(const int& k);
	friend fraction operator+(const int& k, const fraction& x);
	//
	fraction operator-(const int& k);
	friend fraction operator-(const int& k, const fraction& x);
	//
	fraction operator*(const int& k);
	friend fraction operator*(const int& k, const fraction& x);
	//
	fraction operator/(const int& k);
	friend fraction operator/(const int&, const fraction& x);
	//
	friend ostream& operator<<(ostream& os, const fraction& input);
	friend istream& operator>>(istream& is, fraction& input);
	//
	fraction& operator+=(const fraction& input);
	fraction& operator-=(const fraction& input);
	fraction& operator*=(const fraction& input);
	fraction& operator/=(const fraction& input);
	//
	fraction& operator++();
	fraction operator++(int one);
	//
	fraction& operator--();
	fraction operator--(int one);
	//
	operator float();

	void normalize();
};

#endif // !_fr_
