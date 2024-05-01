#include "Mocha.h"

Mocha::Mocha(Beverage* beverage)
{
    this->beverage = beverage;
}

std::string Mocha::getDescription()
{
    return this->beverage->getDescription() + ", ��ī";
}

double Mocha::cost()
{
    return this->beverage->cost() + 0.20;
}
