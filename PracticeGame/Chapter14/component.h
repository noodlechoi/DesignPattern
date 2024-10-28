#pragma once

namespace Tongjja
{
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
			// �Է¿� ���� �ӵ� ����
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

			// �ӵ��� ���� ��ġ�� �ٲ۴�.
			x_ += velocity_;
			world.resolveCollision(volume_, x_, y_, velocity_);

			// ��������Ʈ�� �׸���.
			Sprite* sprite = &spriteStand_;
			if (velocity_ < 0) { sprite = &spriteWalkLeft_; }
			else if (velocity_ > 0) { sprite = &spriteWaltRight_; }

			graphics.draw(*sprite, x_, y_);
		}
	};
}