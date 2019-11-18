#include "Library.h"

int main()
{
	Library FullOfBooks;
	// a
	cout << "--------------------------------------INPUT-------------------------------------------\n";
	FullOfBooks.inputList();
	// b
	cout << "--------------------------------------DISPLAY-----------------------------------------\n";
	FullOfBooks.displayList();
	// c
	cout << "---------------------------READER WITH HIGHEST FEE--------------------------------\n";
	Reader* resC = FullOfBooks.highestFee();
	resC->display();
	// d - e
	cout << "--------------------------NUMBER OF EACH TYPE OF READERS-----------------------------\n";
	cout << "Number of normal readers: " << FullOfBooks.numOfNormal() << endl;
	cout << "Number of VIP readers: " << FullOfBooks.numOfVIP() << endl;
	// f
	cout << "-----------------------------------AVERAGE FEE-------------------------------------\n";
	cout << "Average amount of fee: " << FullOfBooks.averageFee() << endl;
	// g
	cout << "----------------LIST OF READERS WHO HAVE THE FEE OF ABOVE 30.000--------------\n";
	FullOfBooks.feeFilter();
	// h - j
	cout << "----------------------------------------SEARCH----------------------------------------\n";
	cout << "By ID: ";
	string sID;
	getline(cin, sID);
	Reader* bID = FullOfBooks.findByID(sID);
	bID->display();
	cout << "By name: ";
	string sName;
	getline(cin, sName);
	Reader* bName = FullOfBooks.findByName(sName);
	bName->display();
	// k
	cout << "---------------------READERS WHOSE MEMBERSHIP WILL EXPIRE IN 2017----------------------\n";
	cout << "There are " << FullOfBooks.expireIn2017() << " readers whose membership will expire in 2017!\n";
	return 0;
}