#include "System/Logger.h" 
using namespace GS3;
	int main ()
	{
		Util::Logger* logger = Util::Logger::CreateLogger ("", "Log.txt", true);
		logger->Log(Util::Logger::Priority::INFO, "Hello World");
		delete logger;
		return 1;
	}