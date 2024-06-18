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
	void dim() { cout << this->place << " ������ ��ο������ϴ�" << endl; }
};

class TV
{
	string place;
public:
	TV(string place) { this->place = place; }
	void on() { cout << this->place << "TV�� �������ϴ�" << endl; };
	void off() { cout << this->place << "TV�� �������ϴ�" << endl; };
	void setInputChannel(int num) { cout << num << "ä�η� �̵��߽��ϴ�" << endl; }
	void setVolume(int sound) { cout << "ũ�Ⱑ " << sound << "�� �����Ǿ����ϴ�" << endl; }
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

class CeilingFan
{
public:
	static enum speeds
	{
		OFF,
		LOW,
		MEDIUM,
		HIGH,
	};
	string place;
	int nowSpeed;
	CeilingFan(string place)
	{
		this->place = place;
		nowSpeed = OFF;
	}

	void high()
	{
		nowSpeed = HIGH;
		cout << "�ӵ��� HIGH�� �����Ǿ����ϴ�" << endl;
	}

	void medium()
	{
		nowSpeed = MEDIUM;
		cout << "�ӵ��� MEDIUM�� �����Ǿ����ϴ�" << endl;
	}

	void low()
	{
		nowSpeed = LOW;
		cout << "�ӵ��� LOW�� �����Ǿ����ϴ�" << endl;
	}

	void off()
	{
		nowSpeed = OFF;
		cout << "��ǳ�Ⱑ ����Ǿ����ϴ�" << endl;
	}

	int getSpeed()
	{
		return nowSpeed;
	}
};