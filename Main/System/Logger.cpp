#include "Logger.h"
namespace GS3
{
	namespace Util
	{
		/// @brief A Util::logger factory. It checks to make sure that if the file already exists if you do not want to
		/// overwrite it. 
		/// @param path The folder path to the file you want to create
		/// @param name The name of the log file you want to create 
		/// @param overwrite The overwrite value. It asks if the file is already there, do you want to overwrite it. False by default
		/// @return Returns a pointer to a logger instance if good, nullptr otherwise. 
		/// Note: If the file already exists and the overwrite flag is false, then return nullptr.
		Logger* Logger::createLogger (std::string path, std::string name, bool overwrite)
		{
			Logger* ret;
			std::string fullPath = path + name;
			if ( !overwrite )
			{
				std::ifstream file (fullPath);
				if ( file.good () )
					return nullptr;
			}
			ret = new Logger (fullPath);
			if ( ret->loggerGood () ) return ret;
			else
			{
				delete ret;
				return nullptr;
			}
		}
		/// @brief Logs a given message to the log output file. Prepeneded will be the priority and the time.
		/// @param priority The Priority level of the message. For more info see Logger::Priority
		/// @param message The message you wish to put into the log file
		void Logger::log (Priority priority, const char* message)
		{
			log (priority, std::string (message));
		}
		/// @brief Logs a given message to the log output file. Prepeneded will be the priority and the time.
		/// @param priority The Priority level of the message. For more info see Logger::Priority
		/// @param message The message you wish to put into the log file
		void Logger::log (Priority priority, std::string& message)
		{
			std::string fullMessage;
			fullMessage += getPriorityString(priority);
			time_t now;
			time (&now);
			tm* nowLocal = localtime (&now);
			fullMessage = fullMessage + " " + std::to_string (nowLocal->tm_hour) + ":"
				+ std::to_string (nowLocal->tm_min) + ":"
				+ std::to_string (nowLocal->tm_sec) + " : " + message;
			m_FileStream << fullMessage;
			m_FileStream.flush ();
		}
		/// @brief Destructor
		Logger::~Logger ()
		{
			m_FileStream.close ();
		}
		/// @brief 
		/// @param priority The priority level being queried. See Logger::Priority for more info
		/// @return The string associated with the given priority level
		std::string Logger::getPriorityString (Priority& priority)
		{
			switch ( priority )
			{
				case Priority::INFO:
					return PriorityString_INFO;
				case Priority::WARNING:
					return PriorityString_WARNING;
				case Priority::CRITICAL:
					return PriorityString_CRITICAL;
				case Priority::CRASH:
					return PriorityString_CRASH;
				default:
					return "";
			}
		}
		/// @brief Constructor
		/// @param fullPath Full path of the file including the file name 
		Logger::Logger (std::string fullPath)
			:m_FileStream (std::ofstream (fullPath))
		{}
	}
}