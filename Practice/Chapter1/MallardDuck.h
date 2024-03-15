#pragma once
#include "Duck.h"

class MallardDuck : public Duck
{
private:
public:
	MallardDuck();
	~MallardDuck() = default;
	void display() override;
};

