#pragma once

class Duck
{
	// �ൿ �������̽� ����
	FlyBH flybh;
	QuackBH quackbh;

	Duck() = default;

	virtual void display() = 0;
	void performFly();
	void performQuack();
	void swim();
};