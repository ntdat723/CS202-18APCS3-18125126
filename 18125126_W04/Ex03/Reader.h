#pragma once
#ifndef _library_
#define _library_

#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	int day, month, year;
	Date& operator=(const Date& res);
	friend istream& operator>>(istream& is, Date& input);
	friend ostream& operator<<(ostream& os, const Date& output);
};

class Reader
{
protected:
	string ID, name, gender;
	Date exp;
public:
	Reader();
	Reader(string tempID, string tempName, string tempGender);
	Reader(Date input);
	Reader(const Reader& cpy);
	Reader(string tempID);
	virtual int fee() const;
	friend ostream& operator<<(ostream& os, const Reader& output);
	friend istream& operator>>(istream& is, Reader& input);
};

#endif // !_library_
