#pragma once
#ifndef _w08_
#define _w08_

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Item
{
protected:
	string name;
	bool hidden;
public:
	Item();
	Item(string temp);
	virtual int getSize();
	string getName();
	void toTrue();
	void toFalse();
	virtual bool getHiddenAtt() = 0;
	virtual void print(int show);
	virtual Item* setHidden(bool fol, bool subfol);
};

class File :public Item
{
private:
	int FileSize;
	bool readOnly;
public:
	File();
	File(string tempName, int tempSize);
	int getSize();
	bool getHiddenAtt() { return hidden; }
	bool getReadOnlyAtt();
	void print(int show);
};

class Folder :public Item
{
private:
	vector<Item*> inside;
	int totalSize;
public:
	Folder();
	Folder(string temp);
	void add(Item* added);
	int getSize();
	bool getHiddenAtt();
	void print(int show);
	Item* removeByName(string removed);
	Item* findByName(string found);
	Item* setHidden(bool fol, bool subfol);
};

#endif // !_w08_
