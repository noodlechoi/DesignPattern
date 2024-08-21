#include "DuckSimulator.h"

int main()
{
	std::unique_ptr<AbstractDuckFactory> duckFactory = std::make_unique<CountingDuckFactory>();
	std::unique_ptr<DuckSimulator> simulator = std::make_unique<DuckSimulator>(std::move(duckFactory));

	simulator->simulate();
}