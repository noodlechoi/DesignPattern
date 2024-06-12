#pragma once
#include <iostream>

using namespace std;

class Light
{
public:
	void on() { cout << "조명이 켜졌습니다" << endl; };
	void off() { cout << "조명이 꺼졌습니다" << endl; };
};