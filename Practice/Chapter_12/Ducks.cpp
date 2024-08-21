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
	this->goose = std::move(goose);
}

void GooseAdapter::quack()
{
	goose->honk();
}

int QuackCounter::number = 0;

QuackCounter::QuackCounter(std::unique_ptr<Quackable> duck)
{
	this->duck = std::move(duck);
}

void QuackCounter::quack()
{
	duck->quack();
	number++;
}