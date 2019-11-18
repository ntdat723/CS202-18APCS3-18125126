#include "VIP.h"
#include "Normal.h"

class Library
{
private:
	string lName;
	vector<Reader*> List;
public:
	Library();
	Library(const Library& cpy);
	Library(string temp);
	Library(int temp);
	Library(string tempSName, int tempNum);
	void inputList();
	void displayList();
	int totalFee();
	int numOfNormal();
	int numOfVIP();
	Reader* highestFee();
	int averageFee();
	void feeFilter();
	Reader* findByID(string found);
	Reader* findByName(string found);
	int expireIn2017();
};