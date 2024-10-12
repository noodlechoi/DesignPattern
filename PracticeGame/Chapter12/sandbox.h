#pragma once
class Superpower
{
public:
	virtual ~Superpower() {}
protected:
	virtual void activate() = 0;	// ����ڽ� �޼���
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
			// ���̶�� ��������
			playSound(0, 1.0f);
			spawnParticles(0, 10);
			move(0, 0, 20);
		}
		else if (getHeroZ() <= 10.0f) {
			// ���� ���̶�� ���� ����
			playSound(0, 1.0f);
			move(0, 0, getHeroZ() - 20);
		}
		else {
			// ���߿� ������ �������
			playSound(0, 0.7f);
			spawnParticles(0, 1);
			move(0, 0, -getHeroZ());
		}
	}
};

// ���� ����� ���� Ŭ������ �ű��
namespace Modified
{
	class Superpower
	{
	private:
		SoundPlayer soundPlayer_;
	public:
		virtual ~Superpower() {}
	protected:
		virtual void activate() = 0;	// ����ڽ� �޼���
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

// ���� Ŭ���� �ʿ� ��ü ��� ���
namespace HowGet
{
	class ParticleSystem {};

	// 1. �����ڷ�
	class SuperPower
	{
	private:
		ParticleSystem* particles;
	public:
		SuperPower(ParticleSystem* particles) : particles{particles} {}
	};

	// ���� Ŭ�������� ������ �μ��� �޾ƾ� �Ѵٴ� ���� �߻�
	class SkyLaunch : public SuperPower
	{
	public:
		SkyLaunch(ParticleSystem* particles) : SuperPower(particles) {}
	};
}