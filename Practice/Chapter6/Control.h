#pragma once
#include <iostream>
#include <string>

using namespace std;

class Light
{
	string place;
public:
	Light(string place) { this->place = place; }
	void on() { cout << this->place << " 조명이 켜졌습니다" << endl; };
	void off() { cout << this->place << " 조명이 꺼졌습니다" << endl; };
	void dim() { cout << this->place << " 조명이 어두워졌습니다" << endl; }
};

class TV
{
	string place;
public:
	TV(string place) { this->place = place; }
	void on() { cout << this->place << "TV가 켜졌습니다" << endl; };
	void off() { cout << this->place << "TV가 꺼졌습니다" << endl; };
	void setInputChannel(int num) { cout << num << "채널로 이동했습니다" << endl; }
	void setVolume(int sound) { cout << "크기가 " << sound << "로 설정되었습니다" << endl; }
};

class GarageDoor
{
	string place;
public:
	GarageDoor(string place) { this->place = place; }
	void up() { cout << "차고 문이 열립니다" << endl; }
	void down() { cout << "차고 문이 닫힙니다" << endl; }
	void stop() { cout << "차고 문이 멈춥니다" << endl; }
	void lightOn() { cout << "차고 조명이 켜졌습니다" << endl; }
	void lightOff() { cout << "차고 조명이 꺼졌습니다" << endl; }
};

class Stereo
{
	string place;
public:
	Stereo(string place) { this->place = place; }
	void on() { cout << "오디오가 켜졌습니다" << endl; }
	void off() { cout << "오디오가 켜졌습니다" << endl; }
	void setCd() { cout << "CD가 재생됩니다" << endl; }
	void setDvd() { cout << "DVD가 재생됩니다" << endl; }
	void setRadio() { cout << "Radio가 재생됩니다" << endl; }
	void setVolume(int sound) { cout << "크기가 " << sound << "로 설정되었습니다" << endl; }
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
		cout << "속도가 HIGH로 설정되었습니다" << endl;
	}

	void medium()
	{
		nowSpeed = MEDIUM;
		cout << "속도가 MEDIUM로 설정되었습니다" << endl;
	}

	void low()
	{
		nowSpeed = LOW;
		cout << "속도가 LOW로 설정되었습니다" << endl;
	}

	void off()
	{
		nowSpeed = OFF;
		cout << "선풍기가 종료되었습니다" << endl;
	}

	int getSpeed()
	{
		return nowSpeed;
	}
};