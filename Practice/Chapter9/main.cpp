#include "Waitress.h"

int main()
{
	PancakeHouseMenu* pancake = new PancakeHouseMenu;
	DinnerMenu* dinner = new DinnerMenu;

	Waitress* waitress = new Waitress(pancake, dinner);

	waitress->printMenu();
}