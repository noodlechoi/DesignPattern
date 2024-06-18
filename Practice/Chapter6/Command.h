#pragma once
#include "Control.h"
#include <vector>

class Command
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class NoCommand : public Command // 널 객체
{
public:
	void execute() override {}
	void undo() override {};
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

	void execute() override
	{
		this->light->on();
	}

	void undo() override
	{
		this->light->off();
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

	void execute() override
	{
		this->light->off();
	}

	void undo() override
	{
		this->light->on();
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

	void execute() override
	{
		this->garageDoor->up();
	}

	void undo() override
	{
		this->garageDoor->down();
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

	void execute() override
	{
		this->garageDoor->down();
	}

	void undo() override
	{
		this->garageDoor->up();
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

	void undo() override
	{
		stereo->off();
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

	void undo() override
	{
		stereo->on();
		stereo->setCd();
		stereo->setVolume(11);
	}
};

class CeilingFanHighCommand : public Command
{
	CeilingFan* ceilingFan{};
	int prevSpeed{};
public:
	CeilingFanHighCommand(CeilingFan* ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->high();
	}

	void undo() override
	{
		if (prevSpeed == CeilingFan::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == CeilingFan::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == CeilingFan::LOW)
		{
			ceilingFan->low();
		}
		else
		{
			ceilingFan->off();
		}
	}
};

class CeilingFanMediumCommand : public Command
{
	CeilingFan* ceilingFan{};
	int prevSpeed{};
public:
	CeilingFanMediumCommand(CeilingFan* ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}

	void undo() override
	{
		if (prevSpeed == CeilingFan::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == CeilingFan::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == CeilingFan::LOW)
		{
			ceilingFan->low();
		}
		else
		{
			ceilingFan->off();
		}
	}
};

class CeilingFanOffCommand : public Command
{
	CeilingFan* ceilingFan{};
	int prevSpeed{};
public:
	CeilingFanOffCommand(CeilingFan* ceilingFan)
	{
		this->ceilingFan = ceilingFan;
	}

	void execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->off();
	}

	void undo() override
	{
		if (prevSpeed == CeilingFan::HIGH)
		{
			ceilingFan->high();
		}
		else if (prevSpeed == CeilingFan::MEDIUM)
		{
			ceilingFan->medium();
		}
		else if (prevSpeed == CeilingFan::LOW)
		{
			ceilingFan->low();
		}
		else
		{
			ceilingFan->off();
		}
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
	Command* undoCommand{};
	static const int buttonNum{7};
public:
	RemoteControl()
	{
		for (int i = 0; i < buttonNum; ++i) {
			onCommands.push_back(new NoCommand);
			offCommands.push_back(new NoCommand);
		}
		undoCommand = new NoCommand;
	}

	void setCommand(int slot, Command* onCommand, Command* offCommand)
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}

	void onButtonWasPushed(int slot)
	{
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}

	void offButtonWasPushed(int slot)
	{
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}

	void undoButtonWasPushed()
	{
		undoCommand->undo();
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
		buff.append("[undo] ");
		buff.append(typeid(*undoCommand).name());
		buff.append("\n");

		return buff;
	}

	int getButtonNum() { return buttonNum; }
};