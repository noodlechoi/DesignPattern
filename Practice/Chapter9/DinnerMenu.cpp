#include "DinnerMenu.h"
#include <iostream>

DinnerMenu::DinnerMenu()
{
	menuItems = new MenuItem*[MAX_ITEMS];

}

void DinnerMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
	MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
	if (numberOfItems >= MAX_ITEMS) {
		std::cout << "¸Þ´º°¡ °¡µæ Ã¡½À´Ï´Ù." << std::endl;
	}
	else {
		menuItems[numberOfItems] = menuItem;
		numberOfItems++;
	}
}

MenuItem** DinnerMenu::getMenuItems()
{
	return menuItems;
}
