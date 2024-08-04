#include "Coffee.h"
#include "Tea.h"
#include <iostream>

using namespace std;

int main()
{
	Tea* tea = new Tea;
	Coffee* coffee = new Coffee;

	cout << "홍차 준비 중" << endl;
	tea->prepareRecipe();

	cout << endl;

	cout << "커피 준비 중" << endl;
	coffee->prepareRecipe();
}