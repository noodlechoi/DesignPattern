#include "Command.h"
#include <iostream>

namespace Key
{
	void jump()
	{
		std::cout << "����\n";
	}

	void fireGun()
	{
		std::cout << "����\n";
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