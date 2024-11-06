#pragma once

namespace serviceLocator
{
	// service
	class Audio
	{
	public:
		virtual ~Audio() {}
		virtual void playSound(int soundID) = 0;
		virtual void stopSound(int soundID) = 0;
		virtual void stopAllSounds() = 0;
	};

	// service provider
	class ConsoleAudio : public Audio
	{
	public:
		virtual void playSound(int soundID)
		{
			// �ܼ��� ����� API�� �̿��� ���带 ���
		}
		virtual void stopSound(int soundID)
		{
			// �ܼ��� ����� API�� �̿��� ���带 ����
		}
		virtual void stopAllSounds()
		{
			// �ܼ��� ����� API�� �̿��� ��� ���带 ����
		}
	};

	// �� ���� ������ ����
	class NullAudio : public Audio
	{
	public:
		virtual void playSound(int soundID)
		{
			// �ƹ��͵� ���� �ʴ´�.
		}
		virtual void stopSound(int soundID)
		{
			// �ƹ��͵� ���� �ʴ´�.
		}
		virtual void stopAllSounds()
		{
			// �ƹ��͵� ���� �ʴ´�.
		}
	};

	// Locator, ������ ���� ��� ���
	class Locator
	{
	private:
		static Audio* service_;
		static NullAudio nullService_;
	public:
		static void initialize()
		{
			service_ = &nullService_;
		}
		static Audio& getAudio() { return *service_; } // �߰� ����, �����Ͱ� �ƴ� ���۷����� ��ȯ(p309 ����)
		static void provide(Audio* service)
		{ 
			if (service == nullptr) {
				// �� ���񽺷� �������´�.
				service_ = &nullService_;
			}
			else {
				service_ = service;
			}
		}
	};

	// �α� ���ڷ�����
	class LoggedAudio : public Audio
	{
	private:
		void log(const char* message) { /*�α׸� ����� �ڵ�*/ }
		Audio& wrapped_;
	public:
		LoggedAudio(Audio &wrapped) : wrapped_{wrapped} {}
		virtual void playSound(int soundID)
		{
			log("���� ���");
			wrapped_.playSound(soundID);
		}
		virtual void stopSound(int soundID)
		{
			log("���� ����");
			wrapped_.stopSound(soundID);
		}
		virtual void stopAllSounds()
		{
			log("��� ���� ����");
			wrapped_.stopAllSounds();
		}
	};

	// ����� �α� ��� on
	void enableAudioLogging()
	{
		// ���� ���񽺸� ���ڷ���Ʈ�Ѵ�.
		Audio* service = new LoggedAudio(Locator::getAudio());
		// �� ������ �ٲ�ġ�� �Ѵ�.
		Locator::provide(service);
	}
}