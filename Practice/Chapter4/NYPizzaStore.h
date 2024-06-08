#pragma once
#include "PizzaStore.h"

class NYPizzaStore : public PizzaStore
{
public :
	Pizza* createPizza(std::string item) override;
};

