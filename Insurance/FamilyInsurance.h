#pragma once
#include "Insurance.h"

class FamilyIns : public Insurance
{
private:
	int members;
	static const int min_size = 3;
public:
	static const char FAMILY = 'F';
	FamilyIns(int M = 3, double P = default_price);
	FamilyIns(const FamilyIns& F);
	void printOn() const override;
	void readFrom(std::istream& is) override;
	void calculate_price() override;
};
