#pragma once
#include <random>

class Random
{
private:
	std::random_device rd;
	std::mt19937 gen;
public:
	Random();
	~Random();
public:
	int getInt(size_t start, size_t end);
};