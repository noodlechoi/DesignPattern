#include "UpdateMethod.h"
Entity skeleton;
bool patrollingLeft = false;
double x = 0;


int main()
{
	// 코드를 유지보수하기 힘들다.
	while (true) {
		if (patrollingLeft) {
			x--;
			if (x == 0) patrollingLeft = false;
		}
		else {
			x++;
			if (x == 100)  patrollingLeft = true;
		}
		skeleton.setX(x);
		// 입력 처리 및 렌더링
	}
}