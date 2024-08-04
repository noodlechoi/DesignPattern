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
	cout << "�� ���̴� ��" << endl;
}

void CaffeineBeverage::pourInCup()
{
	cout << "�ſ� ������ ��" << endl;
}

bool CaffeineBeverage::customerWantsCondiments()
{
	return true;
}
