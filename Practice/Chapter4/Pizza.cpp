#include "Pizza.h"
#include <iostream>

using namespace std;

void Pizza::bake()
{
	cout << "175������ 25�� ���� ����" << endl;
}

void Pizza::cut()
{
	cout << "���ڸ� �缱���� �ڸ���" << endl;
}

void Pizza::box()
{
	cout << "���ڿ� ���� ���" << endl;
}

void Pizza::setName(string name)
{
	this->name = name;
}

std::string Pizza::toString()
{
	return this->name;
}
