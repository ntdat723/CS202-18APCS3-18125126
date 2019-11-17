#include "Employee.h"

class ProductionWorker :public Employee
{
private:
	double numOfProducts;
public:
	ProductionWorker();
	ProductionWorker(double temp);
	ProductionWorker(double cmp1, double cmp2);
	ProductionWorker(const ProductionWorker& cpy);
	ProductionWorker(double cmp1, double cmp2, double cmp3);
	void input();
	void display();
	double salary();
};