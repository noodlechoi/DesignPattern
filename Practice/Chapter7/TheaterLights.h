#pragma once
#include <iostream>
using namespace std;

class TheaterLights
{
public:
	TheaterLights() = default;
	void on() { cout << "불을 킵니다." << endl; }
	void off() { cout << "불을 끕니다." << endl; }
	void dim(int level) { cout << "밝기를 " << level << "로 설정합니다." << endl; }
	void toString() {}
};