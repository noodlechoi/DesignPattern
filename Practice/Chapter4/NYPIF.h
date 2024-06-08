#pragma once
#include "PizzaIngredientFactory.h"

class NYPIF	: public PizzaIngredientFactory// ���� ����� ���丮
{
public:
	Dough* createDough() override;
	Sauce* createSauce() override;
	std::vector<Veggies*> createVeggies() override;
	Cheese* createCheese() override;
	Pepperoni* createPepperoni() override;
	Clams* createClams() override;
};

