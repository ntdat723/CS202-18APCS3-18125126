#include "Employee.h"

class Daysman :public Employee
{
private:
	double workDays;
public:
	Daysman();
	Daysman(int temp);
	Daysman(int cmp1, int cmp2);
	Daysman(int cmp1, int cmp2, int cmp3);
	Daysman(const Daysman& cpy);
	void input();
	void display();
	double salary();
};