#include "student.h"

Student::Student()
{
	ID = "";
	firstName = "";
	lastName = "";
	address = "";
	DoB = "";
	mark = -1;
}

void Student::setID(string input)
{
	ID = input;
}

string Student::getID()
{
	return ID;
}

void Student::setFirstName(string input)
{
	firstName = input;
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setLastName(string input)
{
	lastName = input;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setAddress(string input)
{
	address = input;
}

string Student::getAddress()
{
	return address;
}

void Student::setDoB(string input)
{
	DoB = input;
}

string Student::getDoB()
{
	return DoB;
}

void Student::setMark(float input)
{
	mark = input;
}

float Student::getMark()
{
	return mark;
}

void Student::swap(Student& first, Student& second)
{
	Student temp;
	temp = first;
	first = second;
	second = temp;
}