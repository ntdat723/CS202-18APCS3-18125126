#include "fraction.h"

fraction fraction::operator+(const fraction& x)
{
	fraction res;
	res.numerator = numerator * x.denominator + x.numerator * denominator;
	res.denominator = denominator * x.denominator;
	res.normalize();
	return res;
}

fraction fraction::operator-(const fraction& x)
{
	fraction res;
	res.numerator = numerator * x.denominator - x.numerator * denominator;
	res.denominator = denominator * x.denominator;
	res.normalize();
	return res;
}

fraction fraction::operator*(const fraction& x)
{
	fraction res;
	res.numerator = numerator * x.numerator;
	res.denominator = denominator * x.denominator;
	res.normalize();
	return res;
}

fraction fraction::operator/(const fraction& x)
{
	if (x.numerator == 0)
	{
		throw 0;
	}
	fraction res;
	res.numerator = numerator * x.denominator;
	res.denominator = denominator * x.numerator;
	float val = (1.0 * x.numerator) / (1.0 * x.denominator);
	res.normalize();
	return res;
}

bool fraction::operator==(const fraction& x)
{
	float val1 = (1.0 * x.numerator) / (1.0 * x.denominator);
	float val2 = (1.0 * numerator) / (1.0 * denominator);
	return (val1 == val2) ? true : false;
}

bool fraction::operator!=(const fraction& x)
{
	float val1 = (1.0 * x.numerator) / (1.0 * x.denominator);
	float val2 = (1.0 * numerator) / (1.0 * denominator);
	return (val1 != val2) ? true : false;
}

bool fraction::operator<=(const fraction& x)
{
	float val2 = (1.0 * x.numerator) / (1.0 * x.denominator);
	float val1 = (1.0 * numerator) / (1.0 * denominator);
	return (val1 <= val2) ? true : false;
}

bool fraction::operator>=(const fraction& x)
{
	float val2 = (1.0 * x.numerator) / (1.0 * x.denominator);
	float val1 = (1.0 * numerator) / (1.0 * denominator);
	return (val1 >= val2) ? true : false;
}

//fraction fraction::operator=(const fraction &x)
//{
//	fraction res;
//	res.numerator = x.numerator;
//	res.denominator = x.denominator;
//	return res;
//}

bool fraction::operator<(const fraction& x)
{
	float val2 = (1.0 * x.numerator) / (1.0 * x.denominator);
	float val1 = (1.0 * numerator) / (1.0 * denominator);
	return (val1 < val2) ? true : false;
}

bool fraction::operator>(const fraction& x)
{
	float val2 = (1.0 * x.numerator) / (1.0 * x.denominator);
	float val1 = (1.0 * numerator) / (1.0 * denominator);
	return (val1 > val2) ? true : false;
}

fraction fraction::operator+(const int& k)
{
	fraction res;
	res.numerator = numerator + denominator * k;
	res.denominator = denominator;
	res.normalize();
	return res;
}

fraction operator+(const int& k, const fraction& x)
{
	fraction res;
	res.numerator = x.numerator + k * x.denominator;
	res.denominator = x.denominator;
	res.normalize();
	return res;
}

fraction fraction::operator-(const int& k)
{
	fraction res;
	res.numerator = numerator - denominator * k;
	res.denominator = denominator;
	res.normalize();
	return res;
}

fraction operator-(const int& k, const fraction& x)
{
	fraction res;
	res.numerator = x.numerator - k * x.denominator;
	res.denominator = x.denominator;
	res.normalize();
	return res;
}

fraction fraction::operator*(const int& k)
{
	fraction res;
	res.numerator = numerator * k;
	res.denominator = denominator;
	res.normalize();
	return res;
}

fraction operator*(const int& k, const fraction& x)
{
	fraction res;
	res.numerator = x.numerator * k;
	res.denominator = x.denominator;
	res.normalize();
	return res;
}

fraction fraction::operator/(const int& k)
{
	if (k == 0)
	{
		throw 0;
	}
	fraction res;
	res.numerator = numerator;
	res.denominator = denominator * k;
	res.normalize();
	return res;
}

fraction operator/(const int& k, const fraction& x)
{
	fraction res;
	res.numerator = x.numerator;
	res.denominator = x.denominator * k;
	res.normalize();
	return res;
}

ostream& operator<<(ostream& os, const fraction& input)
{
	os << input.numerator << "/" << input.denominator;
	return os;
}

istream& operator>>(istream& is, fraction& input)
{
	is >> input.numerator >> input.denominator;
	return is;
}

fraction& fraction::operator+=(const fraction& input)
{
	this->numerator = this->numerator * input.denominator + input.numerator * this->denominator;
	this->denominator *= input.denominator;
	this->normalize();
	return *this;
}

fraction& fraction::operator-=(const fraction& input)
{
	this->numerator = this->numerator * input.denominator - input.numerator * this->denominator;
	this->denominator *= input.denominator;
	this->normalize();
	return *this;
}

fraction& fraction::operator*=(const fraction& input)
{
	this->numerator *= input.numerator;
	this->denominator *= input.denominator;
	this->normalize();
	return *this;
}

fraction& fraction::operator/=(const fraction& input)
{
	if (input.numerator == 0)
	{
		throw 0;
	}
	this->numerator *= input.denominator;
	this->denominator *= input.numerator;
	this->normalize();
	return *this;
}

fraction& fraction::operator++()
{
	this->numerator += this->denominator;
	this->normalize();
	return *this;
}

fraction fraction::operator++(int one)
{
	fraction res(*this);
	++* this;
	this->normalize();
	return res;
}

fraction& fraction::operator--()
{
	this->numerator -= this->denominator;
	this->normalize();
	return *this;
}

fraction fraction::operator--(int one)
{
	fraction res(*this);
	--* this;
	this->normalize();
	return res;
}

fraction::operator float()
{
	float res = (1.0 * numerator) / (1.0 * denominator);
	return res;
}

void fraction::normalize()
{
	if (numerator < 0 && denominator < 0)
	{
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
	else if (denominator < 0)
	{
		denominator = abs(denominator);
		numerator *= -1;
	}
}