#include "Ducks.h"
#include <iostream>

using namespace std;

void MallardDuck::quack()
{
	cout << "�в�" << endl;
}

void RedheadDuck::quack()
{
	cout << "�в�" << endl;
}

void DuckCall::quack()
{
	cout << "�˲�" << endl;
}

void RubberDuck::quack()
{
	cout << "���" << endl;
}

void Goose::honk()
{
	cout << "����" << endl;
}

GooseAdapter::GooseAdapter(std::unique_ptr<Goose> goose)
{
	goose = std::move(goose);
}

void GooseAdapter::quack()
{
	goose->honk();
}
