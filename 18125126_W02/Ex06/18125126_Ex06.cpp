#include "listOfStudents.h"

int main()
{
	ListOfStudents ex;
	ex.load("ex06.txt");
	ex.sort();
	ex.save("ex06_res.xml");

	return 0;
}