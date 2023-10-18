#include "AccountSystem.h"

const std::string FILENAME = "UserAccount";

AccountSystem::AccountSystem() : database(FILENAME)
{

}

void AccountSystem::Register()
{
	if (database.exists()) {
		Logger::info("Internal Error: Can't register, because account has been already created!");
		return;
	}

	Logger::info("REGISTRATION");
	Logger::preinput("Enter login: ");
	std::string login =	Input::GetString();
	Logger::preinput("Enter password: ");
	std::string passwordInitial = Input::GetString();
	Logger::preinput("Repeat password: ");
	std::string passwordRepeat = Input::GetString();

	if (passwordInitial == passwordRepeat) {
		database.createDB();
		database.write(std::format("{} {}", login, passwordInitial));
		Logger::info("REGISTRATION COMPLETE");
	}
	else {
		Logger::info("User Error: Passwords are not the same. Repeating operation of registration!");
		Register();
	}
}

void AccountSystem::Login()
{
	if (database.exists() == false) {
		Logger::info("Internal Error: Can't login, because account has not been presented!");
		return;
	}

	Logger::info("LOGIN");
	Logger::preinput("Enter login: ");
	std::string login = Input::GetString();
	Logger::preinput("Enter password: ");
	std::string password = Input::GetString();

	std::string data = database.read();
	auto parsedData = Utility::split(data);

	if (strcmp(login.c_str(), parsedData[0].c_str()) == 0 && strcmp(password.c_str(), parsedData[1].c_str()) == 0) {
		Logger::info("LOGIN SUCCESSFULLY");
	}
	else {
		Logger::info("User Error: Login or password aren't correct. Repeating operation of login!");
		Login();
	}
}

AccountState AccountSystem::GetState()
{
	return database.exists() ? AccountState::Created : AccountState::NotExist;
}

void dbCoreTest()
{
	Database db = Database(FILENAME);

	if (db.exists() == false) {
		db.createDB();
	}

	db.write("TestStuff");
	Logger::info("Written data: " + db.read());
}
