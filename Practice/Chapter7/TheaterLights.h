#pragma once
#include <iostream>
using namespace std;

class TheaterLights
{
public:
	TheaterLights() = default;
	void on() { cout << "���� ŵ�ϴ�." << endl; }
	void off() { cout << "���� ���ϴ�." << endl; }
	void dim(int level) { cout << "��⸦ " << level << "�� �����մϴ�." << endl; }
	void toString() {}
};