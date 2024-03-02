#pragma once
#include <iostream>
#include <string>
#include <exception>
class Insurance abstract
{
protected:
	double base_price;
	double total_price;
	static const double default_price;
public:
	Insurance() = default;
	Insurance(const Insurance& I) = default;
	~Insurance() {};
	virtual void printOn() const abstract;
	virtual void readFrom(std::istream& is) abstract;
	virtual void calculate_price() abstract;
	double getPrice() const;
	bool operator < (const Insurance& other);
	bool operator > (const Insurance& other);
};

std::istream& operator >> (std::istream& is, Insurance& I);

Insurance** createArrayFromFile(std::string fileName, size_t& n,size_t& cap);

void printArray(Insurance** arr, size_t n);

double TotalCost(Insurance** arr, size_t n);

Insurance* findExtreme(Insurance** arr, size_t n, bool(*predicate)(Insurance&, Insurance&));

bool LessThan(Insurance& a, Insurance& b);

bool GreaterThan(Insurance& a, Insurance& b);
