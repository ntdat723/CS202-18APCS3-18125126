#include "Homeroom.h"

Homeroom::Homeroom()
{
	ofClass = "N/A";
}

Homeroom::Homeroom(string tempClass)
{
	ofClass = tempClass;
}

Homeroom::Homeroom(int tempPayRate)
{
	payRate = tempPayRate;
}

Homeroom::Homeroom(int tempPayRate, int tempBasicPay)
{
	payRate = tempPayRate;
	basicPay = tempBasicPay;
}

Homeroom::Homeroom(const Homeroom& cpy) : Teacher(cpy)
{
	ofClass = cpy.ofClass;
}

void Homeroom::input()
{
	Teacher::input();
	cout << "Enter name of class: ";
	getline(cin, ofClass);
}

void Homeroom::display()
{
	Teacher::display();
	cout << "Class: " << ofClass << endl;
	cout << "----------------------------------------------\n";
}

int Homeroom::salary()
{
	return Teacher::salary() + 500000;
}

