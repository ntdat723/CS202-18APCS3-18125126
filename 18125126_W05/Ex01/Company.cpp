#include "Company.h"

Company::Company()
{
	name = "";
	Employee* first = new Employee;
	List.push_back(first);
}

Company::Company(const Company& cpy)
{
	name = cpy.name;
	List = cpy.List;
}

Company::Company(string temp) : Company()
{
	name = temp;
}

Company::Company(int temp)
{
	name = "";
	for (int i = 0; i < temp; ++i)
	{
		Employee* added = new Employee;
		List.push_back(added);
	}
}

Company::Company(string tempName, int tempNum)
{
	name = tempName;
	for (int i = 0; i < tempNum; ++i)
	{
		Employee* added = new Employee;
		List.push_back(added);
	}
}

void Company::inputList()
{
	int num, type;
	Employee* in;
	cout << "------------------------------------------------------------------------\n";
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
	cout << "------------------------------------------------------------------------\n";
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
		total += List.at(i)->salary();
	}
	return total;
}

Employee* Company::highestSalary()
{
	Employee* max = List.at(0);
	double hSalary = List.at(0)->salary();
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->salary() > hSalary)
		{
			hSalary = List.at(i)->salary();
			max = List.at(i);
		}
	}
	return max;
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

double Company::averageSalary()
{
	return totalSalary() / List.size();
}

void Company::belowThreeMillion()
{
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->salary() < 3000000)
		{
			List.at(i)->display();
		}
	}
}

Employee* Company::findByID(int found)
{
	Employee* res;
	for (int i = 0; i < List.size(); ++i)
	{
		if (found == List.at(i)->getID())
		{
			res = List.at(i);
			return res;
		}
	}
	res = new Employee;
	return res;
}

Employee* Company::findByName(string found)
{
	Employee* res;
	for (int i = 0; i < List.size(); ++i)
	{
		if (found.compare(List.at(i)->getName()) == 0)
		{
			res = List.at(i);
			return res;
		}
	}
	res = new Employee;
	return res;
}

int Company::bornInMay()
{
	int total = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->getMonth() == 5)
		{
			++total;
		}
	}
	return total;
}