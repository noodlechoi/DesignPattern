#include "Duck.h"
#include <iostream>

using namespace std;

void Duck::performFly()
{
	flybh.fly();
}

void Duck::performQuack()
{
	quackbh.quack();
}

void Duck::swim()
{
	cout << "��� ������ ���� ��ϴ�. ��¥ ������ ����." << endl;
}
