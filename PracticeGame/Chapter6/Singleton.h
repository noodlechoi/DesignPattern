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