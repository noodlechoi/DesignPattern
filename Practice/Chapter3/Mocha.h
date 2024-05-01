#pragma once
#include "CondimentDecorator.h"

// 데코레이터기 때문에 CondimentDecorator 확장
class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage);
	std::string getDescription() override;
	double cost() override;
};

