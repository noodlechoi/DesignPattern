#pragma once

namespace ENUM
{
	enum Input
	{
		PRESS_B,
		PRESS_DOWN,
		RELEASE_DOWN,
	};

	enum State
	{
		STANDING,
		JUMPING,
		DUCKING,
		DIVING,
	};

	class Heroine
	{
		void handleInput(Input input);
		void update();
		void superBomb() {}
	private:
		static const int MAX_CHARGE{ 5 };
		State state_;
		int chargeTime_{};
	};
}

namespace StatePattern
{
	enum Input
	{
		PRESS_B,
		PRESS_DOWN,
		RELEASE_DOWN,
	};

	enum State
	{
		STANDING,
		JUMPING,
		DUCKING,
		DIVING,
	};

	class Heroine
	{
	public:
		void handleInput(Input input)
		{
			state_->handleInput(*this, input);
		}
		void update()
		{
			state_->update(*this);
		}
		void superBomb() {}
		static const int MAX_CHARGE{ 5 };
	private:
		HeroineState* state_;
	};

	class HeroineState
	{
	public:
		virtual ~HeroineState() {}
		virtual void handleInput(Heroine& heroine, Input input) {}
		virtual void update(Heroine& heroine) {}
	};

	class DuckingState : public HeroineState
	{
	private:
		int chargeTime_;
	public:
		DuckingState() : chargeTime_{} {}

		virtual void handleInput(Heroine& heroine, Input input) override
		{
			if (input == RELEASE_DOWN) {
				// 일어선 상태로 바꾼다
			}
		}

		virtual void update(Heroine& heroine)
		{
			chargeTime_++;
			if (chargeTime_ > Heroine::MAX_CHARGE) {
				heroine.superBomb();
			}
		}
	};
}