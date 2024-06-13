#pragma once
#include "Control.h"
#include <vector>
#include <string>

class Command
{
public:
	virtual void execute() = 0;
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
			onCommands[i] = nullptr;
			offCommands[i] = nullptr;
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

	void onButtonWasPushed(int slot)
	{
		offCommands[slot]->execute();
	}

	std::string toString()
	{
		std::string buff{ "\n-----¸®¸ðÄÁ-----\n" };
		for (int i = 0; i < onCommands.size(); ++i) {
			std::string str{ "[slot " + i < "] " };
			str.append(typeid(onCommands[i]).name());
			str.append("    ");
			str.append(typeid(offCommands[i]).name());
			str.append("\n");

			buff.append(str);
		}

		return buff;
	}
};