#pragma once
#include "Iterator.h"
#include "MenuItem.h"
#include <vector>

class PanCakeHouseIterator : public Iterator
{
private:
	std::vector<MenuItem*>  items;
	int position{};
public:
	PanCakeHouseIterator(std::vector<MenuItem*> items) {
		this->items = items;
	}

	MenuItem* next() override
	{
		MenuItem* menuItem = items[position];
		position++;
		return menuItem;
	}

	bool hasNext()
	{
		if (items[position] == NULL)
			return false;
		else
			return true;
	}
};