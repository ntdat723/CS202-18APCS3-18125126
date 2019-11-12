#include "Reader.h"

class VIP :public Reader
{
public:
	VIP();
	VIP(string tempID, string tempName);
	VIP(const VIP& cpy);
	VIP(string tempID, string tempName, string tempGender);
	VIP(string tempID, string tempName, string tempGender, Date tempEXP);
	int fee() const;
	friend ostream& operator<<(ostream& os, const VIP& output);
	friend istream& operator>>(istream& is, VIP& input);
};