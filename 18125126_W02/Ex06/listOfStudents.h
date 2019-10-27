#pragma once
#ifndef _ListOfStudents_
#define _ListOfStudents_

#include "student.h"
#include <vector>
#include <fstream>

class ListOfStudents
{
private:
	vector<Student> ar;
public:
	void load(const char* path);
	void sort();
	void save(const char* path);
};

#endif // !_ListOfStudent_
