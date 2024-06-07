#pragma once
#include <string>
#include <vector>

class Pizza
{
private:
	std::string name;
	/*Dough dough;
	Sauce sauce;
	std::vector<Veggies> veggies;
	Cheese cheese;
	Pepperoni pepperoni;
	Clams clam;*/
public:
	virtual void prepare() = 0;
	
	void bake();
	void cut();
	void box();
	void setName(std::string name);
	std::string getName() { return name; }
	std::string toString();
};

