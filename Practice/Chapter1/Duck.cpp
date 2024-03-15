#include "Duck.h"
#include <iostream>

using namespace std;

Duck::~Duck()
{
	cout << "Duck 소멸자" << endl;
	if (flybh) {
		delete flybh;
	}
	if (quackbh) {
		delete quackbh;
	}
}

void Duck::performFly()
{
	flybh->fly();
}

void Duck::performQuack()
{
	quackbh->quack();
}

void Duck::swim()
{
	cout << "모든 오리는 물에 뜹니다. 가짜 오리도 뜨죠." << endl;
}

void Duck::setFlyBH(FlyBH* fb)
{
	if (flybh) {
		delete flybh;
	}

	flybh = fb;
}

void Duck::setQuackBH(QuackBH* qb)
{
	if (quackbh) {
		delete quackbh;
	}

	quackbh = qb;
}
