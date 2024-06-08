#pragma once
#include "Ingredient.h"
#include <vector>

class PizzaIngredientFactory
{
public:
	virtual Dough* createDough() = 0;
	virtual Sauce* createSauce() = 0;
	virtual std::vector<Veggies*> createVeggies() = 0;
	virtual Cheese* createCheese() = 0;
	virtual Pepperoni* createPepperoni() = 0;
	virtual Clams* createClams() = 0;
};