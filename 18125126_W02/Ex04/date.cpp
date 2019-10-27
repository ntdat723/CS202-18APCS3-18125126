#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}

bool Date::validateDay(int input)
{
	if (input <= 0 || input > 31)
	{
		return false;
	}
	int addition = this->getMonth();
	if (addition == 1 || addition == 3 || addition == 5 || addition == 7 || addition == 8 || addition == 10 || addition == 12)
	{
		if (input <= 31)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (addition == 4 || addition == 6 || addition == 9 || addition == 11)
	{
		if (input <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (isLeapYear(this->year) == true && addition == 2)
	{
		if (input <= 29)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (input <= 28)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Date::validateMonth(int input)
{
	if (input <= 0 || input > 12)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Date::validateYear(int input)
{
	if (input < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Date::isLeapYear(int input)
{
	if ((input % 4 == 0 && input % 100 != 0) || input % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::validate(Date input)
{
	if (validateDay(input.day) == true && validateMonth(input.month) == true && validateYear(input.year) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Date::setDay(int input)
{
	day = input;
}
int Date::getDay()
{
	return day;
}
void Date::setMonth(int input)
{
	month = input;
}
int Date::getMonth()
{
	return month;
}
void Date::setYear(int input)
{
	year = input;
}
int Date::getYear()
{
	return year;
}

Date Date::previous()
{
	Date cpy;
	cpy.setDay(this->day);
	cpy.setMonth(this->month);
	cpy.setYear(this->year);
	if (month == 1 && day == 1)
	{
		cpy.day = 31;
		cpy.month = 12;
		--cpy.year;
	}
	else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && day == 1)
	{
		--cpy.month;
		cpy.day = 31;
	}
	else if ((month == 5 || month == 7 || month == 10 || month == 12) && day == 1)
	{
		--cpy.month;
		cpy.day = 30;
	}
	else if (month == 3 && isLeapYear(year) == true && day == 1)
	{
		--cpy.month;
		cpy.day = 29;
	}
	else if (month == 3 && isLeapYear(year) == false && day == 1)
	{
		--cpy.month;
		cpy.day = 28;
	}
	else
	{
		--cpy.day;
	}
	return cpy;
}

Date Date::following()
{
	Date cpy;
	cpy.setDay(this->day);
	cpy.setMonth(this->month);
	cpy.setYear(this->year);
	if (month == 12 && day == 31)
	{
		cpy.day = 1;
		cpy.month = 1;
		++cpy.year;
	}
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31)
	{
		++cpy.month;
		cpy.day = 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
	{
		++cpy.month;
		cpy.day = 1;
	}
	else if (month == 2 && isLeapYear(year) == true && day == 29)
	{
		++cpy.month;
		cpy.day = 1;
	}
	else if (month == 2 && isLeapYear(year) == false && day == 28)
	{
		++cpy.month;
		cpy.day = 1;
	}
	else
	{
		++cpy.day;
	}
	return cpy;
}

void Date::display()
{
	cout << day << "/" << month << "/" << year << ".";
}