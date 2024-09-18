#include "State.h"

void StatePattern::Heroine::handleInput(Input input)
{
	// 상태에 따라 분기
	switch (state_)
	{
	case StatePattern::STANDING:
		if (input == PRESS_B) {
			state_ = JUMPING;
		}
		else if (input == PRESS_DOWN) {
			state_ = DUCKING;
			chargeTime_ = 0;
		}
		break;
	case StatePattern::JUMPING:
		if (input == PRESS_DOWN) {
			state_ = DIVING;
		}
		break;
	case StatePattern::DUCKING:
		if (input == RELEASE_DOWN) {
			state_ = STANDING;
		}
		break;
	case StatePattern::DIVING:
		break;
	default:
		break;
	}
}

void StatePattern::Heroine::update()
{
	if (state_ == DUCKING) {
		chargeTime_++;
		if (chargeTime_ > MAX_CHARGE) {
			superBomb();
		}
	}
}
