#include "Command.h"

int main()
{
	RemoteControl* remoteControl = new RemoteControl;

	CeilingFan* ceilingFan = new CeilingFan("°Å»ì");

	CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
	CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
	CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

	remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
	remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	cout << remoteControl->toString() << endl;
	remoteControl->undoButtonWasPushed();

	remoteControl->onButtonWasPushed(1);
	cout << remoteControl->toString() << endl;
	remoteControl->undoButtonWasPushed();
}