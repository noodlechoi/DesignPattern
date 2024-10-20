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

namespace TypeObject
{
	class Breed
	{
	private:
		int health_;
		const char* attack_;
	public:
		Breed(int health, const char* attack) : health_{health}, attack_{attack} {}
		int getHealth() { return health_; }
		const char* getAttack() { return attack_; }
	};

	class Monster
	{
	private:
		int health_;
		Breed& breed_;
	public:
		Monster(Breed& breed) : health_(breed.getHealth()), breed_{breed} {}
		const char* getAttack() { return breed_.getAttack(); }
	};

}