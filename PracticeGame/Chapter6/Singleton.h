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