#include "Insurance.h"
#include "FamilyInsurance.h"
using namespace std;

int main()
{
	size_t n;
	size_t cap = 0;
	Insurance** arr = createArrayFromFile("Insurance.txt", n, cap);
	printArray(arr, cap);
	cout << "Total cost of all insurances: " << TotalCost(arr, cap) << endl;
	cout << "Min price: " << findExtreme(arr,cap,LessThan)->getPrice() << endl;
	cout << "Max price: " << findExtreme(arr,cap,GreaterThan)->getPrice() << endl;

	return 0;
}