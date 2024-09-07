#include "Command.h"
#include <iostream>

void MoveUnitCommand::execute()
{
	// this->x,y == 0, -1 : unit->x,y == 0, 0
	xBefore = unit->GetX();
	yBefore = unit->GetY();
	std::cout << unit->GetX() << " ";
	std::cout << unit->GetY() << std::endl;

	// this->x,y == 0, -1 : unit->x,y == 0, -1
	// this�� �ִ� x,y�� unit�� ����
	unit->MoveTo(x, y);
	std::cout << unit->GetX() << " ";
	std::cout << unit->GetY() << std::endl;
}

void MoveUnitCommand::undo()
{
	unit->MoveTo(xBefore, yBefore);
	std::cout << "undo: ";
	std::cout << unit->GetX() << " ";
	std::cout << unit->GetY() << std::endl;
}
