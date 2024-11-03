#pragma once

class SoundId
{
};

class ResourceId
{
};

struct PlayMessage
{
	SoundId id;
	int volume;
};

void assert(bool)
{}

ResourceId loadSound(SoundId)
{}

int findOpenChannel()
{}

void startSound(ResourceId, int, int)
{}

namespace standardBuffer
{
	class Audio
	{
	private:
		static const int MAX_PENDING = 16;
		static PlayMessage pending_[MAX_PENDING];
		static int numPending_;
	public:
		static void init() { numPending_ = 0; }
		void playSound(SoundId id, int volume)
		{
			assert(numPending_ < MAX_PENDING);
			pending_[numPending_].id = id;
			pending_[numPending_].volume = volume;
			numPending_++;
		}
		static void update()
		{
			for (int i = 0; i < numPending_; ++i) {
				ResourceId resource = loadSound(pending_[i].id);
				int channel = findOpenChannel();
				if (channel == -1) return;
				startSound(resource, channel, pending_[i].volume);
			}
		}
	};
}

namespace circleBuffer
{
	class Audio
	{
	private:
		static int head_;
		static int tail_;
		static const int MAX_PENDING = 16;
		static PlayMessage pending_[MAX_PENDING];
	public:
		static void init()
		{
			head_ = 0;
			tail_ = 0;
		}
		void playSound(SoundId id, int volume)
		{
			assert((tail_ + 1) % MAX_PENDING != head_);
			pending_[tail_].id = id;
			pending_[tail_].volume = volume;
			tail_ = (tail_ + 1) % MAX_PENDING;
		}
		void update()
		{
			// 보류된 요청이 없다면 아무것도 하지 않는다.
			if (head_ == tail_) return;
			ResourceId resource = loadSound(pending_[head_].id);
			int channel = findOpenChannel();
			if (channel == -1) return;
			startSound(resource, channel, pending_[head_].volume);
			head_ = (head_ + 1) % MAX_PENDING;
		}
	};
}