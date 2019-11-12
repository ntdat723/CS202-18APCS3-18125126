#include "Company.h"

int main()
{
	Company INC;
	INC.inputList();
	INC.displayList();
	cout << "Number of daysman: " << INC.numOfDaysman() << endl;
	cout << "Number of production workers: " << INC.numOfProductionWorker() << endl;

	return 0;
}