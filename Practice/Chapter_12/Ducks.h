#pragma once
#include "Quackable.h"
#include <memory>

class MallardDuck : public Quackable
{
public:
	void quack() override;
};

class RedheadDuck : public Quackable
{
public:
	void quack() override;
};

class DuckCall : public Quackable
{
public:
	void quack() override;
};

class RubberDuck : public Quackable
{
public:
	void quack() override;
};

class Goose
{
public:
	void honk();
};

class GooseAdapter : public Quackable
{
private:
	std::unique_ptr<Goose> goose;
public:
	GooseAdapter() = delete;
	GooseAdapter(std::unique_ptr<Goose> goose);
	void quack() override;
};