#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
	numOfProduct = 0;
}

ProductionWorker::ProductionWorker(int temp)
{
	numOfProduct = temp;
}

long ProductionWorker::getSalary() const
{
	return numOfProduct * 20000;
}

ProductionWorker::ProductionWorker(const ProductionWorker& cpy)
{
	ID = new char[100];
	strcpy_s(ID, 100, cpy.ID);
	name = new char[100];
	strcpy_s(name, 100, cpy.name);
	address = new char[100];
	strcpy_s(address, 100, cpy.address);
	DoB = cpy.DoB;
	numOfProduct = cpy.numOfProduct;
}

ProductionWorker::ProductionWorker(int first, int second)
{
	numOfProduct = (first > second) ? second : first;
}
ProductionWorker::ProductionWorker(int first, int second, int third)
{
	if (first < second && second > third)
	{
		numOfProduct = second;
	}
	else
	{
		numOfProduct = third;
	}
}

ostream& operator<<(ostream& os, const ProductionWorker& output)
{
	os << "--------------------PRODUCT WORKER--------------------\n";
	os << "ID: " << output.ID << endl;
	os << "Name: " << output.name << endl;
	os << "Address: " << output.address << endl;
	os << "DoB: " << output.DoB.day << "/" << output.DoB.month << "/" << output.DoB.year << endl;
	long int s = output.getSalary();
	os << "Salary: " << s << endl;
	return os;
}

istream& operator>>(istream& is, ProductionWorker& input)
{
	cout << "--------------------PRODUCTION WORKER--------------------\n";
	cout << "Enter ID: ";
	is.get(input.ID, 100);
	is.ignore();
	cout << "Enter name: ";
	is.get(input.name, 100);
	is.ignore();
	cout << "Enter address: ";
	is.get(input.address, 100);
	is.ignore();
	cout << "Enter date of birth: ";
	cin >> input.DoB;
	cout << "Enter the number of products made: ";
	cin >> input.numOfProduct;
	is.ignore();

	return is;
}