#include "Teacher.h"

Teacher::Teacher()
{
	ID = "";
	name = "";
	payRate = 0;
	basicPay = 0;
	daysOff = 0;
}

Teacher::Teacher(const Teacher& cpy)
{
	this->ID = cpy.ID;
	this->name = cpy.name;
	this->basicPay = cpy.basicPay;
	this->payRate = cpy.payRate;
	this->daysOff = cpy.daysOff;
}

Teacher::Teacher(int bPay, int pRate, int dOff)
{
	this->ID = "";
	this->name = "";
	this->basicPay = bPay;
	this->payRate = pRate;
	this->daysOff = dOff;
}

Teacher::Teacher(string tempID, string tempName)
{
	this->ID = tempID;
	this->name = tempName;
	this->payRate = 0;
	this->basicPay = 0;
	this->daysOff = 0;
}

Teacher::Teacher(string tempID, string tempName, int pRate, int bPay, int dOff)
{
	this->ID = tempID;
	this->name = tempName;
	this->basicPay = bPay;
	this->payRate = pRate;
	this->daysOff = dOff;
}

int Teacher::salary() const
{
	int res = payRate * basicPay - daysOff * 100000;;
	return (res < 0) ? 0 : res;
}

ostream& operator<<(ostream& os, const Teacher& output)
{
	os << "-------------------------TEACHER-------------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Pay Rate: " << output.payRate << endl;
	os << "Basic Pay " << output.basicPay << endl;
	os << "Number of days off: " << output.daysOff << endl;
	os << "Salary: " << output.salary() << endl;
	return os;
}

istream& operator>>(istream& is, Teacher& input)
{
	cout << "-------------------------TEACHER-------------------------\n";
	cout << "Enter ID: ";
	getline(is, input.ID);
	cout << "Enter name: ";
	getline(is, input.name);
	cout << "Enter pay rate: ";
	is >> input.payRate;
	cout << "Enter basic pay: ";
	is >> input.basicPay;
	cout << "Enter number of days off: ";
	is >> input.daysOff;
	is.ignore();
	return is;
}
