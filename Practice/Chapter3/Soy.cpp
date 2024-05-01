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
	double cost = this->beverage->cost();
	if (beverage->getSize() == SIZE::TALL) {
		cost += 0.10;
	}
	else if (beverage->getSize() == SIZE::GRANDE) {
		cost += 0.15;
	}
	else if (beverage->getSize() == SIZE::VENTI) {
		cost += 0.20;
	}
	return cost;
}
