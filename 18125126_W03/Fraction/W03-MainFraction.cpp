#include "fraction.h"

// YY: 27
int main()
{
	fraction f1;					// 0/1
	fraction f2(7);					// 7/1
	fraction f3(1, -7);				// -1/7
	fraction f4(f3);				// copy constructor
	fraction f5 = f2;					// copy constructor
	fraction f6, f7, f8;			// default constructor
	f6 = f3;							// operator =

	f7 = f1 + f5;
	f8 = f2 - f4;
	f3 = f1 * f7;
	f5 = f6 / f2;

	if (f2 == f3)
		cout << "f2 == f3" << endl;
	else
		cout << "f2 != f3" << endl;

	if (f3 != f1)
		cout << "f3 != f1" << endl;
	else
		cout << "f1 == f3" << endl;

	if (f2 >= f5)
		cout << "f2 >= f5" << endl;
	else
		cout << "f2 < f5" << endl;

	if (f2 > f5)
		cout << "f2 > f5" << endl;
	else
		cout << "f2 <= f5" << endl;

	if (f5 <= f3)
		cout << "f5 <= f3" << endl;
	else
		cout << "f5 > f3" << endl;

	if (f5 < f3)
		cout << "f5 < f3" << endl;
	else
		cout << "f5 >= f3" << endl;

	//khi viáº¿t ä‘áº§y ä‘á»§ toã¡n tá»­, cáº§n chá»‰nh láº¡i ä‘á»ƒ háº¿t lá»—i (cã¡c dã²ng 29 ä‘áº¿n 32)
	f1 = f2 + 3;
	f3 = -7 + f1;
	f5 = 7 * f3;
	f6 = f4 - 6;

	cout << f3 << endl;
	cout << f6 << endl;

	f1 += f5;
	f6 -= f7;
	f8 *= f1;
	f8 /= f2;

	cout << f8++ << endl;
	cout << ++f7 << endl;

	cout << f8-- << endl;
	cout << --f7 << endl;

	float f = (float)f3;				// 3/2 => 1.5
	return 0;
}
