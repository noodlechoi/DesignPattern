#include "DuckSimulator.h"
#include <iostream>

using namespace std;

DuckSimulator::DuckSimulator()
{
	mallardDuck = std::make_unique<QuackCounter>(std::make_unique<MallardDuck>());
	redheadDuck = std::make_unique<QuackCounter>(std::make_unique<RedheadDuck>());
	duckCall = std::make_unique<QuackCounter>(std::make_unique<DuckCall>());
	rubberDuck = std::make_unique<QuackCounter>(std::make_unique<RubberDuck>());
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
