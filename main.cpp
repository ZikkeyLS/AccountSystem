#include "AccountSystem.h"

int main()
{
	AccountSystem account = AccountSystem();

	if (account.GetState() == AccountState::NotExist) {
		account.Register();
	}

	account.Login();

	Input::GetString();
	return 0;
}
