#pragma once
#include "Control.h"
#include <vector>

class Command
{
public:
	virtual void execute() = 0;
};

class NoCommand : public Command // 널 객체
{
public:
	void execute() {}
};

class LightONCommand : public Command
{
private:
	Light* light;
public:
	LightONCommand(Light* light)
	{
		this->light = light;
	}

	void execute()
	{
		this->light->on();
	}
};

class LightOffCommand : public Command
{
private:
	Light* light;
public:
	LightOffCommand(Light* light)
	{
		this->light = light;
	}

	void execute()
	{
		this->light->off();
	}
};

class GarageDoorOpenCommand : public Command
{
private:
	GarageDoor* garageDoor;
public:
	GarageDoorOpenCommand(GarageDoor* garageDoor)
	{
		this->garageDoor = garageDoor;
	}

	void execute()
	{
		this->garageDoor->up();
	}
};

class GarageDoorCloseCommand : public Command
{
private:
	GarageDoor* garageDoor;
public:
	GarageDoorCloseCommand(GarageDoor* garageDoor)
	{
		this->garageDoor = garageDoor;
	}

	void execute()
	{
		this->garageDoor->down();
	}
};

class StereoOnWithCDCommand : public Command
{
	Stereo* stereo;
public:
	StereoOnWithCDCommand(Stereo* stereo)
	{
		this->stereo = stereo;
	}

	void execute() override
	{
		stereo->on();
		stereo->setCd();
		stereo->setVolume(11);
	}
};

class StereoOffCommand : public Command
{
	Stereo* stereo;
public:
	StereoOffCommand(Stereo* stereo)
	{
		this->stereo = stereo;
	}

	void execute() override
	{
		stereo->off();
	}
};


class SimpleRemoteControl
{
private:
	Command* slot{ nullptr };
public:
	SimpleRemoteControl() = default;

	void setCommand(Command* command)
	{
		slot = command;
	}
	void buttonWasPressed()
	{
		slot->execute();
	}
};

class RemoteControl
{
private:
	std::vector<Command*> onCommands;
	std::vector<Command*> offCommands;
	static const int buttonNum{7};
public:
	RemoteControl()
	{
		for (int i = 0; i < buttonNum; ++i) {
			onCommands.push_back(new NoCommand);
			offCommands.push_back(new NoCommand);
		}
	}

	void setCommand(int slot, Command* onCommand, Command* offCommand)
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}

	void onButtonWasPushed(int slot)
	{
		onCommands[slot]->execute();
	}

	void offButtonWasPushed(int slot)
	{
		offCommands[slot]->execute();
	}

	std::string toString()
	{
		std::string buff{ "\n-----리모컨-----\n" };
		for (int i = 0; i < onCommands.size(); ++i) {
			std::string str{ "[slot "};
			str.append(to_string(i));
			str.append("]");
			str.append(typeid(*onCommands[i]).name());
			str.append("    ");
			str.append(typeid(*offCommands[i]).name());
			str.append("\n");

			buff.append(str);
		}

		return buff;
	}

	int getButtonNum() { return buttonNum; }
};