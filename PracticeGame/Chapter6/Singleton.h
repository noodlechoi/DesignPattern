#pragma once

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