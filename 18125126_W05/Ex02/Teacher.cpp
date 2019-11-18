#include "Teacher.h"

Teacher::Teacher()
{
	ID = "N/A";
	name = "N/A";
	payRate = 0;
	basicPay = 0;
	daysOff = 0;
}

Teacher::Teacher(const Teacher& cpy)
{
	ID = cpy.ID;
	name = cpy.name;
	payRate = cpy.payRate;
	basicPay = cpy.basicPay;
	daysOff = cpy.daysOff;
}

Teacher::Teacher(string tempID, string tempName) : Teacher()
{
	ID = tempID;
	name = tempName;
}

Teacher::Teacher(int tempPayRate, int tempBasicPay, int tempDaysOff) : Teacher()
{
	payRate = tempPayRate;
	basicPay = tempBasicPay;
	daysOff = tempDaysOff;
}

Teacher::Teacher(int tempDaysOff) : Teacher()
{
	daysOff = tempDaysOff;
}

void Teacher::input()
{
	cin.ignore();
	cout << "Enter ID: ";
	getline(cin, ID);
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter pay rate: ";
	cin >> payRate;
	cout << "Enter basic pay: ";
	cin >> basicPay;
	cout << "Enter number of days off: ";
	cin >> daysOff;
	cin.ignore();
}

void Teacher::display()
{
	cout << "--------------------------------------------------\n";
	cout << "ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Pay rate: " << payRate << endl;
	cout << "Basic pay: " << basicPay << endl;
	cout << "Number of days off: " << daysOff << endl;
	cout << "Salary: " << salary() << endl;
}

int Teacher::salary()
{
	int res = payRate * basicPay - daysOff * 100000;
	return (res < 0) ? 0 : res;
}

string Teacher::getID()
{
	return ID;
}

string Teacher::getName()
{
	return name;
}

int Teacher::getDaysOff()
{
	return daysOff;
}