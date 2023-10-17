#pragma once

#include <string>
#include <iostream>

class Logger
{
public:
	static void Log(const std::string& message)
	{
		std::cout << message << std::endl;
	}
};
