#pragma once


namespace GameWorld
{
	const int WIDTH{5}, HEIGHT{5};

	class Terrain
	{
	private:
		int movementCost_;
		bool isWater_;
		//Texture texture; ����
	public:
		Terrain(int movementCost, bool isWater) : movementCost_{movementCost}, isWater_{isWater} {}

		int getMovementCost() const{ return movementCost_; }
		bool isWater() const { return isWater_; }
	};

	class World
	{
	private:
		// ���� ������ ���� Ÿ���� ��� ���� �ν��Ͻ� �����͸� ���´�.
		Terrain* tiles_[WIDTH][HEIGHT];

		Terrain grassTerrain_;
		Terrain hillTerrain_;
		Terrain riverTerrain_;
	public:
		World() : grassTerrain_(1, false), hillTerrain_(3, false), riverTerrain_(2, true) {}

		void generateTerrain()
		{
			// ���� Ǯ�� ä���.
			for (int x = 0; x < WIDTH; ++x) {
				for (int y = 0; y < HEIGHT; ++y) {
					tiles_[x][y] = &grassTerrain_;
				}
			}

			// ��
			int x = 3;
			for (int y = 0; y < HEIGHT; ++y) {
				tiles_[x][y] = &riverTerrain_;
			}
		}

		const Terrain& getTile(int x, int y) const { return *tiles_[x][y]; }
	};


}