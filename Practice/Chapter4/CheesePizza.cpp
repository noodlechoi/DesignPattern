#include "CheesePizza.h"
#include <iostream>

using namespace std;

CheesePizza::CheesePizza(PizzaIngredientFactory* inf)
{
	this->inf = inf;
}

void CheesePizza::prepare()
{
	cout << "ÁØºñ Áß" + name << endl;
	dough = inf->createDough();
	sauce = inf->createSauce();
	cheese = inf->createCheese();
}
