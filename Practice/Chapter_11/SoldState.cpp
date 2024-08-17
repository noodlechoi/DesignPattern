#include "SoldState.h"

using namespace std;

SoldState::SoldState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void SoldState::insertQuarter()
{
	cout << "알맹이를 내보내고 있습니다." << endl;
}

void SoldState::ejectQuarter()
{
	cout << "이미 알갱이를 뽑으셨습니다." << endl;
}

void SoldState::turnCrank()
{
	cout << "손잡이는 한 번만 돌려주세요." << endl;
}

void SoldState::dispense()
{
	gumballmachine->releaseBall();
	if (gumballmachine->getCount() > 0) {
		gumballmachine->setState(gumballmachine->getNoQuarterState());
	}
	else {
		cout << "이런, 매진되었습니다." << endl;
		gumballmachine->setState(gumballmachine->getSoldOutState());
		cout << "알맹이를 리필합니다." << endl;
		// 리필
		gumballmachine->refill(5);
		gumballmachine->setState(gumballmachine->getNoQuarterState());
	}
}
