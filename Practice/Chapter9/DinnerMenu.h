#pragma once
#include "MenuItem.h"

class Iterator;

class DinnerMenu
{
private:
	static const int MAX_ITEMS{6};
	int numberOfItems{};
	MenuItem** menuItems{};
public:
	DinnerMenu();
	void addItem(std::string name, std::string description, bool vegetarian, double price);
	//MenuItem** getMenuItems();
	Iterator* createIterator();
};

