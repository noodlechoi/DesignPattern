#pragma once
namespace dataLocal
{
	class AIComponent
	{
	private:
		// �޽�, �ؽ�ó, ���̴� ���
		// ��ǥ, ��� ���
	public:
		void update() { /*�۾� �� ���¸� �����Ѵ�.*/ }
	};
	
	class PhysicsComponent
	{
	private:
		// ��ü, �ӵ�, ���� ���
	public:
		void update() { /*�۾� �� ���¸� �����Ѵ�.*/ }
	};

	class RenderComponent
	{
	private:
		// �޽�, �ؽ�ó, ���̴� ���
	public:
		void update() { /*�۾� �� ���¸� �����Ѵ�.*/ }
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

	// ��ƼŬ �ý���
	class Particle
	{
	public:
		void update() {}
		bool isActive() {}
 	};

	class ParticleSystem // ��ü Ǯ�� ����
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