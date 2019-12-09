#include "header.h"

Item::Item()
{
	name = "";
	hidden = false;
}

Item::Item(string temp) : Item()
{
	name = temp;
}

int Item::getSize()
{
	return 0;
}

string Item::getName()
{
	return name;
}


void Item::print(int show)
{
}

Item* Item::setHidden(bool fol, bool subfol)
{
	return this;
}

void Item::toTrue()
{
	hidden = true;
}

void Item::toFalse()
{
	hidden = false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
File::File()
{
	FileSize = 0;
	readOnly = true;
}

File::File(string tempName, int tempSize) : Item(tempName)
{
	FileSize = tempSize;
	readOnly = true;
}

int File::getSize()
{
	return Item::getSize() + FileSize;
}

bool File::getReadOnlyAtt()
{
	return true;
}

void File::print(int show)
{
	if (show == 0)
	{
		if (getReadOnlyAtt() == true)
		{
			cout << "Name: " << getName() << endl;
			cout << "File Size: " << getSize() << endl;
		}
	}
	else
	{
		cout << "Name: " << getName() << endl;
		cout << "File Size: " << getSize() << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
Folder::Folder()
{
	totalSize = 0;
	hidden = false;
}

Folder::Folder(string temp) : Item(temp)
{
	Folder();
}

void Folder::add(Item* added)
{
	inside.push_back(added);
	totalSize += added->getSize();
}

int Folder::getSize()
{
	return Item::getSize() + totalSize;
}

bool Folder::getHiddenAtt()
{
	return hidden;
}

void Folder::print(int show)
{

	if (show == 0)
	{
		for (int i = 0; i < inside.size(); ++i)
		{
			if (inside.at(i)->getHiddenAtt() == false)
			{
				cout << "Folder Name: " << getName() << endl;
				cout << "Folder Size: " << getSize() << endl;
				inside.at(i)->print(show);
			}
		}
	}
	else
	{
		for (int i = 0; i < inside.size(); ++i)
		{
			cout << "Folder Name: " << getName() << endl;
			cout << "Folder Size: " << getSize() << endl;
			inside.at(i)->print(show);
		}
	}
}

Item* Folder::removeByName(string removed)
{
	for (int i = 0; i < inside.size(); ++i)
	{
		if (inside.at(i)->getName().compare(removed) == false)
		{
			totalSize -= inside.at(i)->getSize();
			inside.erase(inside.begin() + i);
			break;
		}
	}
	return this;
}

Item* Folder::findByName(string found)
{
	for (int i = 0; i < inside.size(); ++i)
	{
		if (inside.at(i)->getHiddenAtt() == false)
		{
			if (inside.at(i)->getName() == found)
			{
				return inside.at(i);
			}
		}
	}
	return NULL;
}

Item* Folder::setHidden(bool fol, bool subfol)
{
	if (fol == true && subfol == true)
	{
		for (int i = 0; i < inside.size(); ++i)
		{
			inside.at(i)->setHidden(fol, subfol);
			inside.at(i)->toTrue();
		}
		toTrue();
	}
	else if (fol == true && subfol == false)
	{
		for (int i = 0; i < inside.size(); ++i)
		{
			inside.at(i)->setHidden(fol, subfol);
			inside.at(i)->toFalse();
		}
		toTrue();
	}
	else if (fol == false && subfol == true)
	{
		for (int i = 0; i < inside.size(); ++i)
		{
			inside.at(i)->setHidden(fol, subfol);
			inside.at(i)->toTrue();
		}
		toFalse();
	}
	return this;
}