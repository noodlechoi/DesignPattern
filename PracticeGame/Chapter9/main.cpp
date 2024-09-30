#include "GameLoop.h"

using namespace GameLoop;

int main()
{
	// ���� ���� �ӵ� ����X
	/*while (true) {
		processInput();
		update();
		render();
	}*/

	// �ذ�, but �ʹ� �������� ���� ���� ���Ѵ�.
	/*while (true) {
		double start = getCurrentTime();
		processInput();
		update();
		render();

		sleep(start + MS_PER_FRAME - getCurrentTime());
	}*/

	// �ذ�, ���� �ð� ����
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