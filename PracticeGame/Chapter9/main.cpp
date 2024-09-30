#include "GameLoop.h"

using namespace GameLoop;

int main()
{
	// 게임 실행 속도 제어X
	/*while (true) {
		processInput();
		update();
		render();
	}*/

	// 해결, but 너무 느려지는 것을 막지 못한다.
	/*while (true) {
		double start = getCurrentTime();
		processInput();
		update();
		render();

		sleep(start + MS_PER_FRAME - getCurrentTime());
	}*/

	// 해결, 가변 시간 간격
	double last = getCurrentTime();
	while (true) {
		double current = getCurrentTime();
		double elapsed = current - last;
		processInput();
		update(elapsed);
		render();
		last = current;
	}
}