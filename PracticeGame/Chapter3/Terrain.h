#pragma once


namespace GameWorld
{
	const int WIDTH{5}, HEIGHT{5};

	enum Terrain {
		TERRAIN_GLASS,
		TERRAIN_HILL,
		TERRAIN_RIVER,
		// 그 외 지형들
	};

	class World
	{
	private:
		Terrain tiles_[WIDTH][HEIGHT];
	public:
		int getMovementCost(int x, int y) {
			switch (tiles_[x][y]) {
			case TERRAIN_GLASS: return 1;
			case TERRAIN_HILL: return 3;
			case TERRAIN_RIVER: return 2;
			default:
				return 0;
			}
		}

		bool isWater(int x, int y) {
			switch (tiles_[x][y]) {
			case TERRAIN_GLASS: return false;
			case TERRAIN_HILL: return false;
			case TERRAIN_RIVER: return true;
			default:
				return false;
			}
		}
	};


}