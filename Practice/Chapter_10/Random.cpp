#include "Random.h"
using namespace std;

Random::Random() : gen{ rd() }
{
}

Random::~Random()
{

}

int Random::getInt(size_t start, size_t end)
{
	uniform_int_distribution<size_t> dist(start, end);

	return dist(this->gen);
}