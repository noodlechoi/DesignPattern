#include "Command.h"
#include <iostream>

namespace Key
{
	void jump()
	{
		std::cout << "Á¡ÇÁ\n";
	}

	void fireGun()
	{
		std::cout << "»§¾ß\n";
	}
}


void JumpCommand::execute()
{
	Key::jump();
}

void FireCommand::execute()
{
	Key::fireGun();
}