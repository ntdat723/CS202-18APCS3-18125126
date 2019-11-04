#pragma once
#ifndef _intArray_
#define _intArray_

#include <iostream>
#include <array>
using namespace std;

class IntArray
{
private:
	int* arr;
	int size;
public:
	IntArray();
	IntArray(const IntArray& cpy);
	IntArray(int num);
	IntArray(int* cpy, int num);
	friend istream& operator>>(istream& is, IntArray& input);
	friend ostream& operator<<(ostream& os, const IntArray& output);
	int& operator[](const int& num);
	IntArray& operator=(const IntArray& cpy);
	operator int();
	~IntArray();
};
#endif // !_intArray_
