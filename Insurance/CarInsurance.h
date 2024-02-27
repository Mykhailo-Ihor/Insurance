#pragma once
#include "Insurance.h"

class CarIns : public Insurance
{
private:
	double eng_cap;
	static const double min_cap;
public:
	static const char CAR = 'C';
	CarIns(double E = 1.1, double P = default_price);
	CarIns(const CarIns& C);
	void printOn() const override;
	void readFrom(std::istream& is) override;
	void calculate_price() override;
};
