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
		friend DuckingState;
	public:
		void handleInput(Input input)
		{
			HeroineState* state = state_->handleInput(*this, input);
			if (state != nullptr) {
				delete state_;
				state_ = state;

				state_->enter(*this);
			}
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
		static DuckingState ducking;
		// 기타 상태
		virtual ~HeroineState() {}
		virtual HeroineState* handleInput(Heroine& heroine, Input input) {}
		virtual void update(Heroine& heroine) {}
		virtual void enter(Heroine& heroine) {}
	};

	class DuckingState : public HeroineState
	{
	private:
		int chargeTime_;
	public:
		DuckingState() : chargeTime_{} {}

		virtual HeroineState* handleInput(Heroine& heroine, Input input) override
		{
			if (input == RELEASE_DOWN) {
				return new DuckingState();
			}
		}

		virtual void update(Heroine& heroine)
		{
			chargeTime_++;
			if (chargeTime_ > Heroine::MAX_CHARGE) {
				heroine.superBomb();
			}
		}

		virtual void enter(Heroine& heroine) {}

	};
}