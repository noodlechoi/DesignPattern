#include "Soy.h"

Soy::Soy(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Soy::getDescription()
{
	return this->beverage->getDescription() + ", µÎÀ¯";
}

double Soy::cost()
{
	return this->beverage->cost() + 0.15;
}
