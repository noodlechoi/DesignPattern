#pragma once
#include "PizzaIngredientFactory.h"
#include "Pizza.h"

class CheesePizza : public Pizza
{
private:
	PizzaIngredientFactory* inf{};
public:
	CheesePizza(PizzaIngredientFactory* inf);
	void prepare() override;
};

