#pragma once
#include "Projector.h"
class Amplifier;

class StreamingPlayer
{
	Amplifier* amplifier;
public:
	StreamingPlayer() = default;
	void on() { cout << "��Ʈ���� �÷��̾ Ƶ�ϴ�." << endl; }
	void off() { cout << "��Ʈ���� �÷��̾ ���ϴ�." << endl; }
	void play(string movie) { cout << "��Ʈ���� �÷��̾�� " << movie << "�� ����մϴ�." << endl; }
	void toString() {}
};