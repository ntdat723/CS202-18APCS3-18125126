#include "listOfStudents.h"

void ListOfStudents::load(const char* path)
{
	ifstream input;
	input.open(path);

	int num;
	input >> num;

	for (int i = 0; i < num; ++i)
	{
		string tmp;
		float mTemp;
		Student temp;

		input >> tmp;
		temp.setID(tmp);

		input >> tmp;
		temp.setFirstName(tmp);

		input >> tmp;
		temp.setLastName(tmp);

		input >> tmp;
		temp.setAddress(tmp);

		input >> tmp;
		temp.setDoB(tmp);

		input >> mTemp;
		temp.setMark(mTemp);

		ar.push_back(temp);
	}
	input.close();
}

void ListOfStudents::sort()
{
	for (int i = 0; i < ar.size() - 1; ++i)
	{
		for (int j = i + 1; j < ar.size(); ++j)
		{
			string str1 = ar.at(i).getLastName();
			string str2 = ar.at(j).getLastName();
			int l = (str1.length() > str2.length()) ? str2.length() : str1.length();
			for (int k = 0; k < l; ++k)
			{
				if (str1.at(k) > str2.at(k))
				{
					swap(ar.at(i), ar.at(j));
					break;
				}
				else if (str1.at(k) < str2.at(k))
				{
					break;
				}
			}
		}
	}
}

void ListOfStudents::save(const char* path)
{
	ofstream output;
	output.open(path);

	output << "<?xml version=" "\"1.0""\" encoding=""\"UTF-8""\"?>\n";
	output << "<ListOfStudents>\n";

	for (int i = 0; i < ar.size(); ++i)
	{
		output << "<student>\n";
		output << "	<ID>" << ar.at(i).getID() << "</ID>\n";
		output << "	<LastName>" << ar.at(i).getLastName() << "</LastName>\n";
		output << "	<FirstName>" << ar.at(i).getFirstName() << "</FirstName>\n";
		output << "	<Address>" << ar.at(i).getAddress() << "</Address>\n";
		output << "	<DateOfBirth>" << ar.at(i).getDoB() << "</DateOfBirth>\n";
		output << "	<Mark>" << ar.at(i).getMark() << "</Mark>\n";
		output << "</student>\n";
	}
	output << "</ListOfStudents>";
	output.close();
}