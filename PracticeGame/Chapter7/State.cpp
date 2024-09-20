#include "State.h"

void ENUM::Heroine::handleInput(Input input)
{
	// 상태에 따라 분기
	switch (state_)
	{
	case ENUM::STANDING:
		if (input == PRESS_B) {
			state_ = JUMPING;
		}
		else if (input == PRESS_DOWN) {
			state_ = DUCKING;
			chargeTime_ = 0;
		}
		break;
	case ENUM::JUMPING:
		if (input == PRESS_DOWN) {
			state_ = DIVING;
		}
		break;
	case ENUM::DUCKING:
		if (input == RELEASE_DOWN) {
			state_ = STANDING;
		}
		break;
	case ENUM::DIVING:
		break;
	default:
		break;
	}
}

void ENUM::Heroine::update()
{
	if (state_ == DUCKING) {
		chargeTime_++;
		if (chargeTime_ > MAX_CHARGE) {
			superBomb();
		}
	}
}
