#include "MallardDuck.h"

int main()
{
	Duck* mallard = new MallardDuck;
	mallard->performQuack();
	mallard->performFly();
}