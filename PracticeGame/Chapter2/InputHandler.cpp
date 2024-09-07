#include "InputHandler.h"
#include <conio.h>

Command* InputHandler::handlerInput()
{
	Unit* unit = new Unit;

	char k = _getch();
	if (k == 'w') {
		int destY = unit->GetY() -  1;
		// unity의 x,y가 아닌 MoveUnitCommand의 x,y에 이동할 좌표를 저장
		return new MoveUnitCommand(unit, unit->GetX(), destY);
	}
	else if (k == 's') {
		int destY = unit->GetY() + 1;
		return new MoveUnitCommand(unit, unit->GetX(), destY);
	}
	else if (k == 'a') {
		int destX = unit->GetX() - 1;
		return new MoveUnitCommand(unit, destX, unit->GetY());
	}
	else if (k == 'd') {
		int destX = unit->GetX() + 1;
		return new MoveUnitCommand(unit, destX, unit->GetY());
	}

	return nullptr;
}

InputHandler::InputHandler()
{
}