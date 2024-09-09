#pragma once

const int MAX_OBSERVERS{ 5 };

class Entity
{
public:
	bool isHero() const { return false; }
	bool isStandingOn(int surface) const { return false; }
	bool isOnSurface() { return true; }
	void accelerate(int force) {}
	void update() {}
};


enum Event
{
	EVENT_ENTITY_FELL,
	ACHIEVEMENT_FELL_OFF_BRIDGE,
};

enum Achievement
{
	ACHIEVEMENT_FELL_OFF_BRIDGE
};

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity& entity, Event event) = 0;
	// 아무 매개변수 상관없음. 보통 알림을 보내는 객체와 다른 구체적인 정보를 담은 일반적인 데이터를 매개변수로 넘김.
};

class Achievements : public Observer
{
private:
	void unlock(Achievement achievement)
	{
		// 업적이 잠겨 있으면 잠금해제
	}
	bool heroIsOnBridge_;
public:
	virtual void onNotify(const Entity& entity, Event event) override
	{
		switch (event) {
		case EVENT_ENTITY_FELL:
			if (entity.isHero() && heroIsOnBridge_) {
				unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
			}
			break;
			// 그 외 이번트 처리
			// heroIsOnBridge_ 값 업데이트
		default:
			break;
		}
	}
};

class Subject
{
private:
	Observer* observers_[MAX_OBSERVERS];
	int numObervers_{};
protected:
	void notify(const Entity& entity, Event event)
	{
		for (int i = 0; i < numObervers_; ++i) {
			// 아래 함수 호출 시 observer_에 관찰자가 더해지거나 빠지지 않는다고 가정한다.
			observers_[i]->onNotify(entity, event);
		}
	}
public:
	void addObserver(Observer* observer)
	{
		// 추가
	}
	void removeObserver(Observer* observer)
	{
		// 제거
	}
};

class Physics :public Subject
{
public:
	void updateEntity(Entity& entity) {}
};