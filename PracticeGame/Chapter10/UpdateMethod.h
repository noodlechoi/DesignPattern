#pragma once

class Entity
{
protected:
	double x_;
	double y_;
public:
	Entity() : x_{}, y_{} {}
	virtual ~Entity() {}
	virtual void update() = 0;
	virtual void update(double) = 0;

	double x() const { return x_; }
	double y() const { return y_; }
	void setX(double x) { x_ = x; }
	void setY(double y) { y_ = y; }
};

class World
{
private:
	static const int MAX_ENTITIES = 5;
	Entity* entities_[MAX_ENTITIES];	// �÷��� Ŭ���� ����ϱ�
	int numEntities_;
public:
	World() : numEntities_{} {}
	void gameLoop()
	{
		while (true) {
			// ���� �Է� ó��

			// ������Ʈ
			for (int i = 0; i < numEntities_; ++i) {
				entities_[i]->update();
			}
			// ����, ������
		}
	}

}; class Skeleton : public Entity
{
private:
	bool patrollingLeft_;
public:
	Skeleton() : patrollingLeft_{false} {}
	// ���� �ð� ����
	virtual void update() override
	{
		if (patrollingLeft_) {
			setX(x() - 1);
			if (x() == 0) patrollingLeft_ = false;
		}
		else {
			setX(x() + 1);
			if (x() == 100) patrollingLeft_ = true;
		}
	}
	// ���� �ð� ����
	virtual void update(double elapsed) override
	{
		if (patrollingLeft_) {
			x_ -= elapsed;
			if (x_ <= 0) {
				patrollingLeft_ = false;
				x_ = -x_;
			}
		}
		else {
			x_ += elapsed;
			if (x_ <= 0) {
				patrollingLeft_ = true;
				x_ = 100 - (x_ - 100);
			}
		}
	}
};

class Statue : public Entity
{
private:
	int frames_;
	int delay_;

	void shootLightning() {}
public:
	Statue(int delay) : frames_{}, delay_{delay} {}

	virtual void update() override
	{
		if (++frames_ == delay_) {
			shootLightning();

			// Ÿ�̸� �ʱ�ȭ
			frames_ = 0;
		}
	}
};