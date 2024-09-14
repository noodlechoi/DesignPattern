#include "MonsterSpawn.h"

using namespace CloneMonster;

int main()
{
	// 유령 스포너 생성
	Monster* ghostPrototype = new Ghost(15, 3);
	Spawner* ghostSpawner = new Spawner(ghostPrototype);
}