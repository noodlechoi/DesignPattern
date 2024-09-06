#pragma once

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class JumpCommand : public Command
{
public:
	virtual void execute() override;
};

class FireCommand : public Command
{
public:
	virtual void execute() override;
};

// 그외 생략