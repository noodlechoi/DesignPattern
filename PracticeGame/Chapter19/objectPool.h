#pragma once

namespace objectPool
{
	class Particle
	{
	private:
		int framesLeft_;
		double x_, y_;
		double xVel_, yVel_;
	public:
		Particle() : framesLeft_{} {}
		void init(double x, double y, double xVel, double yVel, int lifetime);
		void animate();
		bool inUse() const { return framesLeft_ > 0; }
	};

	void Particle::init(double x, double y, double xVel, double yVel, int lifetime)
	{
		x_ = x;
		y_ = y;
		xVel_ = xVel;
		yVel_ = yVel;
		framesLeft_ = lifetime;
	}

	void Particle::animate()
	{
		if (!inUse()) return;

		framesLeft_--;
		x_ += xVel_;
		y_ += yVel_;
	}

	// 객체 풀 클래스
	class ParticlePool
	{
	private:
		static const int POOL_SIZE = 100;
		Particle particles_[POOL_SIZE];
	public:
		void create(double x, double y, double xVel, double yVel, int lifetime);
		void animate();
	};

	void ParticlePool::create(double x, double y, double xVel, double yVel, int lifetime)
	{
		// 사용 가능한 파티클을 찾는다.
		for (int i = 0; i < POOL_SIZE; ++i) {
			if (!particles_[i].inUse()) {
				particles_[i].init(x, y, xVel, yVel, lifetime);
				return;
			}
		}
	}

	void ParticlePool::animate()
	{
		for (int i = 0; i < POOL_SIZE; ++i) {
			particles_[i].animate();
		}
	}
}