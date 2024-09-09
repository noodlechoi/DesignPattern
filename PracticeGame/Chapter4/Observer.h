#pragma once

namespace ObserverPattern
{
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
		// �ƹ� �Ű����� �������. ���� �˸��� ������ ��ü�� �ٸ� ��ü���� ������ ���� �Ϲ����� �����͸� �Ű������� �ѱ�.
	};

	class Achievements : public Observer
	{
	private:
		void unlock(Achievement achievement)
		{
			// ������ ��� ������ �������
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
				// �� �� �̹�Ʈ ó��
				// heroIsOnBridge_ �� ������Ʈ
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
				// �Ʒ� �Լ� ȣ�� �� observer_�� �����ڰ� �������ų� ������ �ʴ´ٰ� �����Ѵ�.
				observers_[i]->onNotify(entity, event);
			}
		}
	public:
		void addObserver(Observer* observer)
		{
			// �߰�
		}
		void removeObserver(Observer* observer)
		{
			// ����
		}
	};

	class Physics :public Subject
	{
	public:
		void updateEntity(Entity& entity) {}
	};
}


namespace Node
{
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

	class Observer
	{
	private:
		friend class Subject;
		Observer* next_;
	public:
		Observer() : next_{ nullptr } {}
		virtual void onNotify(const Entity& entity, Event event) = 0;
	};

	class Subject
	{
	private:
		Observer* head_;
	public:
		Subject() : head_{ nullptr } {}
		// �� ������ �߰�
		void addObserver(Observer* observer)
		{
			observer->next_ = head_;
			head_ = observer;
		}
		void removeObserver(Observer* observer)
		{
			if (head_ == observer) {
				head_ = observer->next_;
				observer->next_ = nullptr;
				return;
			}

			Observer* current = head_;
			while (current != nullptr) {
				if (current->next_ == observer) {
					current->next_ = observer->next_;
					observer->next_ = nullptr;
					return;
				}
				current = current->next_;
			}
		}
		void notify(const Entity& entity, Event event)
		{
			Observer* observer = head_;
			while (observer != nullptr) {
				observer->onNotify(entity, event);
				observer = observer->next_;
			}
		}
	};
}

