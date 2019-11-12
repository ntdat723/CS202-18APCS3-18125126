#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
	Employee();
	numOfProducts = 0;
}

void ProductionWorker::input()
{
	Employee::input();
	cout << "Enter number of products: ";
	cin >> numOfProducts;
}

void ProductionWorker::display()
{
	Employee::display();
	cout << "Number of products: " << numOfProducts << endl;
}

double ProductionWorker::salary()
{
	return Employee::salary() + numOfProducts * 10000;
}

