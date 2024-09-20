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
		void handleInput(Input input);
		void update();
		void superBomb() {}
	private:
		static const int MAX_CHARGE{ 5 };
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
}