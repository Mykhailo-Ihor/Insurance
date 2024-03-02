#include "FamilyInsurance.h"
using namespace std;

FamilyIns::FamilyIns(int M, double P)
{
	if (M < min_size)
	{
		cerr << "Cannot create family insuranse with family members less than 3, field is set to the default value\n";
		members = 3;
	}
	else
	{
		members = M;
	}
	if (P < default_price)
	{
		cerr << "Cannot create family insurance with base price less then 1000, field is set to the default value\n";
		base_price = default_price;
	}
	else
	{
		base_price = P;
	}
	calculate_price();
}

FamilyIns::FamilyIns(const FamilyIns& F) : members(F.members), Insurance(F) {};

void FamilyIns::printOn() const
{
	cout << "Family members: " << members << ", base price: " << base_price << ", total price: " << total_price << endl;
}

void FamilyIns::readFrom(std::istream& is)
{
	int mem;
	double price;
	is >> mem >> price;
	if (mem < min_size)
	{
		cerr << "Can't initialize family insuranse with family members less than 3, field value is unchanged\n";
	}
	else
	{
		members = mem;
	}
	if (price < default_price)
	{
		cerr << "Can't initialize family insurance with base price less then 1000, field value is unchanged\n";
	}
	else
	{
		base_price = price;
	}
	calculate_price();
}

void FamilyIns::calculate_price()
{
	total_price = base_price * members;
}
