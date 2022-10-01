#pragma once
#include <ofstream>
#include <string>
class Logger
{
	enum Priority{LOG,WARNING,CRITICAL,CRASH};
	std::ofstream
	Logger(std::string path, std::string name, bool overwrite=true);
	bool Log(Priority, std::string& message);
};