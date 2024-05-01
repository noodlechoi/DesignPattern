#include "Mocha.h"

Mocha::Mocha(Beverage* beverage)
{
    this->beverage = beverage;
}

std::string Mocha::getDescription()
{
    return this->beverage->getDescription() + ", ¸ðÄ«";
}

double Mocha::cost()
{
    return this->beverage->cost() + 0.20;
}
