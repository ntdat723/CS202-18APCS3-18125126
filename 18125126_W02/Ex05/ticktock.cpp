#include "ticktock.h"

TickTock::TickTock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

void TickTock::setTime(int hInput, int mInput, int sInput)
{
	hour = hInput;
	minute = mInput;
	second = sInput;
}

bool TickTock::validate()
{
	if ((hour < 0 || hour > 23)
		|| (minute < 0 || minute > 59)
		|| (second < 0 || second > 59))
	{
		return false;
	}
	else
	{
		return true;
	}
}

TickTock TickTock::timeForward()
{
	TickTock cpy;
	cpy.setTime(hour, minute, second);
	if (hour == 23 && minute == 59 && second == 59)
	{
		cpy.hour = cpy.minute = cpy.second = 0;
	}
	else if (minute == 59 && second == 59)
	{
		++cpy.hour;
		cpy.minute = cpy.second = 0;
	}
	else if (second == 59)
	{
		++cpy.minute;
	}
	else
	{
		++cpy.second;
	}
	return cpy;
}

TickTock TickTock::timeBackward()
{
	TickTock cpy;
	cpy.setTime(hour, minute, second);
	if (hour == 0 && minute == 0 && second == 0)
	{
		cpy.hour = 23;
		cpy.minute = cpy.second = 59;
	}
	else if (minute == 0 && second == 0)
	{
		--cpy.hour;
		cpy.minute = cpy.second = 59;
	}
	else if (second == 0)
	{
		--cpy.minute;
		cpy.second = 59;
	}
	else
	{
		--cpy.second;
	}
	return cpy;
}

void TickTock::display()
{
	cout << setw(2) << setfill('0') << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

