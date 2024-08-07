#pragma once
#include <list>
#include "MenuItem.h"

class PancakeHouseMenu
{
private:
	std::list<MenuItem*> menuItems;
public:
	PancakeHouseMenu();
	void addItem(std::string name, std::string description, bool vegetarian, double price);
	std::list<MenuItem*> getMenuItems();
};

