#include <iostream>
#include <string>
using namespace std;

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
	size = n;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = 0;
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
	for (int i = 0; i < n; ++i)
	{
		arr[i] = this->arr[i];
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
	cout << "------------------------------------------------------------INTEGER:\n";
	MyVector<int> ai(4);
	ai.print();
	cout << endl;

	int bi[3] = { 1, 2, 3 };
	MyVector<int> ci(bi, 3);
	ci.print();
	cout << endl;
	
	MyVector<int> gi(ci);
	gi.print();
	cout << endl;
	
	cout << gi.getSize() << endl;
	
	cout << gi.getItem(0) << endl;
	
	gi.setItem(10, 0);
	gi.print();
	cout << endl;

	gi.add(4);
	gi.print();
	cout << endl;
	
	int di[4] = { 6, 9 , 11, 17 };
	gi.addRange(di, 4);
	gi.print();
	cout << endl;

	if (gi.contains(10) == false)
	{
		cout << "Not in MyVector!" << endl;
	}
	else
	{
		cout << "In MyVector!" << endl;
	}

	int xi[8];
	int ni = 8;
	gi.toArray(xi, ni);
	for (int i = 0; i < ni; ++i)
	{
		cout << xi[i] << " ";
	}
	cout << endl;

	if (gi.equals(ai) == true)
	{
		cout << "Equal!" << endl;
	}
	else
	{
		cout << "Not Equal!" << endl;
	}
	
	cout << "Index of 6: " << gi.indexOf(6) << endl;

	gi.add(6);
	gi.print(); 
	cout << "\nLast index of 6: " << gi.lastIndexOf(6) << endl;

	gi.insert(50, 7);
	gi.print();
	cout << endl;
	
	gi.remove(6);
	gi.print();
	cout << endl;

	gi.removeAt(5);
	gi.print();
	cout << endl;

	gi.reverse();
	gi.print();
	cout << endl;

	string resi = gi.toString();
	cout << resi << endl;

	gi.sortAsc();
	gi.print();
	cout << endl;

	gi.sortDesc();
	gi.print();
	cout << endl;

	////////////////////////////////////////////////////////////////////////////////// FRACTION
	cout << "------------------------------------------------------------FRACTION:\n";
	MyVector<Fraction> a(4);
	a.print();
	cout << endl;

	Fraction b[3] = { Fraction(2, 1), Fraction(2, 3), Fraction(1, 2) };
	MyVector<Fraction> c(b, 3);
	c.print();
	cout << endl;

	MyVector<Fraction> g(c);
	g.print();
	cout << endl;

	cout << g.getSize() << endl;

	cout << g.getItem(0) << endl;

	g.setItem(Fraction(7, 9), 0);
	g.print();
	cout << endl;

	g.add(Fraction(1, 6));
	g.print();
	cout << endl;

	Fraction d[4] = { Fraction(6, 7), Fraction(1, 9) , Fraction(11, 11), Fraction(1, 17) };
	g.addRange(d, 4);
	g.print();
	cout << endl;

	if (g.contains(Fraction(1, 99)) == false)
	{
		cout << "Not in MyVector!" << endl;
	}
	else
	{
		cout << "In MyVector!" << endl;
	}

	Fraction x[8];
	int n = 8;
	g.toArray(x, n);
	for (int i = 0; i < n; ++i)
	{
		cout << x[i] << " ";
	}
	cout << endl;

	if (g.equals(a) == true)
	{
		cout << "Equal!" << endl;
	}
	else
	{
		cout << "Not Equal!" << endl;
	}

	cout << "Index of 6/7: " << g.indexOf(Fraction(6, 7)) << endl;

	g.add(Fraction(6, 7));
	g.print();
	cout << "\nLast index of 6/7: " << g.lastIndexOf(Fraction(6, 7)) << endl;

	g.insert(Fraction(5, 9), 7);
	g.print();
	cout << endl;

	g.remove(Fraction(6, 7));
	g.print();
	cout << endl;

	g.removeAt(5);
	g.print();
	cout << endl;

	g.reverse();
	g.print();
	cout << endl;

	string res = g.toString();
	cout << res << endl;

	g.sortAsc();
	g.print();
	cout << endl;

	g.sortDesc();
	g.print();
	cout << endl;
	return 0;
}