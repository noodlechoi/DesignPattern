#pragma once
class CaffeineBeverage
{
public:
	virtual void prepareRecipe() final;
	virtual void brew() = 0;
	virtual void addCondiments() = 0;
	void boilWater();
	void pourInCup();
};

