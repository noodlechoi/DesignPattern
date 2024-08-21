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
	cout << "\n오리 시뮬레이션 게임" << endl;

	simulate(mallardDuck);
	simulate(redheadDuck);
	simulate(duckCall);
	simulate(rubberDuck);
	simulate(gooseDuck);

	cout << "오리가 소리 낸 횟수: " << QuackCounter::getQuacks() << endl;
}

void DuckSimulator::simulate(std::unique_ptr<Quackable>& duck)
{
	duck->quack();
}
