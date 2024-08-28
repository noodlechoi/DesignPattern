#pragma once
#include "Ducks.h"

// �����
class GooseAdapter : public Quackable
{
	std::unique_ptr<Goose> goose;
public:
	GooseAdapter() = delete;
	GooseAdapter(std::unique_ptr<Goose> goose);
	void quack() override;
};

// ���ڷ�����
class QuackCounter : public Quackable
{
	std::unique_ptr<Quackable> duck;
	static int number;
public:
	QuackCounter() = delete;
	QuackCounter(std::unique_ptr<Quackable>);
	void quack() override;
	static int getQuacks() { return number; }
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};

// ���丮
class AbstractDuckFactory
{
public:
	virtual std::unique_ptr<Quackable> createMallardDuck() = 0;
	virtual std::unique_ptr<Quackable> createRedheadDuck() = 0;
	virtual std::unique_ptr<Quackable> createDuckCall() = 0;
	virtual std::unique_ptr<Quackable> createRubberDuck() = 0;
};

class DuckFactory : public AbstractDuckFactory
{
public:
	std::unique_ptr<Quackable> createMallardDuck() override;
	std::unique_ptr<Quackable> createRedheadDuck() override;
	std::unique_ptr<Quackable> createDuckCall() override;
	std::unique_ptr<Quackable> createRubberDuck() override;
};

class CountingDuckFactory : public AbstractDuckFactory
{
public:
	std::unique_ptr<Quackable> createMallardDuck() override;
	std::unique_ptr<Quackable> createRedheadDuck() override;
	std::unique_ptr<Quackable> createDuckCall() override;
	std::unique_ptr<Quackable> createRubberDuck() override;
};

// ������Ʈ ����
class Flock : public Quackable
{
	std::vector<std::shared_ptr<Quackable>> quackers;
public:
	Flock();
	void add(std::unique_ptr<Quackable>& quacker);
	void add(std::shared_ptr<Quackable> quacker);
	void quack() override;
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};