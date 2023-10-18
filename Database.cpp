#include "Database.h"

Database::Database(const std::string& fileName)
{
	fileName_ = fileName;
	fullName = fileName + ".data";
}

void Database::write(const std::string& data)
{
	if (exists() == false) {
		Logger::info("Internal Error: We can't write to nonexistent file!");
		return;
	}
	std::ofstream file;
	file.open(fullName);

	if (file.is_open()) {
		file << Utility::textToBinary(data) << std::endl;
	}

	file.close();
}

std::string Database::read()
{
	if (exists() == false) {
		Logger::info("Internal Error: We can't get data of nonexistent file!");
		return "";
	}

	std::string outputLine;
	std::ifstream file;
	file.open(fullName);

	if (file.is_open()) {
		std::getline(file, outputLine);
		file.close();
		return Utility::binaryToText(outputLine);
	}
}

bool Database::createDB()
{
	if (exists()) {
		return false;
	}

	std::ofstream { fullName };
	return true;
}

bool Database::deleteDB()
{
	if (exists() == false) {
		return false;
	}

	std::filesystem::remove(fullName);
	return true;
}

bool Database::exists()
{
	return std::filesystem::exists(fullName);
}
