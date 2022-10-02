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
			/// @brief Priority Enumeration for setting the priority of the log message 
			///| Level | Description |
			/// |----:|:----|
			/// |INFO|This should indicate a normal log message for the program (e.g logging initializations, file saves, progress starting or ending, etc)|
			/// |Warning|This should indicate a potentially error causing state that can be recovered from (e.g. file not found). These should also indicate that the programmer has created a system to recover from these states. In other words, if the program as is cannot recover, then it should be categorized in the more critical states|
			/// |Critical|These should indicate error causing states. Any state that does not allow the program to function as intended should be categorized here. They should not indicate a crash or it`s direct cause, however they can indicate the steps leading up to a crash.|
			/// |Crash|This should indicate that a crash has happened or will happen and log the relevant info here. Things that might be appropriate are, line numbers or file where this  crash occurred.|
			enum class Priority { INFO, WARNING, CRITICAL, CRASH };
			static Logger* createLogger (std::string path, std::string name, bool overwrite = false);
			void log (Priority priority, std::string& message);
			void log (Priority priority, const char* message);
			/// @brief Determines if the logger stream is still good.
			/// @return returns True if the logger file stream is still active, false otherwise 
			inline bool loggerGood() {return m_FileStream.good();}
			~Logger ();
		private:
			const std::string PriorityString_INFO = "[INFO] ";
			const std::string PriorityString_WARNING = "[WARNING] ";
			const std::string PriorityString_CRITICAL = "[CRITICAL] ";
			const std::string PriorityString_CRASH = "[CRASH] ";
			std::string getPriorityString(Priority& priority);
			Logger (std::string fullPath);
			std::ofstream m_FileStream;

		};
	}
}