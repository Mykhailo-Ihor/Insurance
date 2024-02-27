#include "CarInsurance.h"
using namespace std;
const double CarIns::min_cap = 1.1;

CarIns::CarIns(double E, double P)
{
	if (E < min_cap)
	{
		cout << "Can't create car insurance with engine capacity less than 1.1l, field is set to the default value\n";
		eng_cap = 1.1;
	}
	else
	{
		eng_cap = E;
	}
	if (P < default_price)
	{
		cout << "Can't create car insurance with base price less then 1000, field is set to the default value\n";
		base_price = default_price;
	}
	else
	{
		base_price = P;
	}
	calculate_price();
}

CarIns::CarIns(const CarIns& C) : eng_cap(C.eng_cap), Insurance(C) {};

void CarIns::printOn() const
{
	cout << "Engine capacity: " << eng_cap << "l, base price: " << base_price << ", total price: " << total_price << endl;
}

void CarIns::readFrom(std::istream& is)
{
	double cap;
	double price;
	is >> cap >> price;
	if (cap < min_cap)
	{
		cout << "Can't initialize car insurance with engine capacity less than 1.1l, field value is unchanged\n";
	}
	else
	{
		eng_cap = cap;
	}
	if (price < default_price)
	{
		cout << "Can't initialize car insurance with base price less then 1000, field value is unchanged\n";
	}
	else
	{
		base_price = price;
	}
	calculate_price();
}

void CarIns::calculate_price()
{
	if (eng_cap > 3.0)
	{
		total_price = base_price * 1.25;
	}
	else if (eng_cap > 2.0)
	{
		total_price = base_price * 1.15;
	}
	else
	{
		total_price = base_price;
	}
}
