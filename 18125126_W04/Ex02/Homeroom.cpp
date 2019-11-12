#include "Homeroom.h"

HomeroomTeacher::HomeroomTeacher()
{
	Teacher::Teacher();
	ofClass = "";
}

HomeroomTeacher::HomeroomTeacher(string temp)
{
	Teacher::Teacher();
	ofClass = temp;
}

HomeroomTeacher::HomeroomTeacher(int x, int y)
{
	if (x > y)
	{
		this->daysOff = x;
	}
	else
	{
		this->daysOff = y;
	}
}

HomeroomTeacher::HomeroomTeacher(int pRate1, int pRate2, int pRate3)
{
	if (pRate1 < pRate2 && pRate2 > pRate3)
	{
		this->payRate = pRate2;
	}
	else
	{
		this->payRate = abs(pRate1 - pRate3);
	}
}

HomeroomTeacher::HomeroomTeacher(const HomeroomTeacher& cpy)
{
	this->ID = cpy.ID;
	this->name = cpy.name;
	this->basicPay = cpy.basicPay;
	this->payRate = cpy.payRate;
	this->daysOff = cpy.daysOff;
	this->ofClass = cpy.ofClass;
}

int HomeroomTeacher::salary() const
{
	int res = Teacher::salary();
	return res + 500000;
}

ostream& operator<<(ostream& os, const HomeroomTeacher& output)
{
	os << "-------------------------HOMEROOM TEACHER-------------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Class: " << output.ofClass << endl;
	os << "Pay Rate: " << output.payRate << endl;
	os << "Basic Pay " << output.basicPay << endl;
	os << "Number of days off: " << output.daysOff << endl;
	os << "Salary: " << output.salary() << endl;
	return os;
}

istream& operator>>(istream& is, HomeroomTeacher& input)
{
	cout << "-------------------------HOMEROOM TEACHER-------------------------\n";
	cout << "Enter ID: ";
	getline(is, input.ID);
	cout << "Enter name: ";
	getline(is, input.name);
	cout << "Enter class: ";
	getline(is, input.ofClass);
	cout << "Enter pay rate: ";
	is >> input.payRate;
	cout << "Enter basic pay: ";
	is >> input.basicPay;
	cout << "Enter number of days off: ";
	is >> input.daysOff;
	is.ignore();
	return is;
}