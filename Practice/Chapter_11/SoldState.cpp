#include "SoldState.h"

using namespace std;

SoldState::SoldState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
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
		cout << "�˸��̸� �����մϴ�." << endl;
		// ����
		gumballmachine->refill(5);
		gumballmachine->setState(gumballmachine->getNoQuarterState());
	}
}
