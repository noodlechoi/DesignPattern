#pragma once
#include "GameActor.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(GameActor& actor) = 0;
};

class JumpCommand : public Command
{
public:
	virtual void execute(GameActor& actor) override;
};

class FireCommand : public Command
{
public:
	virtual void execute(GameActor& actor) override;
};

// 그외 생략