#pragma once
#include <iostream>
#include "Random.h"

using namespace std;

class Duck
{
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallarDuck : public Duck
{
public:
	void quack() override
	{
		cout << "��" << endl;
	}

	void fly() override
	{
		cout << "���� �־��!!" << endl;
	}
};

class Turkey
{
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
	void gobble() override
	{
		cout << "���" << endl;
	}

	void fly() override
	{
		cout << "ª�� �Ÿ��� ���� �־��!!" << endl;
	}
};

class TurketAdapter : public Duck
{
private:
	Turkey* turkey;
public:
	TurketAdapter(Turkey* turkey)
	{
		this->turkey = turkey;
	}
	void quack() override
	{
		turkey->gobble();
	}

	void fly() override
	{
		for (int i = 0; i < 5; ++i) {
			turkey->fly();
		}
	}
};

class DuckAdapter : public Turkey
{
private:
	Duck* duck;
	Random* rand;
public:
	DuckAdapter(Duck* duck)
	{
		this->duck = duck;
		rand = new Random;
	}

	void gobble() override
	{
		duck->quack();
	}

	void fly() override
	{
		if (rand->getInt(0, 5) == 0) {
			duck->fly();
		}
	}
};