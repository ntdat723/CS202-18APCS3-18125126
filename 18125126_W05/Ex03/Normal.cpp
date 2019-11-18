#include "Normal.h"

Normal::Normal()
{
	numOfBorrow = 0;
}

Normal::Normal(int temp)
{
	numOfBorrow = temp;
}

Normal::Normal(int temp1, int temp2)
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

int Normal::fee()
{
	return Reader::fee() + numOfBorrow * 5000;
}

void Normal::input()
{
	Reader::input();
	cout << "Enter number of books borrowing: ";
	cin >> numOfBorrow;
	cin.ignore();
}

void Normal::display()
{
	Reader::display();
	cout << "Number of books borrowing: " << numOfBorrow << endl;
	cout << "---------------------------------------------------------\n";
}