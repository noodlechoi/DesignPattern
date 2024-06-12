#pragma once
#include <iostream>

using namespace std;

class Light
{
public:
	void on() { cout << "조명이 켜졌습니다" << endl; };
	void off() { cout << "조명이 꺼졌습니다" << endl; };
};

class GarageDoor
{
public:
	void up() { cout << "차고 문이 열립니다" << endl; }
	void down() { cout << "차고 문이 닫힙니다" << endl; }
	void stop() { cout << "차고 문이 멈춥니다" << endl; }
	void lightOn() { cout << "차고 조명이 켜졌습니다" << endl; }
	void lightOff() { cout << "차고 조명이 꺼졌습니다" << endl; }
};