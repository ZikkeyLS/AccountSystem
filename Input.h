#pragma once

#include <string>
#include <iostream>

class Input
{
public:
	static std::string GetString()
	{
		std::string message;
		std::getline(std::cin, message);
		return message;
	}
};
