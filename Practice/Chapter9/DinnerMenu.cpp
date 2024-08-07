#include "DinnerMenu.h"
#include "DinnerMenuIterator.h"
#include <iostream>

DinnerMenu::DinnerMenu()
{
	menuItems = new MenuItem*[MAX_ITEMS];

}

void DinnerMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
	MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
	if (numberOfItems >= MAX_ITEMS) {
		std::cout << "�޴��� ���� á���ϴ�." << std::endl;
	}
	else {
		menuItems[numberOfItems] = menuItem;
		numberOfItems++;
	}
}

Iterator* DinnerMenu::createIterator()
{
	return new DinnerMenuIterator(menuItems);
}

//MenuItem** DinnerMenu::getMenuItems()
//{
//	return menuItems;
//}
