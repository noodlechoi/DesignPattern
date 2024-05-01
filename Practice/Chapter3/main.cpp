#include <iostream>
#include "DarkRoast.h"
#include "Espresso.h"
#include "HouseBlend.h"
#include "Mocha.h"
#include "Soy.h"
#include "Whip.h"

using namespace std;

int main()
{
	Beverage* b1 = new Espresso();
	cout << b1->getDescription() + " $" + to_string(b1->cost()) << endl;

	Beverage* b2 = new DarkRoast();
	// °¨½Î±â
	b2 = new Mocha(b2);
	b2 = new Mocha(b2);
	b2 = new Whip(b2);
	cout << b2->getDescription() + " $" + to_string(b2->cost());

}
