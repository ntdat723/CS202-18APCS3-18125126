#pragma once
#ifndef _date_
#define _date_

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Date
{
private:
	int day, month, year;

	bool validateYear(int input);
	bool validateMonth(int input);
	bool validateDay(int input);
	bool isLeapYear(int input);
public:
	Date();

	void setDay(int input);
	int getDay();

	void setMonth(int input);
	int getMonth();

	void setYear(int input);
	int getYear();

	bool validate(Date input);
	Date previous();
	Date following();
	void display();
};

#endif // !_date_
