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

namespace freeList // 빈칸 리스트 기법
{
	class Particle
	{
	private:
		int framesLeft_;
		union {
			// 사용 중일 때의 상태
			struct {
				double x, y;
				double xVel, yVel;
			} live;

			// 사용중이 아닐 때의 상태
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

	bool Particle::animate()	// 죽을 때 true 반환
	{
		if (!inUse()) return false;

		framesLeft_--;
		state_.live.x += state_.live.xVel;
		state_.live.y += state_.live.yVel;

		return framesLeft_ == 0;
	}

	// 객체 풀 클래스
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
		// 처음 파티클부터 사용 가능하다.
		firstAvailable_ = &particles_[0];

		// 모든 파티클은 다음 파티클을 가리킨다.
		for (int i = 0; i < POOL_SIZE - 1; ++i) {
			particles_[i].setNext(&particles_[i + 1]);
		}

		// 마지막 파티클에서 리스트를 종료한다.
		particles_[POOL_SIZE - 1].setNext(nullptr);
	}

	void ParticlePool::create(double x, double y, double xVel, double yVel, int lifetime)
	{
		// 풀이 비어 있지 않은지 확인한다.
		assert(firstAvailable_ != nullptr);

		// 얻은 파티클을 빈칸 목록에서 제거한다.
		Particle* newParticle = firstAvailable_;
		firstAvailable_ = newParticle->getNext();
		newParticle->init(x, y, xVel, yVel, lifetime);
	}

	void ParticlePool::animate()
	{
		for (int i = 0; i < POOL_SIZE; ++i) {
			if (particles_[i].animate()) {
				// 방금 죽은 파티클을 빈칸 리스트 앞에 추가한다.
				particles_[i].setNext(firstAvailable_);
				firstAvailable_ = &particles_[i];
			}
		}
	}

	void assert(bool) {}
}