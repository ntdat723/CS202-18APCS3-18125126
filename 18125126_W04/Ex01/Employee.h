#pragma once
#ifndef _company_
#define _company_

#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	int day, month, year;
	Date() : day(1), month(1), year(1900) {}
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
	Date& operator=(const Date& cpy);
	friend ostream& operator<<(ostream& os, const Date& output);
	friend istream& operator>>(istream& is, Date& input);
};

class Employee
{
protected:
	char* ID, * name, * address;
	Date DoB;
public:
	Employee();
	Employee(const char* tempID);
	Employee(const char* tempID, const char* tempName);
	Employee(const char* tempID, const char* tempName, const char* tempAddress);
	Employee(const char* tempID, const char* tempName, const char* tempAddress, const Date tempDoB);
	friend ostream& operator<<(ostream& os, const Employee& output);
	friend istream& operator>>(istream& is, Employee& input);
	~Employee();
};

#endif // !_company_
