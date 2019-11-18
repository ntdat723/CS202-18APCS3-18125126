#include "VIP.h"

VIP::VIP()
{
	// nothing added
}

VIP::VIP(string tempID, string tempName)
{
	ID = tempID;
	name = tempName;
}

VIP::VIP(string tempID, string tempName, string tempGender) : Reader(tempID, tempName, tempGender)
{
	expr.day = 1;
	expr.month = 1;
	expr.year = 1900;
}

VIP::VIP(string tempID, string tempName, string tempGender, Date tempEXP) : Reader(tempID, tempName, tempGender)
{
	expr = tempEXP;
}

VIP::VIP(const VIP& cpy) : Reader(cpy)
{
	// nothing added
}

int VIP::fee()
{
	return Reader::fee() + 50000;
}

void VIP::input()
{
	// nothing added
	Reader::input();
}

void VIP::display()
{
	// nothing added
	Reader::display();
	cout << "---------------------------------------------------------\n";
}