#include "Singleton.h"

using namespace Succession;

FileSystem& FileSystem::instance()
{
#if PLATFORM == PLAYSTATION3
	static FileSystem* instance = new PS3FileSystem();
#elif PLATFORM == WII
	static FileSystem* instance = new WillFileSystem();
#endif
	return *instance;
}