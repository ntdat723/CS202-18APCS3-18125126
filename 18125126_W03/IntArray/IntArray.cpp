#include "intArray.h"

IntArray::IntArray()
{
	size = 1;
	arr = new int[size];
	arr[0] = 0;
}

IntArray::IntArray(const IntArray& input)
{
	size = input.size;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = input.arr[i];
	}
}

IntArray::IntArray(int num)
{
	size = num;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = 0;
	}
}


IntArray::IntArray(int* cpy, int num)
{
	size = num;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = cpy[i];
	}
}

istream& operator>>(istream& is, IntArray& input)
{
	delete[] input.arr;
	cout << "Enter number of elements: ";
	int num;
	is >> num;
	input.size = num;
	input.arr = new int[num];
	for (int i = 0; i < num; ++i)
	{
		is >> input.arr[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const IntArray& output)
{
	for (int i = 0; i < output.size; ++i)
	{
		os << output.arr[i] << " ";
	}
	return os;
}

int& IntArray::operator[](const int& num)
{
	return arr[num];
}

IntArray::operator int()
{
	int total = 0;
	for (int i = 0; i < size; ++i)
	{
		total += arr[i];
	}
	return total;
}

IntArray& IntArray::operator=(const IntArray& cpy)
{
	size = cpy.size;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = cpy.arr[i];
	}
	return *this;
}

IntArray::~IntArray()
{
	delete[] arr;
}

