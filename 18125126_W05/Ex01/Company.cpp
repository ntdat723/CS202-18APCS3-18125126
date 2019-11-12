#include "Company.h"

void Company::inputList()
{
	int num, type;
	Employee* in;
	cout << "Enter the number of employees: ";
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cout << "Enter information for employee number " << i + 1 << ": \n";
		cout << "Enter the type of employee (1 for production worker, 2 for daysman): ";
		cin >> type;
		in = NULL;
		if (type == 1)
		{
			in = new ProductionWorker;
		}
		else if (type == 2)
		{
			in = new Daysman;
		}
		in->input();
		List.push_back(in);
	}
}

void Company::displayList()
{
	for (int i = 0; i < List.size(); ++i)
	{
		List.at(i)->display();
	}
}

double Company::totalSalary()
{
	double total = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		total += List.at(0)->salary();
	}
	return total;
}

int Company::numOfDaysman()
{
	int n = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (typeid(*List.at(i)) == typeid(Daysman))
		{
			++n;
		}
	}
	return n;
}

int Company::numOfProductionWorker()
{
	int n = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (typeid(*List.at(i)) == typeid(ProductionWorker))
		{
			++n;
		}
	}
	return n;
}