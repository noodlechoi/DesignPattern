#pragma once
#include <iostream>

using namespace std;

class Light
{
public:
	void on() { cout << "������ �������ϴ�" << endl; };
	void off() { cout << "������ �������ϴ�" << endl; };
};

class GarageDoor
{
public:
	void up() { cout << "���� ���� �����ϴ�" << endl; }
	void down() { cout << "���� ���� �����ϴ�" << endl; }
	void stop() { cout << "���� ���� ����ϴ�" << endl; }
	void lightOn() { cout << "���� ������ �������ϴ�" << endl; }
	void lightOff() { cout << "���� ������ �������ϴ�" << endl; }
};