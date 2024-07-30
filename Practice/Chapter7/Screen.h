#pragma once
#include <iostream>
using namespace std;

class Screen
{
public:
	Screen() = default;
	void up() { cout << "스크린이 올라갑니다." << endl; }
	void down() { cout << "스크린이 내려갑니다." << endl; }
	void toString() {}
};