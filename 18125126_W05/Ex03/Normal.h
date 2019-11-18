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
	int fee();
	void input();
	void display();
};