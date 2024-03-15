#pragma once
#include "FlyBH.h"
#include "QuackBH.h"

class Duck
{
protected:
	// 행동 인터페이스 변수
	FlyBH* flybh;	// 추상 클래스는 포인터나 참조자로 받아야함
	QuackBH* quackbh;
public:
	Duck() = default;
	~Duck();

	virtual void display() = 0;
	void performFly();
	void performQuack();
	void swim();

	void setFlyBH(FlyBH*);
	void setQuackBH(QuackBH*);
};