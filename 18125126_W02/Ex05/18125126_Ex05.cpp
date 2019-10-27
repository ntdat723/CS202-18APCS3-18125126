#include "ticktock.h"

int main()
{
	int a, b, c;
	TickTock ex;

	while (1)
	{
		cout << "Enter hour: ";
		cin >> a;
		cout << "Enter minute: ";
		cin >> b;
		cout << "Enter second: ";
		cin >> c;

		ex.setTime(a, b, c);

		if (ex.validate() == true)
		{
			break;
		}
		else
		{
			cout << "Invalid input! Re-enter: \n";
		}
	}

	cout << "Current time: ";
	ex.display();
	cout << endl;

	TickTock oneSecFaster = ex.timeForward();
	TickTock oneSecSlower = ex.timeBackward();

	cout << "Increase by one second: ";
	oneSecFaster.display();
	cout << endl;

	cout << "Decrease by one second: ";
	oneSecSlower.display();

	return 0;
}