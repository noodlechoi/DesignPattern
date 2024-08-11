#include "Waitress.h"
#include <iostream>

using namespace std;

void Waitress::printMenu(Iterator* iterator)
{
	while (iterator->hasNext()) {
		MenuItem* menuItem = iterator->next();
		cout << menuItem->getName() << ", ";
		cout << menuItem->getPrice() << " -- ";
		cout << menuItem->getDescription() << endl;
	}
}

Waitress::Waitress(PancakeHouseMenu* pancake, DinnerMenu* dinner)
{
	this->pancakeHouseMenu = pancake;
	this->dinnerMenu = dinner;
}

void Waitress::printMenu()
{
	Iterator* pancakeIterator = pancakeHouseMenu->createIterator();
	Iterator* dinnerIterator = dinnerMenu->createIterator();

	cout << "�޴�\n----\n��ħ �޴�" << endl;
	printMenu(pancakeIterator);
	cout << "\n���� �޴�" << endl;
	printMenu(dinnerIterator);
}
