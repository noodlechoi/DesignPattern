#pragma once
#include "Beverage.h"

class CondimentDecorator : public Beverage
{
protected:
	Beverage* beverage;	// ���� ���Ḧ ��Ÿ���� Beverage ��ü ����
public:
	virtual std::string getDescription() = 0;	// ���� �����Ͽ� ����� ���� �߻� �޼ҵ�� ����
	SIZE getSize() override { return beverage->getSize(); }
};

