#include "Coffee.h"
#include "Tea.h"
#include <iostream>

using namespace std;

int main()
{
	Tea* tea = new Tea;
	Coffee* coffee = new Coffee;

	cout << "ȫ�� �غ� ��" << endl;
	tea->prepareRecipe();

	cout << endl;

	cout << "Ŀ�� �غ� ��" << endl;
	coffee->prepareRecipe();
}