#include "VIP.h"
#include "Normal.h"

int main()
{
	Reader first;
	cin >> first;
	cout << first;

	Normal second;
	cin >> second;
	cout << second;

	VIP third;
	cout << third;

	Normal fourth(second);
	cout << fourth;

	return 0;
}