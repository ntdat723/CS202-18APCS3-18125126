#include "Employee.h"

class Daysman :Employee
{
private:
	int daysOfWork;
public:
	Daysman();
	Daysman(int temp);
	Daysman(int first, int second);
	Daysman(const Daysman& cpy);
	Daysman(int first, int second, int third);
	long getWages() const;
	friend ostream& operator<<(ostream& os, const Daysman& output);
	friend istream& operator>>(istream& is, Daysman& input);
};