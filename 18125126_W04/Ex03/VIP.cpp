#include "VIP.h"

VIP::VIP() : Reader()
{
}

VIP::VIP(string tempID, string tempName) : Reader()
{
	ID = tempID;
	name = tempName;
}

VIP::VIP(string tempID, string tempName, string tempGender) : Reader(tempID, tempName, tempGender)
{
	exp.day = 1;
	exp.month = 1;
	exp.year = 1900;
}

VIP::VIP(string tempID, string tempName, string tempGender, Date tempEXP)
{
	ID = tempID;
	name = tempName;
	gender = tempGender;
	exp = tempEXP;
}

VIP::VIP(const VIP& cpy) : Reader(cpy)
{
}

int VIP::fee() const
{
	return Reader::fee() + 50000;
}

ostream& operator<<(ostream& os, const VIP& output)
{
	os << "---------------------------VIP---------------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Gender: " << output.gender << endl;
	os << "Expiration date: " << output.exp << endl;
	os << "Total fee charged: " << output.fee() << endl;
	return os;
}

istream& operator>>(istream& is, VIP& input)
{
	cout << "---------------------------VIP---------------------------\n";
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