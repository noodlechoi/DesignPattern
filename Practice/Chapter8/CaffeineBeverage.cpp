#include "CaffeineBeverage.h"
#include <iostream>

using namespace std;

void CaffeineBeverage::prepareRecipe()
{
	boilWater();
	brew();
	pourInCup();
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
