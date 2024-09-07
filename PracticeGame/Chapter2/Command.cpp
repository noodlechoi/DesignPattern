#include "Command.h"


void JumpCommand::execute(GameActor& actor)
{
	actor.jump();
}

void FireCommand::execute(GameActor& actor)
{
	actor.fireGun();
}