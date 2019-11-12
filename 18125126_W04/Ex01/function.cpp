#include "Employee.h"

Employee::Employee()
{
	ID = new char[100];
	strcpy_s(ID, 100, "");
	name = new char[100];
	strcpy_s(name, 100, "");
	address = new char[100];
	strcpy_s(address, 100, "");
}

Employee::Employee(const char* tempID)
{
	ID = new char[100];
	strcpy_s(ID, 100, tempID);
	name = new char[100];
	strcpy_s(name, 100, "");
	address = new char[100];
	strcpy_s(address, 100, "");
}

Employee::Employee(const char* tempID, const char* tempName)
{
	ID = new char[100];
	strcpy_s(ID, 100, tempID);
	name = new char[100];
	strcpy_s(name, 100, tempName);
	address = new char[100];
	strcpy_s(address, 100, "");
}

Employee::Employee(const char* tempID, const char* tempName, const char* tempAddress)
{
	ID = new char[100];
	strcpy_s(ID, 100, tempID);
	name = new char[100];
	strcpy_s(name, 100, tempName);
	address = new char[100];
	strcpy_s(address, 100, tempAddress);
}

Employee::Employee(const char* tempID, const char* tempName, const char* tempAddress, const Date tempDoB)
{
	ID = new char[100];
	strcpy_s(ID, 100, tempID);
	name = new char[100];
	strcpy_s(name, 100, tempName);
	address = new char[100];
	strcpy_s(address, 100, tempAddress);
	DoB = tempDoB;
}

Employee::~Employee()
{
	delete[] ID;
	delete[] name;
	delete[] address;
}
////////////////////////////////////////////////////////////////////
Date& Date::operator=(const Date& input)
{
	this->day = input.day;
	this->month = input.month;
	this->year = input.year;
	return *this;
}

ostream& operator<<(ostream& os, const Date& output)
{
	os << output.day << "/" << output.month << "/" << output.year;
	return os;
}
istream& operator>>(istream& is, Date& input)
{
	is >> input.day >> input.month >> input.year;
	return is;
}

///////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, const Employee& output)
{
	os << "--------------------EMPLOYEE--------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Address: " << output.address << endl;
	os << "Date of Birth: " << output.DoB << endl;
	return os;
}

istream& operator>>(istream& is, Employee& input)
{
	cout << "--------------------EMPLOYEE--------------------\n";
	cout << "Enter ID: ";
	is.get(input.ID, 100);
	is.ignore();
	cout << "Enter name: ";
	is.get(input.name, 100);
	is.ignore();
	cout << "Enter address: ";
	is.get(input.address, 100);
	is.ignore();
	cout << "Enter date of birth: ";
	cin >> input.DoB;
	is.ignore();

	return is;
}