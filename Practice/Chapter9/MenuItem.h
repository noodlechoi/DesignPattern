#pragma once
#include <string>

class MenuItem
{
private:
	std::string name;
	std::string description;
	bool vegetarian;
	double price;
public:
	MenuItem(std::string name, std::string description,	bool vegetarian, double price) 
		: name{name}, description{description}, vegetarian{vegetarian}, price{price} {}

	std::string getName() { return name; }
	std::string getDescription() { return description; }
	double getPrice() { return price; }
	bool isVegetarian() { return vegetarian; }
};