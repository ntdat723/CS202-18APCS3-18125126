#pragma once
#ifndef _Employee_
#define _Employee_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class Employee
{
private:
	int ID;
	string fullName, address;
public:
	Employee();
	virtual void input();
	virtual void display();
	virtual double salary();
};

#endif // !_Employee_
