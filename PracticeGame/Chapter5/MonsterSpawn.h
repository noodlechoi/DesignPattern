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

namespace SpawnFunc
{
	class Monster
	{
	public:
		virtual ~Monster() {}
		virtual Monster* clone() = 0;
	};

	class Ghost : public Monster
	{
	public:
		Ghost()  {}
		virtual Monster* clone() override
		{
			return new Ghost();
		}
	};

	Monster* spawnGhost()
	{
		return new Ghost();
	}

	// �Լ� ������ ����
	typedef Monster* (*SpawnCallback) ();

	class Spawner
	{
	private:
		SpawnCallback spawn_;
	public:
		Spawner(SpawnCallback spawn) :spawn_{spawn} {}
		Monster* spawnMonster() { return spawn_(); }
	};
}