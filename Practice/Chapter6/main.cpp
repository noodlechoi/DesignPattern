#include "Command.h"

int main()
{
	RemoteControl* remoteControl = new RemoteControl;

	Light* livingRoomLight = new Light("거실");
	Light* kitchenLight = new Light("부엌");
	GarageDoor* garageDoor = new GarageDoor("차고");
	Stereo* stereo = new Stereo("거실");

	LightONCommand* livingRoomLightOn = new LightONCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
	LightONCommand* kitchenLightmLightOn = new LightONCommand(kitchenLight);
	LightOffCommand* kitchenLightLightOff = new LightOffCommand(kitchenLight);

	GarageDoorOpenCommand* garageDoorOpen = new GarageDoorOpenCommand(garageDoor);
	GarageDoorCloseCommand* garageDoorclose = new GarageDoorCloseCommand(garageDoor);

	StereoOnWithCDCommand* stereoOnWithCD = new StereoOnWithCDCommand(stereo);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remoteControl->setCommand(1, kitchenLightmLightOn, kitchenLightLightOff);
	remoteControl->setCommand(2, garageDoorOpen, garageDoorclose);
	remoteControl->setCommand(3, stereoOnWithCD, stereoOff);

	cout << remoteControl->toString() << endl;

	for (int i = 0; i < remoteControl->getButtonNum(); ++i) {
		remoteControl->onButtonWasPushed(i);
		remoteControl->offButtonWasPushed(i);
	}

}