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
			// 콘솔의 오디오 API를 이용해 사운드를 출력
		}
		virtual void stopSound(int soundID)
		{
			// 콘솔의 오디오 API를 이용해 사운드를 중지
		}
		virtual void stopAllSounds()
		{
			// 콘솔의 오디오 API를 이용해 모든 사운드를 중지
		}
	};

	// 널 서비스 제공자 정의
	class NullAudio : public Audio
	{
	public:
		virtual void playSound(int soundID)
		{
			// 아무것도 하지 않는다.
		}
		virtual void stopSound(int soundID)
		{
			// 아무것도 하지 않는다.
		}
		virtual void stopAllSounds()
		{
			// 아무것도 하지 않는다.
		}
	};

	// Locator, 의존성 주입 기법 사용
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
		static Audio& getAudio() { return *service_; } // 중개 역할, 포인터가 아닌 레퍼런스로 반환(p309 참고)
		static void provide(Audio* service)
		{ 
			if (service == nullptr) {
				// 널 서비스로 돌려놓는다.
				service_ = &nullService_;
			}
			else {
				service_ = service;
			}
		}
	};

	// 로그 데코레이터
	class LoggedAudio : public Audio
	{
	private:
		void log(const char* message) { /*로그를 남기는 코드*/ }
		Audio& wrapped_;
	public:
		LoggedAudio(Audio &wrapped) : wrapped_{wrapped} {}
		virtual void playSound(int soundID)
		{
			log("사운드 출력");
			wrapped_.playSound(soundID);
		}
		virtual void stopSound(int soundID)
		{
			log("사운드 중지");
			wrapped_.stopSound(soundID);
		}
		virtual void stopAllSounds()
		{
			log("모든 사운드 중지");
			wrapped_.stopAllSounds();
		}
	};

	// 오디오 로그 기능 on
	void enableAudioLogging()
	{
		// 기존 서비스를 데코레이트한다.
		Audio* service = new LoggedAudio(Locator::getAudio());
		// 이 값으로 바꿔치기 한다.
		Locator::provide(service);
	}
}