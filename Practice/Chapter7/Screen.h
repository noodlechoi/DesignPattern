#pragma once
#include <iostream>
using namespace std;

class Screen
{
public:
	Screen() = default;
	void up() { cout << "��ũ���� �ö󰩴ϴ�." << endl; }
	void down() { cout << "��ũ���� �������ϴ�." << endl; }
	void toString() {}
};