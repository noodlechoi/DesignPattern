#include "InputHandler.h"

int main()
{
	InputHandler h;

	Command* command;
	while (1) {
		command = h.handlerInput();
		if (command) {
			command->execute();
			command->undo();
		}
	}
}