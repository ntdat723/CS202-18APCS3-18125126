#include "Daysman.h"

Daysman::Daysman()
{
	Employee();
	basicPay = 0;
	payRate = 0;
	daysOff = 0;
}

void Daysman::input()
{
	Employee::input();
	cout << "Enter basic pay: ";
	cin >> basicPay;
	cout << "Enter pay rate: ";
	cin >> payRate;
	cout << "Enter number of days off: ";
	cin >> daysOff;
}

void Daysman::display()
{
	Employee::display();
	cout << "Basic pay: " << basicPay << endl;
	cout << "Pay rate: " << payRate << endl;
	cout << "Number of days off: " << daysOff << endl;
}

double Daysman::salary()
{
	double res = Employee::salary() + basicPay * payRate - daysOff * 300000;
	return (res < 0) ? 0 : res;
}