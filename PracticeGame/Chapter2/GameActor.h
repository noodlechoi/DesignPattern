#pragma once

class Unit
{
public:
	Unit() : x{}, y{} {}
	void MoveTo(int x, int y);
	int GetX() { return x; }
	int GetY() { return y; }
private:
	int x, y;
};