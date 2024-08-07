#pragma once
#include <vector>
#include "MenuItem.h"

class Iterator;

class PancakeHouseMenu
{
private:
	std::vector<MenuItem*> menuItems;
public:
	PancakeHouseMenu();
	void addItem(std::string name, std::string description, bool vegetarian, double price);
	//std::list<MenuItem*> getMenuItems();
	Iterator* createIterator();
};

