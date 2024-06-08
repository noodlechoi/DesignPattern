#include "NYPizzaStore.h"
#include "NYPIF.h"
#include "CheesePizza.h"

Pizza* NYPizzaStore::createPizza(std::string item)
{
    Pizza* pizza = nullptr;
    PizzaIngredientFactory* inf = new NYPIF;

    if (item == "cheese") {
        pizza = new CheesePizza(inf);
        pizza->setName("���� ġ�� ����");
    }

    return pizza;
}
