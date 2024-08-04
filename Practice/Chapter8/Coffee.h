#pragma once
#include "CaffeineBeverage.h"
#include <string>

class Coffee : public CaffeineBeverage
{
private:
	std::string getUserInput();
public:
	void brew() override;
	void addCondiments() override;
	bool customerWantsCondiments() override;
};