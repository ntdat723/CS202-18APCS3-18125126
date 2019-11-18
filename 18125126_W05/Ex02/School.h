#include "Homeroom.h"

class School
{
private:
	string sName;
	vector<Teacher*> List;
public:
	School();
	School(const School& cpy);
	School(string temp);
	School(int temp);
	School(string tempSName, int tempNum);
	void inputList();
	void outputList();
	int totalSalary();
	int numOfNormal();
	int numOfHomeroom();
	Teacher* highestSalary();
	int averageSalary();
	void aboveTenMillion();
	Teacher* findByID(string found);
	Teacher* findByName(string found);
	int overAbsence();
};