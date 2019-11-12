#include "Teacher.h"

class HomeroomTeacher :Teacher
{
private:
	string ofClass;
public:
	HomeroomTeacher();
	HomeroomTeacher(string temp);
	HomeroomTeacher(int x, int y);
	HomeroomTeacher(int pRate1, int pRate2, int pRate3);
	HomeroomTeacher(const HomeroomTeacher& cpy);
	int salary() const;
	friend ostream& operator<<(ostream& os, const HomeroomTeacher& output);
	friend istream& operator>>(istream& is, HomeroomTeacher& input);
};