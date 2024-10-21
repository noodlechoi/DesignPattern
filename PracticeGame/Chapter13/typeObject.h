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
		// 방식 1: 속성 값을 요청받을 때마다 동적으로 위임하는 방식
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
				// 오버라이딩
				if (health_ != 0 || parent_ == nullptr) {
					return health_;
				}

				// 상속
				return parent_->getHealth();
			}

			const char* Breed::getAttack()
			{
				// 오버라이딩
				if (attack_ != nullptr || parent_ == nullptr) {
					return attack_;
				}

				// 상속
				return parent_->getAttack();
			}
		}

		// 방식 2: 카피다운 위임
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
					// 오버라이드하지 않고 속성만 상속받는다.
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