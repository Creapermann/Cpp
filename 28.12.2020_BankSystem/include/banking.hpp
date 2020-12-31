#pragma once

#include <vector>

#include "account.hpp"

class Banking
{
public:
	//Constructor
	Banking();

	//Methods connected to accounts
	void menu();
	void new_acc();
	void see();
	void showAll();
	void edit();
	void transact();
	void erase();

	//UI Methods
	void continueScreen();
	
	//Helping Methods
	void getInfoForAccount(Account acc);
	void removeAccountByID(int id);


private:
	std::vector<Account> accountVec;
};