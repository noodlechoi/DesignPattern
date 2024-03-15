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
	cout << "모든 오리는 물에 뜹니다. 가짜 오리도 뜨죠." << endl;
}
