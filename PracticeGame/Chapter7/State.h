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


namespace Double
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
			state_->handleInput(*this, input);
			equipment->handleInput(*this, input);
		}
		void update()
		{
			state_->update(*this);
		}
		void superBomb() {}
		static const int MAX_CHARGE{ 5 };
	private:
		HeroineState* state_;
		HeroineState* equipment;
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


namespace Step
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
		virtual void handleInput(Heroine& heroine, Input input) {}
		virtual void update(Heroine& heroine) {}
		virtual void enter(Heroine& heroine) {}
	};

	class OnGroundState : public HeroineState
	{
	public:
		virtual void handleInput(Heroine& heroine, Input input) override
		{
			if(input == PRESS_B) {}
			// 등등
		}
	};

	class DuckingState : public OnGroundState
	{
	private:
		int chargeTime_;
	public:
		DuckingState() : chargeTime_{} {}

		virtual void handleInput(Heroine& heroine, Input input) override
		{
			if (input == RELEASE_DOWN) {
			}
			else {
				// 따로 입력을 처리하지 않고 상위 상태로 보낸다.
				OnGroundState::handleInput(heroine, input);
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