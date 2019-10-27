#include "date.h"

int main()
{
	Date current;
	int a, b, c;

	while (1)
	{
		cout << "Enter day: ";
		cin >> a;
		current.setDay(a);

		cout << "Enter month: ";
		cin >> b;
		current.setMonth(b);

		cout << "Enter year: ";
		cin >> c;
		current.setYear(c);

		bool check = current.validate(current);
		if (check == true)
		{
			break;
		}
		else
		{
			cout << "Invalid date! Re-enter: \n";
		}
	}

	cout << "Current date: ";
	current.display();
	cout << endl;

	cout << "The day before: ";
	Date prv = current.previous();
	prv.display();
	cout << endl;

	cout << "The day after: ";
	Date aft = current.following();
	aft.display();

	return 0;
}