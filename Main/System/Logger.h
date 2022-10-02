#pragma once
#include <fstream>
#include <string>
namespace GS3
{
	namespace Util
	{
		class Logger
		{
		public:
			enum class Priority { INFO, WARNING, CRITICAL, CRASH };
			static Logger* CreateLogger (std::string path, std::string name, bool overwrite = false);
			void Log (Priority priority, std::string& message);
			void Log (Priority priority, const char* message);
			~Logger ();
		private:
			Logger (std::string fullPath);
			std::ofstream m_FileStream;

		};
	}
}