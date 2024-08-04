#include "Coffee.h"
#include <iostream>

using namespace std;

std::string Coffee::getUserInput()
{
	cout << "Ŀ�ǿ� ������ ������ ��������?(y/n) ";
	std::string answer;
	try	{
		cin >> answer;
		if (answer != "n" && answer != "y") throw answer;
	}
	catch (const std::exception& e)	{
		return "n";
	}
	return answer;
}

void Coffee::brew()
{
	cout << "���ͷ� Ŀ�Ǹ� ������� ��" << endl;
}

void Coffee::addCondiments()
{
	cout << "������ ������ �߰��ϴ� ��" << endl;
}

bool Coffee::customerWantsCondiments()
{
	string answer = getUserInput();

	if (answer == "y") {
		return true;
	}
	else {
		return false;
	}
}
