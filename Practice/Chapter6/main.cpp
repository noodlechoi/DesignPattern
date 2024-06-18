#include "Command.h"

int main()
{
	// ���ù� ��ü ����
	Light* light = new Light("�Ž�");
	TV* tv = new TV("�Ž�");
	Stereo* stereo = new Stereo("�Ž�");

	// Ŀ�ǵ� ��ü ����
	LightONCommand* lightOn = new LightONCommand(light);
	StereoOnWithCDCommand* stereoOn = new StereoOnWithCDCommand(stereo);
	TVOnCommand* tvOn = new TVOnCommand(tv);

	// OFF Ŀ�ǵ�
	LightOffCommand* lightOff= new LightOffCommand(light);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);
	TVOffCommand* tvOff = new TVOffCommand(tv);

	// �迭
	std::vector<Command*> partyOn;
	std::vector<Command*> partyOff;

	partyOn.push_back(lightOn);
	partyOn.push_back(stereoOn);
	partyOn.push_back(tvOn);
	partyOff.push_back(lightOff);
	partyOff.push_back(stereoOff);
	partyOff.push_back(tvOff);

	MacroCommand* partyOnMacro = new MacroCommand(partyOn);
	MacroCommand* partyOffMacro = new MacroCommand(partyOff);

	// ��ư ����
	RemoteControl* remoteControl = new RemoteControl;
	remoteControl->setCommand(0, partyOnMacro, partyOffMacro);
	remoteControl->toString();
	cout << "------ ��ũ�� ON ------" << endl;
	remoteControl->onButtonWasPushed(0);
	cout << "------ ��ũ�� OFF ------" << endl;
	remoteControl->offButtonWasPushed(0);
}