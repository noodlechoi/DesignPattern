#include "DuckSimulator.h"

int main()
{
	std::unique_ptr<DuckSimulator> simulator = std::make_unique<DuckSimulator>();
	simulator->simulate();
}