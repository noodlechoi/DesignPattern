#include "Command.h"

int main()
{
	// 리시버 객체 생성
	Light* light = new Light("거실");
	TV* tv = new TV("거실");
	Stereo* stereo = new Stereo("거실");

	// 커맨드 객체 생성
	LightONCommand* lightOn = new LightONCommand(light);
	StereoOnWithCDCommand* stereoOn = new StereoOnWithCDCommand(stereo);
	TVOnCommand* tvOn = new TVOnCommand(tv);

	// OFF 커맨드
	LightOffCommand* lightOff= new LightOffCommand(light);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);
	TVOffCommand* tvOff = new TVOffCommand(tv);

	// 배열
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

	// 버튼 실행
	RemoteControl* remoteControl = new RemoteControl;
	remoteControl->setCommand(0, partyOnMacro, partyOffMacro);
	remoteControl->toString();
	cout << "------ 매크로 ON ------" << endl;
	remoteControl->onButtonWasPushed(0);
	cout << "------ 매크로 OFF ------" << endl;
	remoteControl->offButtonWasPushed(0);
}