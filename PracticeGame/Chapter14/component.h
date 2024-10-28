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
	class GameObject
	{
	private:
		inputComponent* input_;
		PhysicsComponent* phsics_;
		GraphicsComponent* graphics_;
	public:
		int velocity_;
		int x_, y_;

		GameObject(inputComponent* input, PhysicsComponent* phsics, GraphicsComponent* graphics)
			: velocity_{}, x_{}, y_{}, input_(input), phsics_(phsics), graphics_(graphics) {}
		void update(World& world, Graphics& graphics)
		{
			input_->update(*this);
			phsics_->update(*this, world);
			graphics_->update(*this, graphics);
		}
	};

	class inputComponent
	{
	public:
		virtual ~inputComponent() {}
		virtual void update(GameObject& obj) = 0;
	};

	class PlayerInputComponent : public inputComponent
	{
	private:
		static const int WALK_ACCELERATION = 1;
	public:
		virtual void update(GameObject& obj)
		{
			switch (Controller::getJoystickDirection()) {
			case LEFT:
				obj.velocity_ -= WALK_ACCELERATION;
				break;
			case RIGHT:
				obj.velocity_ += WALK_ACCELERATION;
				break;
			default:
				break;
			}
		}
	};

	class DemoInputComponent : public inputComponent
	{
	public:
		virtual void update(GameObject& obj)
		{
			// AI가 알아서 조정한다.
		}
	};

	class PhysicsComponent
	{
	public:
		virtual ~PhysicsComponent() {}
		virtual void update(GameObject& obj, World& world) = 0;
	};

	class BjornPhysicsComponent : public PhysicsComponent
	{
	private:
		Volume volume_;
	public:
		virtual void update(GameObject& obj, World& world)
		{
			obj.x_ += obj.velocity_;
			world.resolveCollision(volume_, obj.x_, obj.y_, obj.velocity_);
		}
	};

	class GraphicsComponent
	{

	public:
		virtual ~GraphicsComponent() {}
		virtual void update(GameObject& obj, Graphics& graphics) = 0;
	};

	class BjornGraphicsComponent : public GraphicsComponent
	{
	private:
		Sprite spriteStand_;
		Sprite spriteWalkLeft_;
		Sprite spriteWaltRight_;
	public:
		virtual void update(GameObject& obj, Graphics& graphics)
		{
			Sprite* sprite = &spriteStand_;
			if (obj.velocity_ < 0) { sprite = &spriteWalkLeft_; }
			else if (obj.velocity_ > 0) { sprite = &spriteWaltRight_; }
			graphics.draw(*sprite, obj.x_, obj.y_);
		}
	};
}