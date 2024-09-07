#include "InputHandler.h"
#include <conio.h>

Command* InputHandler::handlerInput()
{
	char k = _getch();
	if (k == 'x') return buttonX_;
	else if (k == 'y')  return buttonY_;
	else if (k == 'a')  return buttonA_;
	else if (k == 'b')  return buttonB_;

	return nullptr;
}

InputHandler::InputHandler()
{
	buttonX_ = new JumpCommand();
	buttonY_ = new FireCommand();
	// »ý·«
}