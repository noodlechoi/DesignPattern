#pragma once
#include "PizzaIngredientFactory.h"

class NYPIF	: public PizzaIngredientFactory// ´º¿å ¿øÀç·á ÆÑÅä¸®
{
public:
	Dough* createDough() override;
	Sauce* createSauce() override;
	std::vector<Veggies*> createVeggies() override;
	Cheese* createCheese() override;
	Pepperoni* createPepperoni() override;
	Clams* createClams() override;
};

