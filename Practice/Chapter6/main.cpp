#include "Command.h"

int main()
{
	SimpleRemoteControl* remote = new SimpleRemoteControl;	// �κ�Ŀ
	Light* light = new Light;								// ���ù�
	GarageDoor* garageDoor = new GarageDoor;
	LightONCommand* lightOn = new LightONCommand(light);	// ���ù��� Ŀ�ǵ� ��ü�� ����
	GarageDoorOpenCommand* garageOpen = new GarageDoorOpenCommand(garageDoor);

	remote->setCommand(lightOn);							// �κ�Ŀ�� Ŀ�ǵ� ��ü ����
	remote->buttonWasPressed();								// execute ����
	remote->setCommand(garageOpen);
	remote->buttonWasPressed();
}