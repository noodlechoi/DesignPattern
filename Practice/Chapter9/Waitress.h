#pragma once
#include "PancakeHouseMenu.h"
#include "DinnerMenu.h"
#include "PancakeHouseIterator.h"
#include "DinnerMenuIterator.h"

class Waitress
{
private:
	PancakeHouseMenu* pancakeHouseMenu{};
	DinnerMenu* dinnerMenu;
	void printMenu(Iterator* iterator);
public:
	Waitress(PancakeHouseMenu* pancake, DinnerMenu* dinner);
	void printMenu();
};

