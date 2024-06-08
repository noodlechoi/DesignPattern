#include "Pizza.h"
#include <iostream>

using namespace std;

void Pizza::bake()
{
	cout << "175도에서 25분 동안 굽기" << endl;
}

void Pizza::cut()
{
	cout << "피자를 사선으로 자르기" << endl;
}

void Pizza::box()
{
	cout << "상자에 피자 담기" << endl;
}

void Pizza::setName(string name)
{
	this->name = name;
}

std::string Pizza::toString()
{
	return this->name;
}
