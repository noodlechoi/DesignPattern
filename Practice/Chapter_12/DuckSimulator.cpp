#include "DuckSimulator.h"
#include <iostream>

using namespace std;

DuckSimulator::DuckSimulator(std::unique_ptr<AbstractDuckFactory> duckFactory)
{
	mallardDuck = duckFactory->createMallardDuck();
	redheadDuck = duckFactory->createRedheadDuck();
	duckCall = duckFactory->createDuckCall();
	rubberDuck = duckFactory->createRubberDuck();
	gooseDuck = std::make_unique<GooseAdapter>(make_unique<Goose>());
}

void DuckSimulator::simulate()
{
	cout << "\n���� �ùķ��̼� ����" << endl;

	simulate(mallardDuck);
	simulate(redheadDuck);
	simulate(duckCall);
	simulate(rubberDuck);
	simulate(gooseDuck);

	cout << "������ �Ҹ� �� Ƚ��: " << QuackCounter::getQuacks() << endl;
}

void DuckSimulator::simulate(std::unique_ptr<Quackable>& duck)
{
	duck->quack();
}
