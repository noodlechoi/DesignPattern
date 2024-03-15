#include "Duck.h"
#include <iostream>

using namespace std;

Duck::~Duck()
{
	cout << "Duck �Ҹ���" << endl;
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
	cout << "��� ������ ���� ��ϴ�. ��¥ ������ ����." << endl;
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
