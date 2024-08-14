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
		cout << "������ �� ���� �־��ּ���." << endl;
	}
	else if (state == NO_QUARTER) {
		state = HAS_QUARTER;
		cout << "������ �����̽��ϴ�." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "���� �Ǿ����ϴ�. ���� ��ȸ�� �̿����ּ���." << endl;
	}
	else if (state == SOLD) {
		cout << "�˸��̸� �������� �ֽ��ϴ�." << endl;
	}
}

void GumballMachine::ejectQuarter()
{
	if (state == HAS_QUARTER) {
		cout << "������ ��ȯ�˴ϴ�." << endl;
		state = NO_QUARTER;
	}
	else if (state == NO_QUARTER) {
		cout << "������ �־��ּ���." << endl;
	}
	else if (state == SOLD) {
		cout << "�̹� �˰��̸� �����̽��ϴ�." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "������ ���� �����̽��ϴ�. ������ ��ȯ���� �ʽ��ϴ�." << endl;
	}
}

void GumballMachine::turnCrank()
{
	if (state == SOLD) {
		cout << "�����̴� �� ���� �����ּ���." << endl;
	}
	else if (state == NO_QUARTER) {
		cout << "������ �־��ּ���." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "���� �Ǿ����ϴ�." << endl;
	}
	else if (state == HAS_QUARTER) {
		cout << "�����̸� �����̽��ϴ�." << endl;
		state = SOLD;
		dispense();
	}
}

void GumballMachine::dispense()
{
	if (state == SOLD) {
		cout << "�˸��̸� �������� �ֽ��ϴ�." << endl;
		count--;
		if (count == 0) {
			cout << "�� �̻� �˸��̰� �����ϴ�." << endl;
			state = SOLD_OUT;
		}
		else {
			state = NO_QUARTER;
		}
	}
	else if (state == NO_QUARTER) {
		cout << "������ �־��ּ���." << endl;
	}
	else if (state == SOLD_OUT) {
		cout << "���� �Ǿ����ϴ�." << endl;
	}
	else if (state == HAS_QUARTER) {
		cout << "�˸��̸� ������ �� �����ϴ�." << endl;
	}
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
	if (state == SOLD_OUT) {
		cout << "����\n";
	}
	else if (state == SOLD) {
		cout << "�Ǹ���\n";
	}
	else if (state == HAS_QUARTER) {
		cout << "���� ������\n";
	}
	else if (state == NO_QUARTER) {
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
