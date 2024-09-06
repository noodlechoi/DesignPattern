#pragma once
#include "Command.h"

class InputHandler
{
public:
	void handlerInput();
	InputHandler();
private:
	Command* buttonX_;
	Command* buttonY_;
	Command* buttonA_;
	Command* buttonB_;
};