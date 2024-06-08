#include "NYPizzaStore.h"
#include "NYPIF.h"
#include "CheesePizza.h"

Pizza* NYPizzaStore::createPizza(std::string item)
{
    Pizza* pizza = nullptr;
    PizzaIngredientFactory* inf = new NYPIF;

    if (item == "cheese") {
        pizza = new CheesePizza(inf);
        pizza->setName("뉴욕 치즈 피자");
    }

    return pizza;
}
