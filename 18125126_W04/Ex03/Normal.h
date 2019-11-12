#include "Reader.h"

class Normal :public Reader
{
private:
	int numOfBorrow;
public:
	Normal();
	Normal(int temp);
	Normal(const Normal& cpy);
	Normal(int temp1, int temp2);
	Normal(string tempID, string tempName, string tempGender, int tempNum);
	int fee() const;
	friend ostream& operator<<(ostream& os, const Normal& output);
	friend istream& operator>>(istream& is, Normal& input);
};