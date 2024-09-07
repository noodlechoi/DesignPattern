#pragma once


namespace GameWorld
{
	const int WIDTH{5}, HEIGHT{5};

	class Terrain
	{
	private:
		int movementCost_;
		bool isWater_;
		//Texture texture; 생략
	public:
		Terrain(int movementCost, bool isWater) : movementCost_{movementCost}, isWater_{isWater} {}

		int getMovementCost() const{ return movementCost_; }
		bool isWater() const { return isWater_; }
	};

	class World
	{
	private:
		// 지형 종유가 같은 타일은 모두 같은 인스턴스 포인터를 갖는다.
		Terrain* tiles_[WIDTH][HEIGHT];

		Terrain grassTerrain_;
		Terrain hillTerrain_;
		Terrain riverTerrain_;
	public:
		World() : grassTerrain_(1, false), hillTerrain_(3, false), riverTerrain_(2, true) {}

		void generateTerrain()
		{
			// 땅에 풀을 채운다.
			for (int x = 0; x < WIDTH; ++x) {
				for (int y = 0; y < HEIGHT; ++y) {
					tiles_[x][y] = &grassTerrain_;
				}
			}

			// 강
			int x = 3;
			for (int y = 0; y < HEIGHT; ++y) {
				tiles_[x][y] = &riverTerrain_;
			}
		}

		const Terrain& getTile(int x, int y) const { return *tiles_[x][y]; }
	};


}