#include "Daysman.h"
#include "ProductionWorker.h"
#include <vector>

class Company
{
private:
	string name;
	vector<Employee*> List;
public:
	Company();
	Company(const Company& cpy);
	Company(string temp);
	Company(int temp);
	Company(string tempName, int tempNum);
	void inputList();
	double totalSalary();
	void displayList();
	int numOfDaysman();
	int numOfProductionWorker();
	Employee* highestSalary();
	double averageSalary();
	void belowThreeMillion();
	Employee* findByID(int found);
	Employee* findByName(string found);
	int bornInMay();
};