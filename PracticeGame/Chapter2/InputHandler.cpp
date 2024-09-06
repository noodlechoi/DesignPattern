#include "InputHandler.h"
#include <conio.h>

void InputHandler::handlerInput()
{
	char k = _getch();
	if (k == 'x') buttonX_->execute();
	else if (k == 'y') buttonY_->execute();
	else if (k == 'a') buttonA_->execute();
	else if (k == 'b') buttonB_->execute();
}

InputHandler::InputHandler()
{
	buttonX_ = new JumpCommand();
	buttonY_ = new FireCommand();
	// »ý·«
}