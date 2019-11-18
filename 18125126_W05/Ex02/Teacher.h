#pragma once
#ifndef _Teacher_
#define _Teacher_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class Teacher
{
protected:
	string ID;
	string name;
	int payRate;
	int basicPay;
	int daysOff;
public:
	Teacher();
	Teacher(const Teacher& cpy);
	Teacher(string tempID, string tempName);
	Teacher(int tempPayRate, int tempBasicPay, int tempDaysOff);
	Teacher(int tempDaysOff);
	virtual void input();
	virtual void display();
	virtual int salary();
	string getID();
	string getName();
	int getDaysOff();
};

#endif // !_Teacher_
