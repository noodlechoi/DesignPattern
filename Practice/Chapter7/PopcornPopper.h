#pragma once
#include <iostream>
using namespace std;

class PopcornPopper
{
public:
	PopcornPopper() = default;
	void on() { cout << "���� ��踦 ŵ�ϴ�." << endl; }
	void off() { cout << "���� ��踦 ���ϴ�." << endl; }
	void pop() { cout << "������ ����ϴ�." << endl; }
	void toString() {}
};