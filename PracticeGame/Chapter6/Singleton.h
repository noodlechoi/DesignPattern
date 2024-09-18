#pragma once
#include <string>

namespace Singleton
{
	class FileSystem
	{
	private:
		FileSystem() {}
		static FileSystem* instance_;
	public:
		static FileSystem& instance()
		{
			// 게으른 초기화
			if (instance_ == nullptr) {
				instance_ = new FileSystem();
			}

			return *instance_;
		}
	};
	
	// 요즘
	// 스레드 안전하게 초기화하는 것을 보장
	class FileSystem_
	{
	private:
		FileSystem_() {}
	public:
		static FileSystem_& instance()
		{
			static FileSystem_* instance = new FileSystem_();
			return *instance;
		}
	};
}

namespace Succession
{
	class FileSystem
	{
	protected:
		FileSystem() {}
	public:
		static FileSystem& instance();

		virtual ~FileSystem() {}
		virtual char* readFile(char* path) = 0;
		virtual void wirteFile(char* path, char* contents) = 0;
	};

	class PS3FileSystem : public FileSystem
	{
		virtual char* readFile(char* path) override {}
		virtual void wirteFile(char* path, char* contents) override {}
	};

	class WillFileSystem : public FileSystem
	{
		virtual char* readFile(char* path) override {}
		virtual void wirteFile(char* path, char* contents) override {}
	};
}

namespace Alternative
{
	// 대안1
	class FileSystem
	{
	private:
		static bool instantiated_;
	public:
		FileSystem()
		{
			// assert(!insantiated_); 오류
			instantiated_ = true;
		}
		~FileSystem()
		{
			instantiated_ = false;
		}
	};

	bool FileSystem::instantiated_ = false;

	// 대안2
	// 상위 클래스로부터 얻기
	class Log
	{
	public:
		void write(std::string s) {}
	};

	class GameObject
	{
	protected:
		Log& getLog() { return log_; }
	private:
		static Log& log_;
	};

	class Enemy : public GameObject
	{
		void doSometing()
		{
			getLog().write("I can log!");
		}
	};

	// 이미 전역인 객체로부터 얻기
	class Game
	{
	private:
		static Game instance_;
		Log* log_;
		FileSystem* filesystem_;
		//AudioPlayer* audioPlayer;
	public:
		static Game& instance() { return instance_; }
		Log& getLog() { return *log_; }
		// 기타 등등
	};
}