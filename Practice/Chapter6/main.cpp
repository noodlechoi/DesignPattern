#include "Command.h"

int main()
{
	SimpleRemoteControl* remote = new SimpleRemoteControl;	// 인보커
	Light* light = new Light;								// 리시버
	LightONCommand* lightOn = new LightONCommand(light);	// 리시버를 커맨드 객체에 저장

	remote->setCommand(lightOn);							// 인보커에 커맨드 객체 저장
	remote->buttonWasPressed();								// execute 실행
}