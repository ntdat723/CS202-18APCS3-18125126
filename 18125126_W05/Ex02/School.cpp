#include "School.h"

School::School()
{
	sName = "";
}

School::School(const School& cpy)
{
	sName = cpy.sName;
	List = cpy.List;
}

School::School(string temp) : School()
{
	sName = temp;
}

School::School(int temp)
{
	sName = "";
	for (int i = 0; i < temp; ++i)
	{
		Teacher* added = new Teacher;
		List.push_back(added);
	}
}

School::School(string tempSName, int tempNum)
{
	sName = tempSName;
	for (int i = 0; i < tempNum; ++i)
	{
		Teacher* added = new Teacher;
		List.push_back(added);
	}
}


void School::inputList()
{
	int num, type;
	Teacher* in;
	cout << "------------------------------------------------------------------------\n";
	cout << "Enter the number of teachers: ";
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cout << "Enter information for teacher number " << i + 1 << ": \n";
		cout << "Enter the type of teacher (1 for normal teacher, 2 for homeroom one): ";
		cin >> type;
		in = NULL;
		if (type == 1)
		{
			in = new Teacher;
		}
		else if (type == 2)
		{
			in = new Homeroom;
		}
		in->input();
		List.push_back(in);
	}
	cout << "------------------------------------------------------------------------\n";
}

void School::outputList()
{
	for (int i = 0; i < List.size(); ++i)
	{
		List.at(i)->display();
	}
}

int School::totalSalary()
{
	int total = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		total += List.at(i)->salary();
	}
	return total;
}

Teacher* School::highestSalary()
{
	Teacher* max = List.at(0);
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

int School::numOfNormal()
{
	int count = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (typeid(*List.at(i)) == typeid(Teacher))
		{
			++count;
		}
	}
	return count;
}

int School::numOfHomeroom()
{
	int count = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (typeid(*List.at(i)) == typeid(Homeroom))
		{
			++count;
		}
	}
	return count;
}

int School::averageSalary()
{
	return totalSalary() / List.size();
}

void School::aboveTenMillion()
{
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->salary() > 10000000)
		{
			List.at(i)->display();
		}
	}
}

Teacher* School::findByID(string found)
{
	Teacher* res;
	for (int i = 0; i < List.size(); ++i)
	{
		if (found.compare(List.at(i)->getID()) == 0)
		{
			res = List.at(i);
			return res;
		}
	}
	res = new Teacher;
	return res;
}

Teacher* School::findByName(string found)
{
	Teacher* res;
	for (int i = 0; i < List.size(); ++i)
	{
		if (found.compare(List.at(i)->getName()) == 0)
		{
			res = List.at(i);
			return res;
		}
	}
	res = new Teacher;
	return res;
}

int School::overAbsence()
{
	int count = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->getDaysOff() > 4)
		{
			++count;
		}
	}
	return count;
}