#pragma once

#include <string>
#include <iostream>

class Logger
{
public:
	static void preinput(const std::string& message) {
		std::cout << message;
	}

	static void info(const std::string& message) {
		std::cout << message << std::endl;
	}
};
