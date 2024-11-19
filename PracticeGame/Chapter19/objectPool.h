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

	// ��ü Ǯ Ŭ����
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
		// ��� ������ ��ƼŬ�� ã�´�.
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

namespace freeList // ��ĭ ����Ʈ ���
{
	class Particle
	{
	private:
		int framesLeft_;
		union {
			// ��� ���� ���� ����
			struct {
				double x, y;
				double xVel, yVel;
			} live;

			// ������� �ƴ� ���� ����
			Particle* next;
		} state_;
	public:
		Particle() : framesLeft_{} {}
		void init(double x, double y, double xVel, double yVel, int lifetime);
		bool animate();
		bool inUse() const { return framesLeft_ > 0; }

		Particle* getNext() const { return state_.next; }
		void setNext(Particle* next)
		{
			state_.next = next;
		}
	};

	void Particle::init(double x, double y, double xVel, double yVel, int lifetime)
	{
		state_.live.x = x;
		state_.live.y = y;
		state_.live.xVel = xVel;
		state_.live.yVel = yVel;
		framesLeft_ = lifetime;
	}

	bool Particle::animate()	// ���� �� true ��ȯ
	{
		if (!inUse()) return false;

		framesLeft_--;
		state_.live.x += state_.live.xVel;
		state_.live.y += state_.live.yVel;

		return framesLeft_ == 0;
	}

	// ��ü Ǯ Ŭ����
	class ParticlePool
	{
	private:
		static const int POOL_SIZE = 100;
		Particle particles_[POOL_SIZE];

		Particle* firstAvailable_;
	public:
		ParticlePool();
		void create(double x, double y, double xVel, double yVel, int lifetime);
		void animate();
	};

	ParticlePool::ParticlePool()
	{
		// ó�� ��ƼŬ���� ��� �����ϴ�.
		firstAvailable_ = &particles_[0];

		// ��� ��ƼŬ�� ���� ��ƼŬ�� ����Ų��.
		for (int i = 0; i < POOL_SIZE - 1; ++i) {
			particles_[i].setNext(&particles_[i + 1]);
		}

		// ������ ��ƼŬ���� ����Ʈ�� �����Ѵ�.
		particles_[POOL_SIZE - 1].setNext(nullptr);
	}

	void ParticlePool::create(double x, double y, double xVel, double yVel, int lifetime)
	{
		// Ǯ�� ��� ���� ������ Ȯ���Ѵ�.
		assert(firstAvailable_ != nullptr);

		// ���� ��ƼŬ�� ��ĭ ��Ͽ��� �����Ѵ�.
		Particle* newParticle = firstAvailable_;
		firstAvailable_ = newParticle->getNext();
		newParticle->init(x, y, xVel, yVel, lifetime);
	}

	void ParticlePool::animate()
	{
		for (int i = 0; i < POOL_SIZE; ++i) {
			if (particles_[i].animate()) {
				// ��� ���� ��ƼŬ�� ��ĭ ����Ʈ �տ� �߰��Ѵ�.
				particles_[i].setNext(firstAvailable_);
				firstAvailable_ = &particles_[i];
			}
		}
	}

	void assert(bool) {}
}