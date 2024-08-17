#include "HasQuarterState.h"

using namespace std;

HasQuarterState::HasQuarterState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
	randomWinner = new Random;
}

void HasQuarterState::insertQuarter()
{
	cout << "동전은 한 개만 넣어주세요." << endl;
}

void HasQuarterState::ejectQuarter()
{
	cout << "동전이 반환됩니다." << endl;
}

void HasQuarterState::turnCrank()
{
	cout << "손잡이를 돌리셨습니다." << endl;
	int winner = randomWinner->getInt(0, 11);
	if ((winner == 1) && gumballmachine->getCount() > 1) {
		gumballmachine->setState(gumballmachine->getWinnerState());
	}
	else {
		gumballmachine->setState(gumballmachine->getSoldState());
	}
}

void HasQuarterState::dispense()
{
	cout << "알맹이를 내보낼 수 없습니다." << endl;
}
