#include "MonsterSpawn.h"

using namespace CloneMonster;

int main()
{
	// ���� ������ ����
	Monster* ghostPrototype = new Ghost(15, 3);
	Spawner* ghostSpawner = new Spawner(ghostPrototype);
}