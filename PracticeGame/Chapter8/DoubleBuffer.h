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
		// 비디오 드라이버가 화면을 그리기 위해 버퍼 값을 읽을 때 출력 => getPixerls()
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
			// 버퍼 포인터만 교체
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
#include <iostream>
namespace AI
{
	class Actor
	{
	private:
		bool slapped_;
	public:
		Actor() : slapped_{false} {}
		virtual ~Actor() {}
		virtual void update() = 0;
		void reset() { slapped_ = false; }
		void slap() { slapped_ = true; }
		bool wasSlapped() { return slapped_; }
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
				std::cout << "뺨" << std::endl;
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
				actors_[i]->reset();
			}
		}
	};
}