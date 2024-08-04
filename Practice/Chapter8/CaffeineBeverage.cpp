#include "CaffeineBeverage.h"
#include <iostream>

using namespace std;

void CaffeineBeverage::prepareRecipe()
{
	boilWater();
	brew();
	pourInCup();
	if(customerWantsCondiments())
		addCondiments();
}

void CaffeineBeverage::boilWater()
{
	cout << "물 끓이는 중" << endl;
}

void CaffeineBeverage::pourInCup()
{
	cout << "컵에 따르는 중" << endl;
}

bool CaffeineBeverage::customerWantsCondiments()
{
	return true;
}
