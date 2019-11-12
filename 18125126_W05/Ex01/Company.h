#include "Daysman.h"
#include "ProductionWorker.h"
#include <vector>

class Company
{
private:
	string name;
	vector<Employee*> List;
public:
	void inputList();
	double totalSalary();
	void displayList();
	int numOfDaysman();
	int numOfProductionWorker();
};