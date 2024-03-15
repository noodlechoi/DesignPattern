#pragma once

class Duck
{
	// 행동 인터페이스 변수
	FlyBH flybh;
	QuackBH quackbh;

	Duck() = default;

	virtual void display() = 0;
	void performFly();
	void performQuack();
	void swim();
};