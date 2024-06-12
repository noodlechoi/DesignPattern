#include "Command.h"

int main()
{
	SimpleRemoteControl* remote = new SimpleRemoteControl;	// �κ�Ŀ
	Light* light = new Light;								// ���ù�
	LightONCommand* lightOn = new LightONCommand(light);	// ���ù��� Ŀ�ǵ� ��ü�� ����

	remote->setCommand(lightOn);							// �κ�Ŀ�� Ŀ�ǵ� ��ü ����
	remote->buttonWasPressed();								// execute ����
}