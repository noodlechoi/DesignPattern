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
	double getHeroX() { return 0.0f; }
	double getHeroY() { return 0.0f; }
	double getHeroZ() { return 0.0f; }
};

class SkyLaunch : public Superpower
{
protected:
	virtual void activate() override
	{
		if (getHeroZ() == 0) {
			// 땅이라면 공중으로
			playSound(0, 1.0f);
			spawnParticles(0, 10);
			move(0, 0, 20);
		}
		else if (getHeroZ() <= 10.0f) {
			// 거의 땅이라면 이중 점프
			playSound(0, 1.0f);
			move(0, 0, getHeroZ() - 20);
		}
		else {
			// 공중에 있으면 내려찍기
			playSound(0, 0.7f);
			spawnParticles(0, 1);
			move(0, 0, -getHeroZ());
		}
	}
};

namespace Modified
{
	class Superpower
	{
	private:
		SoundPlayer soundPlayer_;
	public:
		virtual ~Superpower() {}
	protected:
		virtual void activate() = 0;	// 샌드박스 메서드
		SoundPlayer& getSoundPlayer()
		{
			return soundPlayer_;
		}
	};

	class SoundPlayer
	{
		void playSound(int sound, double volume) {}
		void stopSound(int sound) {}
		void setVolume(int sound) {}
	};
}