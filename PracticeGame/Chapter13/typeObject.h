#pragma once

// 상속 이용
namespace classicalOOP
{
	class Monster
	{
	private:
		int health_;
	protected:
		Monster(int startingHealth) : health_{startingHealth} {}
	public:
		virtual ~Monster() {}
		virtual const char* getAttack() = 0;
	};

	class Dragon : public Monster
	{
	public:
		Dragon() : Monster(230) {}
		virtual const char* getAttack() override {}
	};
}