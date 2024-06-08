#include "CheesePizza.h"
#include <iostream>

using namespace std;

CheesePizza::CheesePizza(PizzaIngredientFactory* inf)
{
	this->inf = inf;
}

void CheesePizza::prepare()
{
	cout << name + " ÁØºñ Áß"  << endl;
	dough = inf->createDough();
	sauce = inf->createSauce();
	cheese = inf->createCheese();
}
