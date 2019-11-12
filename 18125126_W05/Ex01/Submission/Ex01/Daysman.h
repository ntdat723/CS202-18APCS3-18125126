#include "Employee.h"

class Daysman :public Employee
{
private:
	double payRate;
	double basicPay;
	double daysOff;
public:
	Daysman();
	void input();
	void display();
	double salary();
};