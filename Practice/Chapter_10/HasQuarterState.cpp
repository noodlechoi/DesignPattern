#include "HasQuarterState.h"
#include <memory>

using namespace std;

HasQuarterState::HasQuarterState(std::unique_ptr<GumballMachine> gumballmachine)
{
	this->gumballmachine = std::move(gumballmachine);
}

void HasQuarterState::insertQuarter()
{
	cout << "������ �� ���� �־��ּ���." << endl;
}

void HasQuarterState::ejectQuarter()
{
	cout << "������ ��ȯ�˴ϴ�." << endl;
}

void HasQuarterState::turnCrank()
{
	cout << "�����̸� �����̽��ϴ�." << endl;
	gumballmachine->setState(gumballmachine->getSoldState());
}

void HasQuarterState::dispense()
{
	cout << "�˸��̸� ������ �� �����ϴ�." << endl;
}
