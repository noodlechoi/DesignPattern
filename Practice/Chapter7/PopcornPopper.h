#pragma once
#include <iostream>
using namespace std;

class PopcornPopper
{
public:
	PopcornPopper() = default;
	void on() { cout << "ÆËÄÜ ±â°è¸¦ Åµ´Ï´Ù." << endl; }
	void off() { cout << "ÆËÄÜ ±â°è¸¦ ²ü´Ï´Ù." << endl; }
	void pop() { cout << "ÆËÄÜÀ» ¸¸µì´Ï´Ù." << endl; }
	void toString() {}
};