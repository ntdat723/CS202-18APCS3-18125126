#include "Library.h"

Library::Library()
{
	lName = "";
}

Library::Library(const Library& cpy)
{
	lName = cpy.lName;
	List = cpy.List;
}

Library::Library(string temp) : Library()
{
	lName = temp;
}

Library::Library(int temp)
{
	lName = "";
	for (int i = 0; i < temp; ++i)
	{
		Reader* added = new Reader;
		List.push_back(added);
	}
}

Library::Library(string tempSName, int tempNum)
{
	lName = tempSName;
	for (int i = 0; i < tempNum; ++i)
	{
		Reader* added = new Reader;
		List.push_back(added);
	}
}


void Library::inputList()
{
	int num, type;
	Reader* in;
	cout << "------------------------------------------------------------------------\n";
	cout << "Enter the number of readers: ";
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cout << "Enter information for reader number " << i + 1 << ": \n";
		cout << "Enter the type of reader (1 for normal reader, 2 for VIP reader): ";
		cin >> type;
		in = NULL;
		if (type == 1)
		{
			in = new Normal;
		}
		else if (type == 2)
		{
			in = new VIP;
		}
		in->input();
		List.push_back(in);
	}
	cout << "------------------------------------------------------------------------\n";
}

void Library::displayList()
{
	for (int i = 0; i < List.size(); ++i)
	{
		List.at(i)->display();
	}
}

int Library::totalFee()
{
	int total = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		total += List.at(i)->fee();
	}
	return total;
}

Reader* Library::highestFee()
{
	Reader* max = List.at(0);
	double hFee = List.at(0)->fee();
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->fee() > hFee)
		{
			hFee = List.at(i)->fee();
			max = List.at(i);
		}
	}
	return max;
}

int Library::numOfNormal()
{
	int count = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (typeid(*List.at(i)) == typeid(Normal))
		{
			++count;
		}
	}
	return count;
}

int Library::numOfVIP()
{
	int count = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (typeid(*List.at(i)) == typeid(VIP))
		{
			++count;
		}
	}
	return count;
}

int Library::averageFee()
{
	return totalFee() / List.size();
}

void Library::feeFilter()
{
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->fee() > 30000)
		{
			List.at(i)->display();
		}
	}
}

Reader* Library::findByID(string found)
{
	Reader* res;
	for (int i = 0; i < List.size(); ++i)
	{
		if (found.compare(List.at(i)->getID()) == 0)
		{
			res = List.at(i);
			return res;
		}
	}
	res = new Reader;
	return res;
}

Reader* Library::findByName(string found)
{
	Reader* res;
	for (int i = 0; i < List.size(); ++i)
	{
		if (found.compare(List.at(i)->getName()) == 0)
		{
			res = List.at(i);
			return res;
		}
	}
	res = new Reader;
	return res;
}

int Library::expireIn2017()
{
	int count = 0;
	for (int i = 0; i < List.size(); ++i)
	{
		if (List.at(i)->getExpiryYear() == 2017)
		{
			++count;
		}
	}
	return count;
}