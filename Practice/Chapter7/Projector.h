#pragma once
#include <iostream>
using namespace std;
class StreamingPlayer;

class Projector
{
	StreamingPlayer* player;
public:
	Projector() = default;
	void on() { cout << "�������͸� Ƶ�ϴ�." << endl; }
	void off() { cout << "�������͸� ���ϴ�." << endl; }
	void toString() {}
};
