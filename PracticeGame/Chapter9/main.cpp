#include "GameLoop.h"

using namespace GameLoop;

int main()
{
	// ���� ���� �ӵ� ����X
	while (true) {
		processInput();
		update();
		render();
	}
}