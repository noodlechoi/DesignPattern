#include "NYPizzaStore.h"

int main()
{
	PizzaStore* nystore = new NYPizzaStore;
	Pizza* pizza = nystore->createPizza("cheese");
	pizza->prepare();
}