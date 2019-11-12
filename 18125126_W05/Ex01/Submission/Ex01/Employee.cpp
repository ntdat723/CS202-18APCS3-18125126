#include "Employee.h"

Employee::Employee()
{
	ID = 0;
	fullName = "";
	address = "";
}

void Employee::input()
{
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
}

double Employee::salary()
{
	return 0;
}

void Employee::display()
{
	cout << "ID: " << ID << endl;
	cout << "Full Name: " << fullName << endl;
	cout << "Address: " << address << endl;
	cout << "Salary: " << salary() << endl;
}