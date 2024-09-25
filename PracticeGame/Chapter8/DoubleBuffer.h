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
		Framebuffer buffer_;
	public:
		void draw()
		{
			buffer_.clear();
			buffer_.draw(1, 1);
			// �̶� ���� ����̹��� �ȼ� ���� ��ü�� ���� ���� �ִ�.
			buffer_.draw(2, 1);
			buffer_.draw(3, 1);
			buffer_.draw(4, 1);
		}
		Framebuffer& getBuffer() { return buffer_; }
	};
}
