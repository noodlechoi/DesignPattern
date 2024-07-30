#pragma once
#include "Projector.h"
class Amplifier;

class StreamingPlayer
{
	Amplifier* amplifier;
public:
	StreamingPlayer() = default;
	void on() { cout << "스트리밍 플레이어를 틉니다." << endl; }
	void off() { cout << "스트리밍 플레이어를 끕니다." << endl; }
	void play(string movie) { cout << "스트리밍 플레이어에서 " << movie << "를 재생합니다." << endl; }
	void toString() {}
};