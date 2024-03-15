#pragma once
#include "FlyBH.h"
#include "QuackBH.h"

class Duck
{
protected:
	// �ൿ �������̽� ����
	FlyBH* flybh;	// �߻� Ŭ������ �����ͳ� �����ڷ� �޾ƾ���
	QuackBH* quackbh;
public:
	Duck() = default;

	virtual void display() = 0;
	void performFly();
	void performQuack();
	void swim();
};