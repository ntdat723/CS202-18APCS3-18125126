#include "Reader.h"

Reader::Reader()
{
	ID = "";
	name = "";
	gender = "";
	exp.day = 1;
	exp.month = 1;
	exp.year = 1900;
}

Reader::Reader(string tempID)
{
	Reader();
	ID = tempID;
}

Reader::Reader(string tempID, string tempName, string tempGender)
{
	ID = tempID;
	name = tempName;
	gender = tempGender;
	exp.day = 1;
	exp.month = 1;
	exp.year = 1900;
}

Reader::Reader(Date input)
{
	ID = "";
	name = "";
	gender = "";
	exp = input;
}

Reader::Reader(const Reader& cpy)
{
	this->ID = cpy.ID;
	this->name = cpy.name;
	this->gender = cpy.gender;
	exp = cpy.exp;
}

int Reader::fee() const
{
	return 0;
}

ostream& operator<<(ostream& os, const Reader& output)
{
	os << "---------------------------READER---------------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Gender: " << output.gender << endl;
	os << "Expiration date: " << output.exp << endl;
	os << "Total fee charged: " << output.fee() << endl;
	return os;
}
istream& operator>>(istream& is, Reader& input)
{
	cout << "---------------------------READER---------------------------\n";
	cout << "Enter ID: ";
	getline(is, input.ID);
	cout << "Enter name: ";
	getline(is, input.name);
	cout << "Enter gender: ";
	getline(is, input.gender);
	cout << "Enter expiry date: ";
	is >> input.exp;
	is.ignore();
	return is;
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
