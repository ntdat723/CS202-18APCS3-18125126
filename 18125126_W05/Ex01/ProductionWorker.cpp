#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
	numOfProducts = 0;
}

ProductionWorker::ProductionWorker(double temp)
{
	numOfProducts = temp;
}

ProductionWorker::ProductionWorker(double cmp1, double cmp2)
{
	if (cmp1 > cmp2)
	{
		numOfProducts = cmp1;
	}
	else
	{
		numOfProducts = cmp2;
	}
}

ProductionWorker::ProductionWorker(const ProductionWorker& cpy) : Employee(cpy)
{
	numOfProducts = cpy.numOfProducts;
}

ProductionWorker::ProductionWorker(double cmp1, double cmp2, double cmp3)
{
	numOfProducts = abs(cmp1 - cmp2 - cmp3);
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
	cout << "------------------------------------------\n";
}

double ProductionWorker::salary()
{
	return Employee::salary() + numOfProducts * 20000;
}

