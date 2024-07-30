#pragma once
#include <iostream>
using namespace std;
class StreamingPlayer;

class Projector
{
	StreamingPlayer* player;
public:
	Projector() = default;
	void on() { cout << "프로젝터를 틉니다." << endl; }
	void off() { cout << "프로젝터를 끕니다." << endl; }
	void toString() {}
};
