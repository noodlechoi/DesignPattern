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
	cout << "알맹이를 내보내고 있습니다." << endl;
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
		cout << this->count << "개로 리필되었습니다." << endl;
	}
}

void GumballMachine::printState() const
{
	if (state == soldOutState) {
		cout << "매진\n";
	}
	else if (state == soldState) {
		cout << "판매중\n";
	}
	else if (state == hasQuarterState) {
		cout << "동전 투입중\n";
	}
	else if (state == noQuarterState) {
		cout << "동전 투입 대기중\n";
	}
}

std::ostream& operator<<(std::ostream& out, const GumballMachine& machine)
{
	cout << "주식회사 왕뽑기" << endl;
	cout << "남은 개수: " << machine.getCount() << endl;
	machine.printState();
	cout << "\n";

	return out;
}
