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
			// ������ �ʱ�ȭ
			if (instance_ == nullptr) {
				instance_ = new FileSystem();
			}

			return *instance_;
		}
	};
	
	// ����
	// ������ �����ϰ� �ʱ�ȭ�ϴ� ���� ����
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
	// ���1
	class FileSystem
	{
	private:
		static bool instantiated_;
	public:
		FileSystem()
		{
			// assert(!insantiated_); ����
			instantiated_ = true;
		}
		~FileSystem()
		{
			instantiated_ = false;
		}
	};

	bool FileSystem::instantiated_ = false;

	// ���2
	// ���� Ŭ�����κ��� ���
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

	// �̹� ������ ��ü�κ��� ���
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
		// ��Ÿ ���
	};
}