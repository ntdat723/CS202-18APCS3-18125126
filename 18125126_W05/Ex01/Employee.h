#pragma once
#ifndef _Employee_
#define _Employee_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <iomanip>
using namespace std;

class Date
{
public:
	int day, month, year;
	Date() : day(1), month(1), year(1900) {}
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
	friend istream& operator>>(istream& is, Date& in);
	friend ostream& operator<<(ostream& os, const Date& out);
};

class Employee
{
private:
	int ID;
	string fullName, address;
	Date DoB;
public:
	Employee();
	Employee(int tempID, string tempName, string tempAddress);
	Employee(int tempID);
	Employee(string tempName, string tempAddress);
	Employee(Date tempDoB);
	virtual void input();
	virtual void display();
	virtual double salary();

	int getID();
	string getName();
	int getMonth();
};

#endif // !_Employee_
