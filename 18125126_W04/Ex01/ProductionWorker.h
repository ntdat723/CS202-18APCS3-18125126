#include "Employee.h"

class ProductionWorker :Employee
{
private:
	int numOfProduct;
public:
	ProductionWorker();
	ProductionWorker(const ProductionWorker& cpy);
	ProductionWorker(int first, int second);
	ProductionWorker(int first, int second, int third);
	ProductionWorker(int temp);
	long getSalary() const;
	friend ostream& operator<<(ostream& os, const ProductionWorker& output);
	friend istream& operator>>(istream& is, ProductionWorker& input);
};