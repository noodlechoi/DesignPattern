#include "InputHandler.h"

int main()
{
	InputHandler h;
	GameActor actor;

	Command* command;
	while (1) {
		command = h.handlerInput();
		if (command) {
			command->execute(actor);
		}
	}
}