#pragma once

#include "Logger.h"
#include "Utility.h"
#include <filesystem>
#include <fstream>

class Database 
{
public:
	Database(const std::string& fileName);

	void write(const std::string& data);
	std::string read();

	bool createDB();
	bool deleteDB();
	bool exists();
private:
	std::string fileName_;
	std::string fullName;
};
