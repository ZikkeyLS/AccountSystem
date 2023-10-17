#include "Database.h"

const std::string FILENAME = "UserAccount";

int main()
{
	bool running = true;
	while (running)
	{

	}

	Logger::Log("End of working cycle.");
	return 0;
}


void dbCoreTest() 
{
	Database db = Database(FILENAME);

	if (db.exists() == false)
		db.createDB();

	db.write("TestStuff");
	Logger::Log("Written data: " + db.read());
}
