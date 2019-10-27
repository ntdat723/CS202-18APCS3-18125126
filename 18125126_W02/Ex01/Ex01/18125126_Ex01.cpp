#include "fraction.h"
#include "arrayOfFractions.h"

int main()
{
	arrayOfFractions ex;

	ex.load("ex01.txt");

	fraction max = ex.maximum();
	cout << "Max: ";
	max.getFraction();
	cout << endl;

	fraction min = ex.minimum();
	cout << "Min: ";
	min.getFraction();
	cout << endl;

	cout << "Sum: ";
	fraction total = ex.sum();
	total.getFraction();
	cout << endl;

	cout << "Before sorting: ";
	ex.display();
	cout << endl;
	ex.sort();
	cout << "After sorting (Ascending order): ";
	ex.display();

	ex.save("ex01_result.txt");

	return 0;
}