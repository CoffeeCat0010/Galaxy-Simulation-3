#include "System/Logger.h" 
using namespace GS3;
	int main ()
	{
		Util::Logger* logger = Util::Logger::createLogger ("", "Log.txt", true);
		logger->log(Util::Logger::Priority::INFO, "Hello World");
		delete logger;
		return 1;
	}