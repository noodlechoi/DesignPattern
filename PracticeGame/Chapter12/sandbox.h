#pragma once
class Superpower
{
public:
	virtual ~Superpower() {}
protected:
	virtual void activate() = 0;	// 샌드박스 메서드
	void move(double x, double y, double z) {}
	void playSound(int sound, double volume) {}
	void spawnParticles(int type, int count) {}
};

class SkyLaunch : public Superpower
{
protected:
	virtual void activate() override
	{
		playSound(0, 1.0f);
		spawnParticles(0, 10);
		move(0, 0, 20);
	}
};