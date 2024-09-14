#pragma once

namespace CloneMonster
{
	class Monster
	{
	public:
		virtual ~Monster() {}
		virtual Monster* clone() = 0;
	};

	class Ghost : public Monster
	{
	private:
		int health_;
		int speed_;
	public:
		Ghost(int health, int speed) : health_{health}, speed_{speed} {}
		virtual Monster* clone() override
		{
			return new Ghost(health_, speed_);
		}
	};

	// Ŭ���� ���ο� Monster ��ü�� ���� �ִ�.(p90)
	class Spawner
	{
	private:
		Monster* prototype_;
	public:
		Spawner(Monster* prototype) : prototype_{prototype} {}
		Monster* spawnMonster()
		{
			return prototype_->clone();
		}
	};
}