#pragma once
#include "StreamingPlayer.h"

class Amplifier
{
	StreamingPlayer* player{};
public:
	Amplifier() = default;
	void on() { cout << "������ ŵ�ϴ�." << endl; }
	void off() { cout << "������ ���ϴ�." << endl; }
	void setStreamingPlayer(StreamingPlayer* player) { cout << "������ ��Ʈ���� �÷��̾�� �����մϴ�." << endl; this->player = player; }
	void setStereoSound() {  }
	void setSurroundSound() { cout << "������ ������ ���� �����մϴ�." << endl; }
	void setTuner() {  }
	void setVolume(int volume) { cout << "������ �Ҹ��� " << volume << "�� �����մϴ�." << endl; }
	void toString() {}
};