#include "UpdateMethod.h"
Entity skeleton;
bool patrollingLeft = false;
double x = 0;


int main()
{
	// �ڵ带 ���������ϱ� �����.
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
		// �Է� ó�� �� ������
	}
}