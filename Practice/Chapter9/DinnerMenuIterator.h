#pragma once
#include "Iterator.h"
#include "MenuItem.h"

class DinnerMenuIterator : public Iterator
{
private:
	MenuItem** items;
	int position{};
public:
	DinnerMenuIterator(MenuItem** items) {
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
		if (position >= 4 || items[position] == nullptr)
			return false;
		else
			return true;
	}
};