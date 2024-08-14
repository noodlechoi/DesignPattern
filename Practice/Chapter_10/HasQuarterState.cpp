#include "HasQuarterState.h"
#include <memory>

using namespace std;

HasQuarterState::HasQuarterState(std::unique_ptr<GumballMachine> gumballmachine)
{
	this->gumballmachine = std::move(gumballmachine);
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
	gumballmachine->setState(gumballmachine->getSoldState());
}

void HasQuarterState::dispense()
{
	cout << "알맹이를 내보낼 수 없습니다." << endl;
}
