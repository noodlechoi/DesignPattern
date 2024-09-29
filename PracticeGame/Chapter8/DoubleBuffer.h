#pragma once

#define WHITE 'w'
#define BLACK 'b'

namespace DoubleBuffer
{
	class Framebuffer
	{
	private:
		static const int WIDTH{ 160 };
		static const int HEIGHT{ 120 };

		char pixels_[WIDTH * HEIGHT];
	public:
		Framebuffer() { clear(); }
		void clear()
		{
			for (int i = 0; i < WIDTH * HEIGHT; ++i) {
				pixels_[i] = WHITE;
			}
		}
		void draw(int x, int y)
		{
			pixels_[(WIDTH * y) + x] = BLACK;
		}
		// ���� ����̹��� ȭ���� �׸��� ���� ���� ���� ���� �� ��� => getPixerls()
		const char* getPixerls() { return pixels_; }
	};

	class Scene
	{
	private:
		Framebuffer buffer_[2];
		Framebuffer* current_;
		Framebuffer* next_;
		void swap()
		{
			// ���� �����͸� ��ü
			Framebuffer* temp = current_;
			current_ = next_;
			next_ = temp;
		}
	public:
		Scene() : current_{&buffer_[0]}, next_{ &buffer_[1] } {}
		void draw()
		{
			next_->clear();
			next_->draw(1, 1);
			// ...
			next_->draw(4, 1);
			swap();
		}
		Framebuffer& getBuffer() { return *current_; }
	};
}

namespace AI
{
	class Actor
	{
	private:
		bool currentSlapped_;
		bool nextSlapped_;
	public:
		Actor() : currentSlapped_{false} {}
		virtual ~Actor() {}
		virtual void update() = 0;
		void swap()
		{
			// ���� ��ü
			currentSlapped_ = nextSlapped_;
			// ���� ���� �ʱ�ȭ
			nextSlapped_ = false;
		}
		void slap() { nextSlapped_ = true; }
		bool wasSlapped() { return currentSlapped_; }
 	};

	class Comedian : public Actor
	{
	private:
		Actor* facing_;
	public:
		void face(Actor* actor) { facing_ = actor; }
		virtual void update()
		{
			if (wasSlapped()) {
				facing_->slap();
			}
		}
	};

	class Stage
	{
	private:
		static const int NUM_ACTORS = 3;
		Actor* actors_[NUM_ACTORS];
	public:
		void add(Actor* actor, int index)
		{
			actors_[index] = actor;
		}
		void update()
		{
			for (int i = 0; i < NUM_ACTORS; ++i) {
				actors_[i]->update();
			}
			for (int i = 0; i < NUM_ACTORS; ++i) {
				actors_[i]->swap();
			}
		}
	};
}