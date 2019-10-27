#pragma once
#ifndef _time_
#define _time_

#include <iostream>
#include <iomanip>
using namespace std;

class TickTock
{
private:
	int hour, minute, second;
public:
	TickTock();
	void setTime(int hInput, int mInput, int sInput);
	bool validate();
	TickTock timeForward();
	TickTock timeBackward();
	void display();
};

#endif // !_time_
