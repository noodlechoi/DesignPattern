#pragma once
namespace dataLocal
{
	class AIComponent
	{
	private:
		// 메시, 텍스처, 쉐이더 등등
		// 목표, 기분 등등
	public:
		void update() { /*작업 후 상태를 변경한다.*/ }
	};
	
	class PhysicsComponent
	{
	private:
		// 강체, 속도, 질량 등등
	public:
		void update() { /*작업 후 상태를 변경한다.*/ }
	};

	class RenderComponent
	{
	private:
		// 메시, 텍스처, 쉐이더 등등
	public:
		void update() { /*작업 후 상태를 변경한다.*/ }
	};

	class GameEntity
	{
	private:
		AIComponent* ai_;
		PhysicsComponent* physics_;
		RenderComponent* render_;
	public:
		GameEntity(AIComponent* ai, PhysicsComponent* physics, RenderComponent* render) : 
			ai_{ai}, physics_{physics},render_{render}
		{}
		AIComponent* ai() { return ai_; }
		PhysicsComponent* physics() { return physics_; }
		RenderComponent* render() { return render_; }

	};

	// 파티클 시스템
	class Particle
	{
	public:
		void update() {}
		bool isActive() {}
 	};

	class ParticleSystem // 객체 풀의 일종
	{
	private:
		static const int MAX_PARTICLES = 100000;
		int numParticles_;
		Particle particles_[MAX_PARTICLES];
	public:
		ParticleSystem() : numParticles_{} {}
		void update()
		{
			for (int i = 0; i < numParticles_; ++i) {
				if(particles_[i].isActive())
					particles_[i].update();
			}
		}
	};
}