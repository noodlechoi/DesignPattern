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