#include "Logger.h"
namespace GS3
{
	namespace Util
	{
		Logger* Logger::CreateLogger (std::string path, std::string name, bool overwrite)
		{
			std::string fullPath = path + name;
			if ( !overwrite )
			{
				std::ifstream file (fullPath);
				if ( file.good () ) return nullptr;
			}
			return new Logger (fullPath);
		}
		void Logger::Log (Priority priority, const char* message)
		{
			Log(priority, std::string(message));
		}
		void Logger::Log (Priority priority, std::string& message)
		{
			std::string fullMessage;
			switch (priority)
			{
				case Priority::INFO:
					fullMessage = "[INFO] ";
						break;
				case Priority::WARNING:
					fullMessage = "[WARNING] ";
						break;
				case Priority::CRITICAL:
					fullMessage = "[CRITICAL] ";
						break;
				case Priority::CRASH:
					fullMessage = "[CRASH] ";
						break;
				default:
					break;
			}
			time_t now;
			time(&now);
			tm* nowLocal = localtime(&now);
			fullMessage = fullMessage + " " + std::to_string(nowLocal->tm_hour) + ":" 
																			+ std::to_string (nowLocal->tm_min) + ":" 
																			+ std::to_string (nowLocal->tm_sec) + " : " + message;
			m_FileStream << fullMessage;
			m_FileStream.flush();
		}
		Logger::~Logger ()
		{
			m_FileStream.close ();
		}
		Logger::Logger (std::string fullPath)
			:m_FileStream (std::ofstream (fullPath))
		{}
	}
}