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
		void handleInput(Input input);
		void update();
		void superBomb() {}
		static const int MAX_CHARGE{ 5 };
	private:
		State state_;
		int chargeTime_{};
	};

	class HerineState
	{
	public:
		virtual ~HerineState() {}
		virtual void handleInput(Heroine& heroine, Input input) {}
		virtual void update(Heroine& heroine) {}
	};

	class DuckingState : public HerineState
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