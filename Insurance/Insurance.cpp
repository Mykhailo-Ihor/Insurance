#include "Insurance.h"
#include "FamilyInsurance.h"
#include "CarInsurance.h"
#include <string>
#include <fstream>

using namespace std;

const double Insurance::default_price = 1000;

double Insurance::getPrice() const
{
	return total_price;
}

bool Insurance::operator < (const Insurance& other)
{
	return total_price < other.total_price;
}

bool Insurance::operator > (const Insurance& other)
{
	return total_price > other.total_price;
}

istream& operator>>(istream& is, Insurance& I)
{
	I.readFrom(is);
	return is;
}

Insurance** createArrayFromFile(string fileName, size_t& n,size_t& cap)
{
	fstream fin(fileName);
	fin >> n; fin.get();
	Insurance** arr = new Insurance * [n];
	for (size_t i = 0; i < n; ++i)
	{
		char type;
		fin >> type;
		if (type == FamilyIns::FAMILY)
		{
			arr[cap] = new FamilyIns;
			fin >> *arr[cap]; 
			++cap;
		}
		else if (type == CarIns::CAR )
		{
			arr[cap] = new CarIns;
			fin >> *arr[cap];
			++cap;
		}
		else
		{
			string temp;
			getline(fin, temp);
		}
	}
	return arr;
}

void printArray(Insurance** arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		arr[i]->printOn();
	}
}

double TotalCost(Insurance** arr, size_t n)
{
	double result = 0;
	for (size_t i = 0; i < n; ++i)
	{
		result += arr[i]->getPrice();
	}
	return result;
}

Insurance* findExtreme(Insurance** arr, size_t n, bool(*predicate)(Insurance&, Insurance&))
{
	Insurance* extreme = arr[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (predicate(*arr[i], *extreme))
		{
			extreme = arr[i];
		}
	}
	return extreme;
}


bool LessThan(Insurance& a , Insurance& b)
{
	return a < b;
}
bool GreaterThan(Insurance& a, Insurance& b)
{
	return a > b;
}