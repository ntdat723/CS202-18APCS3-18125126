#include "School.h"

int main()
{
	School highSchool;
	// a
	cout << "--------------------------------------INPUT-------------------------------------------\n";
	highSchool.inputList();
	// b
	cout << "--------------------------------------DISPLAY-----------------------------------------\n";
	highSchool.outputList();
	// c
	cout << "---------------------------TEACHER WITH HIGHEST SALARY--------------------------------\n";
	Teacher* resC = highSchool.highestSalary();
	resC->display();
	// d - e
	cout << "--------------------------NUMBER OF EACH TYPE OF TEACHERS-----------------------------\n";
	cout << "Number of normal teachers: " << highSchool.numOfNormal() << endl;
	cout << "Number of homeroom teachers: " << highSchool.numOfHomeroom() << endl;
	// f
	cout << "-----------------------------------AVERAGE SALARY-------------------------------------\n";
	cout << "Average amount of salary: " << highSchool.averageSalary() << endl;
	// g
	cout << "----------------LIST OF TEACHERS WHO HAVE THE SALARY OF ABOVE 10 MILLION--------------\n";
	highSchool.aboveTenMillion();
	// h - j
	cout << "----------------------------------------SEARCH----------------------------------------\n";
	cout << "By ID: ";
	string sID;
	getline(cin, sID);
	Teacher* bID = highSchool.findByID(sID);
	bID->display();
	cout << "By name: ";
	string sName;
	getline(cin, sName);
	Teacher* bName = highSchool.findByName(sName);
	bName->display();
	// k
	cout << "---------------------TEACHERS WHO WERE ABSENT MORE THAN 4 DAYS----------------------\n";
	cout << "There are " << highSchool.overAbsence() << " teachers that were absent more than 4 days!\n";
	return 0;
}