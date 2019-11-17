#include "Company.h"

int main()
{
	Company INC;
	// a
	cout << "--------------------------------------INPUT-------------------------------------------\n";
	INC.inputList();
	// b
	cout << "--------------------------------------DISPLAY-----------------------------------------\n";
	INC.displayList();
	// c
	cout << "--------------------------EMPLOYEE WITH HIGHEST SALARY--------------------------------\n";
	Employee* resC = INC.highestSalary();
	resC->display();
	// d - e
	cout << "-------------------------NUMBER OF EACH TYPE OF EMPLOYEES-----------------------------\n";
	cout << "Number of daysman: " << INC.numOfDaysman() << endl;
	cout << "Number of production workers: " << INC.numOfProductionWorker() << endl;
	// f
	cout << "-----------------------------------AVERAGE SALARY-------------------------------------\n";
	cout << "Average amount of salary: " << INC.averageSalary() << endl;
	// g
	cout << "---------------LIST OF EMPLOYEES WHO HAVE THE SALARY OF BELOW 3 MILLION---------------\n";
	INC.belowThreeMillion();
	// h - j
	cout << "----------------------------------------SEARCH----------------------------------------\n";
	cout << "By ID: ";
	int sID;
	cin >> sID;
	cin.ignore();
	Employee* bID = INC.findByID(sID);
	bID->display();
	cout << "By name: ";
	string sName;
	getline(cin, sName);
	Employee* bName = INC.findByName(sName);
	bName->display();
	// k
	cout << "-----------------------------EMPLOYEES WHO WERE BORN IN MAY---------------------------\n";
	cout << "There are " << INC.bornInMay() << " employees that were born in May!\n";
	return 0;
}