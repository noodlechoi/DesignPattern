#pragma once
#include "CaffeineBeverage.h"

class Tea : public CaffeineBeverage
{
public:
	void brew() override;
	void addCondiments() override;
};

