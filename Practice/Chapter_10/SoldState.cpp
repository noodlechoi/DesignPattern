#include "SoldState.h"
#include <memory>

using namespace std;

SoldState::SoldState(std::unique_ptr<GumballMachine> gumballmachine)
{
	this->gumballmachine = std::move(gumballmachine);
}

void SoldState::insertQuarter()
{
	cout << "�˸��̸� �������� �ֽ��ϴ�." << endl;
}

void SoldState::ejectQuarter()
{
	cout << "�̹� �˰��̸� �����̽��ϴ�." << endl;
}

void SoldState::turnCrank()
{
	cout << "�����̴� �� ���� �����ּ���." << endl;
}

void SoldState::dispense()
{
	gumballmachine->releaseBall();
	if (gumballmachine->getCount() > 0) {
		gumballmachine->setState(gumballmachine->getNoQuarterState());
	}
	else {
		cout << "�̷�, �����Ǿ����ϴ�." << endl;
		gumballmachine->setState(gumballmachine->getSoldOutState());
	}
}
