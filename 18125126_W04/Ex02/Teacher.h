#pragma once
#ifndef _Teacher_
#define _Teacher_

#include <iostream>
#include <string>
using namespace std;

class Teacher
{
protected:
	string ID, name;
	int payRate, basicPay, daysOff;
public:
	Teacher();
	Teacher(string tempID, string tempName);
	Teacher(int pRate, int bPay, int dOff);
	Teacher(string tempID, string tempName, int pRate, int bPay, int dOff);
	Teacher(const Teacher& cpy);
	virtual int salary() const;
	friend ostream& operator<<(ostream& os, const Teacher& output);
	friend istream& operator>>(istream& is, Teacher& input);
};

#endif // !_Teacher_
