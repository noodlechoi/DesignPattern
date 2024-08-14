#include "GumballMachine.h"

using namespace std;

GumballMachine::GumballMachine(int count) : count{count}
{
	if (count > 0) {
		state = NO_QUARTER;
	}
}

void GumballMachine::insertQuarter()
{
	if (state == HAS_QUARTER) {
		cout << "동전은 한 개만 넣어주세요." << endl;
	}
	else if (state == NO_QUARTER) {
		state = HAS_QUARTER;
		cout << "동전을 넣으셨습니다." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "매진 되었습니다. 다음 기회에 이용해주세요." << endl;
	}
	else if (state == SOLD) {
		cout << "알맹이를 내보내고 있습니다." << endl;
	}
}

void GumballMachine::ejectQuarter()
{
	if (state == HAS_QUARTER) {
		cout << "동전이 반환됩니다." << endl;
		state = NO_QUARTER;
	}
	else if (state == NO_QUARTER) {
		cout << "동전을 넣어주세요." << endl;
	}
	else if (state == SOLD) {
		cout << "이미 알갱이를 뽑으셨습니다." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "동전을 넣지 않으셨습니다. 동전이 반환되지 않습니다." << endl;
	}
}

void GumballMachine::turnCrank()
{
	if (state == SOLD) {
		cout << "손잡이는 한 번만 돌려주세요." << endl;
	}
	else if (state == NO_QUARTER) {
		cout << "동전을 넣어주세요." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "매진 되었습니다." << endl;
	}
	else if (state == HAS_QUARTER) {
		cout << "손잡이를 돌리셨습니다." << endl;
		state = SOLD;
		dispense();
	}
}

void GumballMachine::dispense()
{
	if (state == SOLD) {
		cout << "알맹이를 내보내고 있습니다." << endl;
		count--;
		if (count == 0) {
			cout << "더 이상 알맹이가 없습니다." << endl;
			state = SOLD_OUT;
		}
		else {
			state = NO_QUARTER;
		}
	}
	else if (state == NO_QUARTER) {
		cout << "동전을 넣어주세요." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "매진 되었습니다." << endl;
	}
	else if (state == HAS_QUARTER) {
		cout << "알맹이를 내보낼 수 없습니다." << endl;
	}
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
	if (state == SOLD_OUT) {
		cout << "매진\n";
	}
	else if (state == SOLD) {
		cout << "판매중\n";
	}
	else if (state == HAS_QUARTER) {
		cout << "동전 투입중\n";
	}
	else if (state == NO_QUARTER) {
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
