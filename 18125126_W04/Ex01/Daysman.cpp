#include "Daysman.h"

Daysman::Daysman()
{
	daysOfWork = 0;
}

Daysman::Daysman(int temp)
{
	daysOfWork = temp;
}

long Daysman::getWages() const
{
	return daysOfWork * 300000;
}

Daysman::Daysman(int first, int second)
{
	daysOfWork = (first > second) ? first : second;
}

Daysman::Daysman(const Daysman& cpy)
{
	ID = new char[100];
	strcpy_s(ID, 100, cpy.ID);
	name = new char[100];
	strcpy_s(name, 100, cpy.name);
	address = new char[100];
	strcpy_s(address, 100, cpy.address);
	DoB = cpy.DoB;
	daysOfWork = cpy.daysOfWork;
}

Daysman::Daysman(int first, int second, int third)
{
	if (first > second && second < third)
	{
		daysOfWork = second;
	}
	else
	{
		daysOfWork = third;
	}
}

ostream& operator<<(ostream& os, const Daysman& output)
{
	os << "--------------------DAYSMAN--------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Address: " << output.address << endl;
	os << "DoB: " << output.DoB.day << "/" << output.DoB.month << "/" << output.DoB.year << endl;
	long int w = output.getWages();
	os << "Wages: " << w << endl;
	return os;
}

istream& operator>>(istream& is, Daysman& input)
{
	cout << "--------------------DAYSMAN--------------------\n";
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
	cout << "Enter days of work: ";
	cin >> input.daysOfWork;
	is.ignore();

	return is;
}