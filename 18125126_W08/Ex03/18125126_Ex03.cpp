#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class InvalidSizeException : public exception {
private:
	int size;
public:
	InvalidSizeException(int n) {
		size = n;
	}
	virtual const char* what() const throw() {
		stringstream stream;
		stream << "Message: Invalid size exception" << endl;
		stream << "Detail: size = " << size << endl;
		return _strdup(stream.str().c_str());
	}
};

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction() : numerator(0), denominator(1) {}
	Fraction(int a, int b) : numerator(a), denominator(b) {}
	int getNum() { return numerator; }
	int getDen() { return denominator; }
	bool operator<(const Fraction& cmp);
	bool operator>(const Fraction& cmp);
	bool operator==(const Fraction& cmp);
	bool operator!=(const Fraction& cmp);
	Fraction operator=(const int& k);
	friend ostream& operator<<(ostream& os, const Fraction& output);
};

bool Fraction::operator!=(const Fraction& cmp)
{
	if (numerator == cmp.numerator && denominator == cmp.denominator)
	{
		return false;
	}
	return true;
}

bool Fraction::operator==(const Fraction& cmp)
{
	if (numerator == cmp.numerator && denominator == cmp.denominator)
	{
		return true;
	}
	return false;
}

Fraction Fraction::operator=(const int& k)
{
	numerator = k;
	denominator = 1;
	return *this;
}

ostream& operator<<(ostream& os, const Fraction& output)
{
	os << output.numerator << "/" << output.denominator;
	return os;
}

bool Fraction::operator<(const Fraction& cmp)
{
	float res1 = (1.0 * numerator) / (1.0 * denominator);
	float res2 = (1.0 * cmp.numerator) / (1.0 * cmp.denominator);
	if (res1 < res2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator>(const Fraction& cmp)
{
	float res1 = (1.0 * numerator) / (1.0 * denominator);
	float res2 = (1.0 * cmp.numerator) / (1.0 * cmp.denominator);
	if (res1 > res2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string to_string(Fraction value)
{
	string res = to_string(value.getNum()) + "/" + to_string(value.getDen());
	return res;
}

template<class T>
class MyVector
{
private:
	T* arr;
	int size;
public:
	MyVector();
	MyVector(int n);
	MyVector(T* a, int n);
	MyVector(const MyVector& v);
	~MyVector();

	int getSize();
	T getItem(int index);
	void setItem(T value, int index);
	void add(T value);
	void addRange(T* a, int n);
	void clear();
	bool contains(T value);
	void toArray(T* arr, int& n);
	bool equals(const MyVector& v);
	int indexOf(T value);
	int lastIndexOf(T value);
	void insert(T value, int index);
	void remove(T value);
	void removeAt(int index);
	void reverse();
	string toString();
	void sortAsc();
	void sortDesc();
	void print();
};

template <class T>
MyVector<T>::MyVector()
{
	arr = NULL;
	size = 0;
}

template <class T>
MyVector<T>::MyVector(int n)
{
	if (n < 0)
	{
		throw InvalidSizeException(n);
	}
	else
	{
		size = n;
		arr = new T[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = 0;
		}
	}
}

template <class T>
MyVector<T>::MyVector(T* a, int n)
{
	size = n;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = a[i];
	}
}

template <class T>
MyVector<T>::MyVector(const MyVector& v)
{
	size = v.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = v.arr[i];
	}
}

template <class T>
MyVector<T>::~MyVector()
{
	delete[] arr;
}

template <class T>
int MyVector<T>::getSize()
{
	return size;
}

template <class T>
void MyVector<T>::add(T value)
{
	MyVector cpy(*this);
	delete[] arr;
	++size;
	arr = new T[size];
	for (int i = 0; i < size - 1; ++i)
	{
		arr[i] = cpy.arr[i];
	}
	arr[size - 1] = value;
}

template <class T>
void MyVector<T>::addRange(T* a, int n)
{
	if (n < 0)
	{
		throw InvalidSizeException(n);
	}
	else
	{
		MyVector cpy(*this);
		size += n;
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < size - n; ++i)
		{
			arr[i] = cpy.arr[i];
		}
		for (int i = size - n, j = 0; i < size && j < n; ++i, ++j)
		{
			arr[i] = a[j];
		}
	}
}

template <class T>
T MyVector<T>::getItem(int index)
{
	return arr[index];
}

template <class T>
void MyVector<T>::setItem(T value, int index)
{
	arr[index] = value;
}

template <class T>
void MyVector<T>::clear()
{
	delete[] arr;
	size = 0;
}

template <class T>
bool MyVector<T>::contains(T value)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}

template <class T>
void MyVector<T>::toArray(T* arr, int& n)
{
	if (n < 0)
	{
		throw InvalidSizeException(n);
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			arr[i] = this->arr[i];
		}
	}
}

template <class T>
bool MyVector<T>::equals(const MyVector& v)
{
	if (size == v.size)
	{
		for (int i = 0; i < v.size; ++i)
		{
			if (arr[i] == v.arr[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

template <class T>
int MyVector<T>::indexOf(T value)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
int MyVector<T>::lastIndexOf(T value)
{
	for (int i = size - 1; i >= 0; --i)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
void MyVector<T>::insert(T value, int index)
{
	MyVector cpy(*this);
	delete[] arr;
	++size;
	arr = new T[size];
	for (int i = 0; i < index; ++i)
	{
		arr[i] = cpy.arr[i];
	}
	arr[index] = value;
	for (int i = index + 1; i < size; ++i)
	{
		arr[i] = cpy.arr[i - 1];
	}
}

template <class T>
void MyVector<T>::remove(T value)
{
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
		{
			++count;
		}
	}
	MyVector cpy(*this);
	delete[] arr;
	bool toggle = false;
	size -= count;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		if (cpy.arr[i] != value && toggle == false)
		{
			arr[i] = cpy.arr[i];
		}
		else
		{
			toggle = true;
			
		}
		if (toggle == true)
		{
			arr[i] = cpy.arr[i + 1];
		}
	}
}

template <class T>
void MyVector<T>::removeAt(int index)
{
	remove(arr[index]);
}

template <class T>
void MyVector<T>::reverse()
{
	MyVector cpy(*this);
	for (int i = 0; i < size; ++i)
	{
		arr[i] = cpy.arr[size - 1 - i];
	}
}

template <class T>
string MyVector<T>::toString()
{
	string res = "{";
	for (int i = 0; i < size; ++i)
	{
		if (i != size - 1)
			res += to_string(arr[i]) + ", ";
		else
		{
			res += to_string(arr[i]) + "}";
		}
	}
	return res;
}

template <class T>
void MyVector<T>::sortAsc()
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template <class T>
void MyVector<T>::sortDesc()
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[i] < arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template <class T>
void MyVector<T>::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	////////////////////////////////////////////////////////////////////////////////// INTEGER
	MyVector<int> a(5);
	a.print();
	cout << endl;

	try
	{
		MyVector<int> b(-4);
	}
	catch (InvalidSizeException & err)
	{
		cout << err.what() << endl;
	}
	return 0;
}