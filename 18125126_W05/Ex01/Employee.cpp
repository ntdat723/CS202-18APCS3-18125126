#include "Employee.h"

Employee::Employee()
{
	ID = 0;
	fullName = "N/A";
	address = "N/A";
	DoB.day = 1;
	DoB.month = 1;
	DoB.year = 1900;
}

Employee::Employee(int tempID, string tempName, string tempAddress)
{
	ID = tempID;
	fullName = tempName;
	address = tempAddress;
}

Employee::Employee(int tempID) :Employee()
{
	ID = tempID;
}

Employee::Employee(string tempName, string tempAddress) : Employee()
{
	fullName = tempName;
	address = tempAddress;
}

Employee::Employee(Date tempDoB) :Employee()
{
	DoB.day = tempDoB.day;
	DoB.month = tempDoB.month;
	DoB.year = tempDoB.year;
}

void Employee::input()
{
	cout << "------------------------------------------\n";
	do
	{
		cout << "Enter ID: ";
		cin >> ID;
	} while (ID < 0);
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, fullName);
	cout << "Enter address: ";
	getline(cin, address);
	cout << "Enter date of birth (day, month, year - respectively): ";
	cin >> DoB;
}

double Employee::salary()
{
	return 0;
}

void Employee::display()
{
	cout << "------------------------------------------\n";
	cout << "ID: " << ID << endl;
	cout << "Full Name: " << fullName << endl;
	cout << "Date of Birth: " << DoB << endl;
	cout << "Address: " << address << endl;
	cout << "Salary: " << fixed << setprecision(0) << salary() << endl;
}

int Employee::getID()
{
	return ID;
}

string Employee::getName()
{
	return fullName;
}

int Employee::getMonth()
{
	return DoB.month;
}
///////////////////////////////////////////////////////////////////////////////
istream& operator>>(istream& is, Date& in)
{
	is >> in.day >> in.month >> in.year;
	return is;
}

ostream& operator<<(ostream& os, const Date& out)
{
	os << out.day << "/" << out.month << "/" << out.year;
	return os;
}
