#include "Terrain.h"
#include <iostream>

int main()
{
	GameWorld::World world;
	world.generateTerrain();

	int cost = world.getTile(2, 3).getMovementCost();
	std::cout << cost;
}