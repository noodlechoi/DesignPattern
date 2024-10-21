#pragma once

// ��� �̿�
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

	namespace FactoryMethod
	{
		class Breed
		{
		private:
			int health_;
			const char* attack_;
		public:
			Monster* newMonster()
			{
				return new Monster(*this);
			}
			Breed(int health, const char* attack) : health_{ health }, attack_{ attack } {}
			int getHealth() { return health_; }
			const char* getAttack() { return attack_; }
		};

		class Monster
		{
			friend class Breed;
		private:
			Monster(Breed& breed) : health_(breed.getHealth()), breed_{ breed } {}
			int health_;
			Breed& breed_;
		public:
			const char* getAttack() { return breed_.getAttack(); }
		};
	}
	
	namespace ShareData
	{
		// ��� 1: �Ӽ� ���� ��û���� ������ �������� �����ϴ� ���
		namespace One
		{
			class Breed
			{
			private:
				Breed* parent_;
				int health_;
				const char* attack_;
			public:
				Breed(Breed* parent, int health, const char* attack) : parent_{parent}, health_ { health }, attack_{ attack } {}
				int getHealth();
				const char* getAttack();
			};

			int Breed::getHealth()
			{
				// �������̵�
				if (health_ != 0 || parent_ == nullptr) {
					return health_;
				}

				// ���
				return parent_->getHealth();
			}

			const char* Breed::getAttack()
			{
				// �������̵�
				if (attack_ != nullptr || parent_ == nullptr) {
					return attack_;
				}

				// ���
				return parent_->getAttack();
			}
		}

		// ��� 2: ī�Ǵٿ� ����
		namespace Two
		{
			class Breed
			{
			private:
				int health_;
				const char* attack_;
			public:
				Breed(Breed* parent, int health, const char* attack) : health_{ health }, attack_{ attack }
				{
					// �������̵����� �ʰ� �Ӽ��� ��ӹ޴´�.
					if (parent != nullptr) {
						if (health == 0)
							health_ = parent->getHealth();
						if (attack == nullptr)
							attack_ = parent->getAttack();
					}
				}
				int getHealth() { return health_; }
				const char* getAttack() { return attack_; }
			};
		}
	}

}