#pragma once
#include "Database.h"
#include "Input.h"

enum AccountState 
{
	NotExist = 0,
	Created
};

class AccountSystem 
{
public:
	AccountSystem();
	void Register();
	void Login();
	AccountState GetState();
private:
	Database database;
};
