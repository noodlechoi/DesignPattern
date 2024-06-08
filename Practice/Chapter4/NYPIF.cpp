#include "NYPIF.h"

Dough* NYPIF::createDough()
{
    return new ThinCrustDough;
}

Sauce* NYPIF::createSauce()
{
    return new MarinaraSauce;
}

std::vector<Veggies*> NYPIF::createVeggies()
{
    std::vector<Veggies*> veggies;
    veggies.push_back(new Garlic);
    veggies.push_back(new Onion);
    return veggies;
}

Cheese* NYPIF::createCheese()
{
    return new ReggianoCheese;
}

Pepperoni* NYPIF::createPepperoni()
{
    return new SlicedPepperoni;
}

Clams* NYPIF::createClams()
{
    return new FreshClams;
}
