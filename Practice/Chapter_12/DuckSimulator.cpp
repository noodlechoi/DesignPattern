#include "DuckSimulator.h"
#include <iostream>

using namespace std;

DuckSimulator::DuckSimulator(std::unique_ptr<AbstractDuckFactory> duckFactory)
{
	std::unique_ptr<Quackable> redheadDuck = duckFactory->createRedheadDuck();
	std::unique_ptr<Quackable> duckCall = duckFactory->createDuckCall();
	std::unique_ptr<Quackable> rubberDuck = duckFactory->createRubberDuck();
	std::unique_ptr<Quackable> gooseDuck = std::make_unique<GooseAdapter>(make_unique<Goose>());

	flockOfDucks = std::make_unique<Flock>();
	flockOfDucks->add(redheadDuck);
	flockOfDucks->add(duckCall);
	flockOfDucks->add(rubberDuck);
	flockOfDucks->add(gooseDuck);

	flockOfmallards = std::make_unique<Flock>();
	for (int i = 0; i < 4; ++i) {
		std::unique_ptr<Quackable> mallard = duckFactory->createMallardDuck();
		flockOfmallards->add(mallard);
	}
	flockOfDucks->add(std::make_unique<Flock>(*flockOfmallards));
}

void DuckSimulator::simulate()
{
	cout << "\n���� �ùķ��̼� ����: ��ü ����" << endl;
	simulate(*flockOfDucks);

	cout << "\n���� �ùķ��̼� ����: ������ ����" << endl;
	simulate(*flockOfmallards);

	cout << "������ �Ҹ� �� Ƚ��: " << QuackCounter::getQuacks() << endl;
}

void DuckSimulator::simulate(Quackable& duck)
{
	duck.quack();
}
