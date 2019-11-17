#include "Daysman.h"

Daysman::Daysman()
{
	workDays = 0;
}

Daysman::Daysman(int temp)
{
	workDays = temp;
}

Daysman::Daysman(int cmp1, int cmp2)
{
	if (cmp1 < cmp2)
	{
		workDays = cmp1;
	}
	else
	{
		workDays = cmp2;
	}
}

Daysman::Daysman(int cmp1, int cmp2, int cmp3)
{
	workDays = abs(cmp1 - cmp2 - cmp3);
}

Daysman::Daysman(const Daysman& cpy) : Employee(cpy)
{
	workDays = cpy.workDays;
}

void Daysman::input()
{
	Employee::input();
	cout << "Enter number of working days: ";
	cin >> workDays;
}

void Daysman::display()
{
	Employee::display();
	cout << "Days of working: " << workDays << endl;
	cout << "------------------------------------------\n";
}

double Daysman::salary()
{
	return Employee::salary() + workDays * 300000;
}