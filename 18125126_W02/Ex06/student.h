#pragma once
#ifndef _student_
#define _student_

#include <iostream>
using namespace std;

class Student
{
private:
	string ID, firstName, lastName, address, DoB;
	float mark;
public:
	Student();

	void setID(string input);
	string getID();

	void setFirstName(string input);
	string getFirstName();

	void setLastName(string input);
	string getLastName();

	void setAddress(string input);
	string getAddress();

	void setDoB(string input);
	string getDoB();

	void setMark(float input);
	float getMark();

	void swap(Student& first, Student& second);
};

#endif // !_student_
