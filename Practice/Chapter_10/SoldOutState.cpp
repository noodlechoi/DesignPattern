#include "SoldOutState.h"

using namespace std;


SoldOutState::SoldOutState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void SoldOutState::insertQuarter()
{
	cout << "���� �Ǿ����ϴ�. ���� ��ȸ�� �̿����ּ���." << endl;
}

void SoldOutState::ejectQuarter()
{
	cout << "������ ���� �����̽��ϴ�. ������ ��ȯ���� �ʽ��ϴ�." << endl;
}

void SoldOutState::turnCrank()
{
	cout << "���� �Ǿ����ϴ�." << endl;
}

void SoldOutState::dispense()
{
	cout << "���� �Ǿ����ϴ�." << endl;
}
