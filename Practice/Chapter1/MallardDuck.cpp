#include "MallardDuck.h"
#include "FlyWithWings.h"
#include "Quack.h"
#include <iostream>
using namespace std;

MallardDuck::MallardDuck() : Duck()
{
	flybh = new FlyWithWings;
	quackbh = new Quack;
}

void MallardDuck::display()
{
	cout << "저는 물오리입니다." << endl;
}
