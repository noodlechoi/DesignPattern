#include "WinnerState.h"
using namespace std;

WinnerState::WinnerState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void WinnerState::insertQuarter()
{
	cout << "알맹이를 내보내고 있습니다." << endl;
}

void WinnerState::ejectQuarter()
{
	cout << "이미 알갱이를 뽑으셨습니다." << endl;
}

void WinnerState::turnCrank()
{
	cout << "손잡이는 한 번만 돌려주세요." << endl;
}

void WinnerState::dispense()
{
	gumballmachine->releaseBall();
	if (gumballmachine->getCount() == 0) {
		gumballmachine->setState(gumballmachine->getSoldOutState());
	}
	else {
		gumballmachine->releaseBall();
		cout << "축하드립니다. 추가 알맹이를 받을 수 있습니다." << endl;
		if (gumballmachine->getCount() > 0) {
			gumballmachine->setState(gumballmachine->getNoQuarterState());
		}
		else {
			cout << "더 이상 알맹이가 없습니다." << endl;
			gumballmachine->setState(gumballmachine->getSoldOutState());
		}
	}
}
