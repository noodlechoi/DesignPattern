#include "SoldOutState.h"

using namespace std;


SoldOutState::SoldOutState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void SoldOutState::insertQuarter()
{
	cout << "매진 되었습니다. 다음 기회에 이용해주세요." << endl;
}

void SoldOutState::ejectQuarter()
{
	cout << "동전을 넣지 않으셨습니다. 동전이 반환되지 않습니다." << endl;
}

void SoldOutState::turnCrank()
{
	cout << "매진 되었습니다." << endl;
}

void SoldOutState::dispense()
{
	cout << "매진 되었습니다." << endl;
}
