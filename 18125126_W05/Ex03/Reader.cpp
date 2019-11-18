#include "Reader.h"

Reader::Reader()
{
	ID = "N/A";
	name = "N/A";
	gender = "N/A";
	expr.day = 1;
	expr.month = 1;
	expr.year = 1900;
}

Reader::Reader(string tempID) : Reader()
{
	ID = tempID;
}

Reader::Reader(string tempID, string tempName, string tempGender) : Reader(tempID)
{
	name = tempName;
	gender = tempGender;
}

Reader::Reader(Date input) : Reader()
{
	expr = input;
}

Reader::Reader(const Reader& cpy)
{
	ID = cpy.ID;
	name = cpy.name;
	gender = cpy.gender;
	expr = cpy.expr;
}

int Reader::fee()
{
	return 0;
}

void Reader::input()
{
	cout << "-----------------------------------------------------------\n";
	cin.ignore();
	cout << "Enter ID: ";
	getline(cin, ID);
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter gender: ";
	getline(cin, gender);
	cout << "Enter expiry date: ";
	cin >> expr;
	cin.ignore();
}

void Reader::display()
{
	cout << "-------------------------------------------------------\n";
	cout << "ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Gender: " << gender << endl;
	cout << "Expiration date: " << expr << endl;
	cout << "Fee: " << fee() << endl;
}

string Reader::getID()
{
	return ID;
}

string Reader::getName()
{
	return name;
}

int Reader::getExpiryYear()
{
	return expr.year;
}

/////////////////////////////////////////////////////
Date& Date::operator=(const Date& res)
{
	this->day = res.day;
	this->month = res.month;
	this->year = res.year;
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
