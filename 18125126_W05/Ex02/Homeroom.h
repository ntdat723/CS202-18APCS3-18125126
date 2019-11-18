#include "Teacher.h"

class Homeroom : public Teacher
{
private:
	string ofClass;
public:
	Homeroom();
	Homeroom(string tempClass);
	Homeroom(int tempPayRate);
	Homeroom(int tempPayRate, int tempBasicPay);
	Homeroom(const Homeroom& cpy);
	void input();
	void display();
	int salary();
};