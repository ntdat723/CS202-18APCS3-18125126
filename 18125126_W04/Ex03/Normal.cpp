#include "Normal.h"

Normal::Normal() : Reader()
{
	numOfBorrow = 0;
}

Normal::Normal(int temp) : Reader()
{
	numOfBorrow = temp;
}

Normal::Normal(int temp1, int temp2) : Reader()
{
	numOfBorrow = (temp1 < temp2) ? temp1 : temp2;
}

Normal::Normal(string tempID, string tempName, string tempGender, int tempNum) : Reader(tempID, tempName, tempGender)
{
	numOfBorrow = tempNum;
}

Normal::Normal(const Normal& cpy) : Reader(cpy)
{
	this->numOfBorrow = cpy.numOfBorrow;
}

int Normal::fee() const
{
	return Reader::fee() + numOfBorrow * 5000;
}

ostream& operator<<(ostream& os, const Normal& output)
{
	os << "---------------------------NORMAL---------------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Gender: " << output.gender << endl;
	os << "Expiration date: " << output.exp << endl;
	os << "Number of books borrowing: " << output.numOfBorrow << endl;
	os << "Total fee charged: " << output.fee() << endl;
	return os;
}

istream& operator>>(istream& is, Normal& input)
{
	cout << "---------------------------NORMAL---------------------------\n";
	cout << "Enter ID: ";
	getline(is, input.ID);
	cout << "Enter name: ";
	getline(is, input.name);
	cout << "Enter gender: ";
	getline(is, input.gender);
	cout << "Enter expiry date: ";
	is >> input.exp;
	cout << "Enter number of books borrowing: ";
	is >> input.numOfBorrow;
	is.ignore();
	return is;
}