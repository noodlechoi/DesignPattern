#pragma once

namespace spaceSpilit
{
	class Unit
	{
		friend class Grid;
	private:
		double x_, y_;
		Grid* grid_;

		Unit* prev_;
		Unit* next_;
	public:
		Unit(Grid* grid, double x, double y) 
			: grid_{grid}, x_{x}, y_{y}, 
			prev_{nullptr}, next_{nullptr}
		{
			grid_->add(this);
		}
		void move(double x, double y);
		
	};

	class Grid 
	{
	public:
		static const int NUM_CELLS = 10;
		static const int CELL_SIZE = 20;
	private:
		Unit* cells_[NUM_CELLS][NUM_CELLS];
	public:
		Grid()
		{
			// 격자를 지운다.
			for (int x = 0; x < NUM_CELLS; ++x) {
				for (int y = 0; y < NUM_CELLS; ++y) {
					cells_[x][y] = nullptr;
				}
			}
		}
		void add(Unit* unit)
		{
			// 어느 칸에 들어갈지 결정한다.
			int cellX = (int)(unit->x_ / Grid::CELL_SIZE);
			int cellY = (int)(unit->y_ / Grid::CELL_SIZE);

			// 칸에 들어 있는 리스트의 맨 앞에 추가한다.
			unit->prev_ = nullptr;
			unit->next_ = cells_[cellX][cellY];
			cells_[cellX][cellY] = unit;

			if (unit->next_ != nullptr) {
				unit->next_->prev_ = unit;
			}
		}
		void handleMelee()
		{
			for (int x = 0; x < NUM_CELLS; ++x) {
				for (int y = 0; y < NUM_CELLS; ++y) {
					handleCell(cells_[x][y]);
				}
			}
		}
		void handleCell(Unit* unit)
		{
			while (!unit) {
				Unit* other = unit->next_;
				while (!other) {
					if (unit->x_ == other->x_ && unit->y_ == other->y_) {
						handleAttack(unit, other);
					}
					other = other->next_;
				}
				unit = unit->next_;
			}
		}
	};

}