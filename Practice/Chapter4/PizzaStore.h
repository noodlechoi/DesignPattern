#pragma once
#include "Pizza.h"

class PizzaStore
{
public:
	virtual Pizza* createPizza(std::string item) = 0;
};