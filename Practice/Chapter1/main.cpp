#include "MallardDuck.h"
#include "FlyNoWay.h"
#include "MuteQuack.h"

int main()
{
	Duck* mallard1 = new MallardDuck;
	mallard1->performQuack();
	mallard1->performFly();

	delete mallard1;

	Duck* mallard2 = new MallardDuck;
	mallard2->performQuack();
	mallard2->performFly();

	// º¯°æ
	mallard2->setQuackBH(new MuteQuack);
	mallard2->setFlyBH(new FlyNoWay);

	mallard2->performQuack();
	mallard2->performFly();

	delete mallard2;
}