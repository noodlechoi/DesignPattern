#pragma once
#include "Control.h"

class Command
{
public:
	virtual void execute() = 0;
};

class LightONCommand : public Command
{
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

class SimpleRemoteControl
{
public:
	Command* slot{nullptr};
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