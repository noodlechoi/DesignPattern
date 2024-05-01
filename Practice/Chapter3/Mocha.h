#pragma once
#include "CondimentDecorator.h"

// ���ڷ����ͱ� ������ CondimentDecorator Ȯ��
class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage);
	std::string getDescription() override;
	double cost() override;
};

