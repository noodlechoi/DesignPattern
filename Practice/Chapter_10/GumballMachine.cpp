#include "NoQuarterState.h"
//#include "HasQuarterState.h"
//#include "SoldOutState.h"
//#include "SoldState.h"
#include "GumballMachine.h"
#include <memory>

using namespace std;

GumballMachine::GumballMachine(int count) : count{count}
{
	noQuarterState = std::make_shared<NoQuarterState>(this);
	/*hasQuarterState = std::make_shared<HasQuarterState>(this);
	soldOutState = std::make_shared<SoldOutState>(this);
	soldState = std::make_shared<SoldState>(this);*/

	if (this->count > 0) {
		state = noQuarterState;
	}
	else {
		state = soldOutState;
	}
}

void GumballMachine::insertQuarter()
{
	state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
	state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
	state->turnCrank();
	state->dispense();
}

void GumballMachine::setState(std::shared_ptr<State> state)
{
	this->state = state;
}

void GumballMachine::releaseBall()
{
	cout << "�˸��̸� �������� �ֽ��ϴ�." << endl;
	if (count > 0) {
		count--;
	}
}

std::shared_ptr<State> GumballMachine::getNoQuarterState()
{
	return noQuarterState;
}

std::shared_ptr<State> GumballMachine::getHasQuarterState()
{
	return hasQuarterState;
}

std::shared_ptr<State> GumballMachine::getSoldOutState()
{
	return soldOutState;
}

std::shared_ptr<State> GumballMachine::getSoldState()
{
	return soldState;
}

void GumballMachine::refill(int count)
{
	if (this->count <= 0) {
		this->count = count;
		cout << this->count << "���� ���ʵǾ����ϴ�." << endl;
	}
}

void GumballMachine::printState() const
{
	if (state == soldOutState) {
		cout << "����\n";
	}
	else if (state == soldState) {
		cout << "�Ǹ���\n";
	}
	else if (state == hasQuarterState) {
		cout << "���� ������\n";
	}
	else if (state == noQuarterState) {
		cout << "���� ���� �����\n";
	}
}

std::ostream& operator<<(std::ostream& out, const GumballMachine& machine)
{
	cout << "�ֽ�ȸ�� �ջ̱�" << endl;
	cout << "���� ����: " << machine.getCount() << endl;
	machine.printState();
	cout << "\n";

	return out;
}
