#pragma once
#include "StreamingPlayer.h"

class Amplifier
{
	StreamingPlayer* player{};
public:
	Amplifier() = default;
	void on() { cout << "앰프를 킵니다." << endl; }
	void off() { cout << "앰프를 끕니다." << endl; }
	void setStreamingPlayer(StreamingPlayer* player) { cout << "앰프를 스트리밍 플레이어와 연결합니다." << endl; this->player = player; }
	void setStereoSound() {  }
	void setSurroundSound() { cout << "앰프를 서라운드 모드로 설정합니다." << endl; }
	void setTuner() {  }
	void setVolume(int volume) { cout << "앰프의 소리를 " << volume << "로 설정합니다." << endl; }
	void toString() {}
};