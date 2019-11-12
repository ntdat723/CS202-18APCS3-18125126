#include "Employee.h"

class ProductionWorker :public Employee
{
private:
	double numOfProducts;
public:
	ProductionWorker();
	void input();
	void display();
	double salary();
};