#pragma once
#include <iostream>
#include <string>

using namespace std;

class Light
{
	string place;
public:
	Light(string place) { this->place = place; }
	void on() { cout << this->place << " ������ �������ϴ�" << endl; };
	void off() { cout << this->place << " ������ �������ϴ�" << endl; };
};

class GarageDoor
{
	string place;
public:
	GarageDoor(string place) { this->place = place; }
	void up() { cout << "���� ���� �����ϴ�" << endl; }
	void down() { cout << "���� ���� �����ϴ�" << endl; }
	void stop() { cout << "���� ���� ����ϴ�" << endl; }
	void lightOn() { cout << "���� ������ �������ϴ�" << endl; }
	void lightOff() { cout << "���� ������ �������ϴ�" << endl; }
};

class Stereo
{
	string place;
public:
	Stereo(string place) { this->place = place; }
	void on() { cout << "������� �������ϴ�" << endl; }
	void off() { cout << "������� �������ϴ�" << endl; }
	void setCd() { cout << "CD�� ����˴ϴ�" << endl; }
	void setDvd() { cout << "DVD�� ����˴ϴ�" << endl; }
	void setRadio() { cout << "Radio�� ����˴ϴ�" << endl; }
	void setVolume(int sound) { cout << "ũ�Ⱑ " << sound << "�� �����Ǿ����ϴ�" << endl; }
};