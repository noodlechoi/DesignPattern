#include "Whip.h"

Whip::Whip(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Whip::getDescription()
{
	return this->beverage->getDescription() + ", ����";
}

double Whip::cost()
{
	return this->beverage->cost() + 0.10;
}
