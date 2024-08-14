#include "WinnerState.h"
using namespace std;

WinnerState::WinnerState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void WinnerState::insertQuarter()
{
	cout << "�˸��̸� �������� �ֽ��ϴ�." << endl;
}

void WinnerState::ejectQuarter()
{
	cout << "�̹� �˰��̸� �����̽��ϴ�." << endl;
}

void WinnerState::turnCrank()
{
	cout << "�����̴� �� ���� �����ּ���." << endl;
}

void WinnerState::dispense()
{
	gumballmachine->releaseBall();
	if (gumballmachine->getCount() == 0) {
		gumballmachine->setState(gumballmachine->getSoldOutState());
	}
	else {
		gumballmachine->releaseBall();
		cout << "���ϵ帳�ϴ�. �߰� �˸��̸� ���� �� �ֽ��ϴ�." << endl;
		if (gumballmachine->getCount() > 0) {
			gumballmachine->setState(gumballmachine->getNoQuarterState());
		}
		else {
			cout << "�� �̻� �˸��̰� �����ϴ�." << endl;
			gumballmachine->setState(gumballmachine->getSoldOutState());
		}
	}
}
