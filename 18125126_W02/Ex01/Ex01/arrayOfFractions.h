#pragma once
#ifndef _loadOfFractions_
#define _loadOfFractions_

#include "fraction.h"
#include <vector>

class arrayOfFractions
{
private:
	vector<fraction> ar;
	void swap(fraction& first, fraction& second);
public:
	void load(const char* path);
	fraction maximum();
	fraction minimum();
	fraction sum();
	void sort();
	void save(const char* path);
	void display();
};

#endif // !_loadOfFractions_
