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
		void move(double x, double y)
		{
			grid_->move(this, x, y);
		}
		
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
			// ���ڸ� �����.
			for (int x = 0; x < NUM_CELLS; ++x) {
				for (int y = 0; y < NUM_CELLS; ++y) {
					cells_[x][y] = nullptr;
				}
			}
		}
		void add(Unit* unit)
		{
			// ��� ĭ�� ���� �����Ѵ�.
			int cellX = (int)(unit->x_ / Grid::CELL_SIZE);
			int cellY = (int)(unit->y_ / Grid::CELL_SIZE);

			// ĭ�� ��� �ִ� ����Ʈ�� �� �տ� �߰��Ѵ�.
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
		void handleCell(int x, int y)
		{
			Unit* unit = cells_[x][y];
			while (unit) {
				// �� ĭ�� ����ִ� �ٸ� ������ ó���Ѵ�.
				handleUnit(unit, unit->next_);

				// Ȯ��
				// �ֺ� ĭ�� ��� �ִ� ���ֵ鵵 Ȯ���Ѵ�.
				if (x > 0) handleUnit(unit, cells_[x - 1][y]);
				if (y > 0) handleUnit(unit, cells_[x][y - 1]);
				if (x > 0 && y > 0) handleUnit(unit, cells_[x - 1][y - 1]);
				if (x > 0 && y > NUM_CELLS - 1) handleUnit(unit, cells_[x - 1][y + 1]);

				unit = unit->next_;
			}
		}
		void handleUnit(Unit* unit, Unit* other)
		{
			while (other) {
				if (distance(unit, other) < ATTACK_DISTANCE) {
					handleAttack(unit, other);
				}
				other = other->next_;
			}
		}
		void move(Unit* unit, double x, double y)
		{
			// ������ ��� ĭ�� �־����� Ȯ���Ѵ�.
			int oldCellX = (int)(unit->x_ / Grid::CELL_SIZE);
			int oldCellY = (int)(unit->y_ / Grid::CELL_SIZE);

			// ������ ��� ĭ���� �����ϴ��� Ȯ���Ѵ�.
			int cellX = (int)(x / Grid::CELL_SIZE);
			int cellY = (int)(y / Grid::CELL_SIZE);

			unit->x_ = x;
			unit->y_ = y;

			// ĭ�� �ٲ��� �ʾҴٸ� �� �� ���� ����.
			if (oldCellX == cellX && oldCellY == cellY) {
				return;
			}

			// ���� ĭ�� ��� �ִ� ����Ʈ���� ������ ����
			if (unit->prev_) {
				unit->prev_->next_ = unit->next_;
			}

			if (unit->next_) {
				unit->next_->prev_ = unit->prev_;
			}

			// ������ ĭ�� ��� �ִ� ����Ʈ�� �Ӹ����ٸ� �Ӹ��� �ٲ��ش�.
			if (cells_[oldCellX][oldCellY] == unit) {
				cells_[oldCellX][oldCellY] = unit->next_;
			}

			// ���� �� ĭ�� �߰��Ѵ�.
			add(unit);
		}
	};
}