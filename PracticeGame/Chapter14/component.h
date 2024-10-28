#pragma once

class Volume
{};
class Sprite
{};
class World
{
public:
	void resolveCollision(Volume, int, int, int) {}
};
class Graphics
{
public:
	void draw(Sprite&, int, int) {}
};
class Controller
{
public:
	static int getJoystickDirection() {}
};
enum DIR
{
	LEFT,
	RIGHT,
};

namespace Tongjja
{
	class Bjorn
	{
	private:
		static const int WALK_ACCELERATION = 1;

		int velocity_;
		int x_, y_;

		Volume volume_;

		Sprite spriteStand_;
		Sprite spriteWalkLeft_;
		Sprite spriteWaltRight_;
	public:
		Bjorn() : velocity_{}, x_{}, y_{} {}
		void update(World& world, Graphics& graphics)
		{
			// 입력에 따라 속도 조절
			switch (Controller::getJoystickDirection())	{
				case LEFT:
					velocity_ -= WALK_ACCELERATION;
					break;
				case RIGHT:
					velocity_ += WALK_ACCELERATION;
					break;
				default:
					break;
			}

			// 속도에 따라 위치를 바꾼다.
			x_ += velocity_;
			world.resolveCollision(volume_, x_, y_, velocity_);

			// 스프라이트를 그린다.
			Sprite* sprite = &spriteStand_;
			if (velocity_ < 0) { sprite = &spriteWalkLeft_; }
			else if (velocity_ > 0) { sprite = &spriteWaltRight_; }

			graphics.draw(*sprite, x_, y_);
		}
	};
}

namespace Component
{
	class Bjorn
	{
	private:
		inputComponent input_;
		PhysicsComponent phsics_;
		GraphicsComponent graphics_;

	public:
		int velocity_;
		int x_, y_;

		Bjorn() : velocity_{}, x_{}, y_{} {}
		void update(World& world, Graphics& graphics)
		{
			input_.update(*this);
			phsics_.update(*this, world);
			graphics_.update(*this, graphics);
		}
	};

	class inputComponent
	{
	private:
		static const int WALK_ACCELERATION = 1;
	public:
		void update(Bjorn& bjorn)
		{
			switch (Controller::getJoystickDirection()) {
			case LEFT:
				bjorn.velocity_ -= WALK_ACCELERATION;
				break;
			case RIGHT:
				bjorn.velocity_ += WALK_ACCELERATION;
				break;
			default:
				break;
			}
		}
	};

	class PhysicsComponent
	{
	private:
		Volume volume_;
	public:
		void update(Bjorn& bjorn, World& world)
		{
			bjorn.x_ += bjorn.velocity_;
			world.resolveCollision(volume_, bjorn.x_, bjorn.y_, bjorn.velocity_);
		}
	};

	class GraphicsComponent
	{
	private:
		Sprite spriteStand_;
		Sprite spriteWalkLeft_;
		Sprite spriteWaltRight_;
	public:
		void update(Bjorn& bjorn, Graphics& graphics)
		{
			Sprite* sprite = &spriteStand_;
			if (bjorn.velocity_ < 0) { sprite = &spriteWalkLeft_; }
			else if (bjorn.velocity_ > 0) { sprite = &spriteWaltRight_; }
			graphics.draw(*sprite, bjorn.x_, bjorn.y_);
		}
	};
}