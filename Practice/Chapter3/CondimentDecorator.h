#pragma once
#include "Beverage.h"

class CondimentDecorator : public Beverage
{
protected:
	Beverage* beverage;	// 감쌀 음료를 나타내는 Beverage 객체 저장
public:
	virtual std::string getDescription() = 0;	// 새로 구현하여 만들기 위해 추상 메소드로 선언
	SIZE getSize() override { return beverage->getSize(); }
};

