#include "GameLoop.h"

using namespace GameLoop;

int main()
{
	// 게임 실행 속도 제어X
	while (true) {
		processInput();
		update();
		render();
	}
}