#include "Insurance.h"
using namespace std;

int main()
{
	size_t n;
	Insurance** arr = createArrayFromFile("Insurance.txt", n);
	printArray(arr, n);
	cout << "Total cost of all insurances: " << TotalCost(arr, n) << endl;
	Insurance* min, * max;

	cout << "Min price: " << findExtreme(arr, n, LessThan)->getPrice() << endl;
	cout << "Max price: " << findExtreme(arr, n, GreaterThan)->getPrice() << endl;

	return 0;
}