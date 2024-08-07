#pragma once
#include "MenuItem.h"

class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual MenuItem* next() = 0;
};