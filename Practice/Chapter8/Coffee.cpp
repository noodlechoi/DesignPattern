#include "Coffee.h"
#include <iostream>

using namespace std;

std::string Coffee::getUserInput()
{
	cout << "커피에 우유와 설탕을 넣을깝쇼?(y/n) ";
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
	cout << "필터로 커피를 우려내는 중" << endl;
}

void Coffee::addCondiments()
{
	cout << "설탕과 우유를 추가하는 중" << endl;
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
