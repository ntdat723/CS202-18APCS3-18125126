#pragma once
#ifndef _singleton_
#define _singleton_

#include <iostream>
#include <vector>
using namespace std;

class CallCenter
{
private:
	CallCenter(string name) { caller = name; }
	static vector<CallCenter*> instance;
	string caller;
public:
	static CallCenter calling(string name) // delete to free an Agent.
	{
		int i = 0;
		for (i = 0; i < instance.size(); i++) 
		{
			if (instance[i] == NULL)
			{
				instance[i] = new CallCenter(name);
				cout << name << " is calling. . ." << endl;
				return *instance[i];
			}
		}
		if (i > 2)
		{
			i = 2;
		}
		return *instance[i];
	}
};

vector<CallCenter*> CallCenter::instance(3);


#endif // !_singleton_
