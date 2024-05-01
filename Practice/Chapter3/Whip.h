#pragma once
#include "CondimentDecorator.h"

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* beverage);
	std::string getDescription() override;
	double cost() override;
};

