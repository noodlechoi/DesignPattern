#pragma once
#include "GameActor.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class MoveUnitCommand : public Command
{
public:
	MoveUnitCommand(Unit* unit, int x, int y) : unit{ unit }, x{ x }, y{ y }, xBefore{}, yBefore{} {}

	virtual void execute() override;
	virtual void undo() override;
private:
	Unit* unit;
	int x, y;
	int xBefore, yBefore;
};