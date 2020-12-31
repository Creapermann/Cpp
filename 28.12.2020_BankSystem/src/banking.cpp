#include <iostream>

#include "banking.hpp"


Banking::Banking() {};


void Banking::continueScreen() {
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "Press 1 to go back to menu or press 9 to quit the application!" << std::endl;

	int temp;
	std::cin >> temp;

	if (temp == 1)
		menu();
	else
		exit(EXIT_SUCCESS);
}



void Banking::menu() {
	system("CLS");

	std::cout << "1. Create new account" << std::endl;
	std::cout << "2. Update information of an existing account" << std::endl;
	std::cout << "3. For transactions" << std::endl;
	std::cout << "4. Check the details of an existing account" << std::endl;
	std::cout << "5. Removing an existent account" << std::endl;
	std::cout << "6. Show all existent accounts" << std::endl;
	std::cout << "7. Exit" << std::endl;

	int temp;
	std::cin >> temp;

	switch (temp) {
	case 1:
		new_acc();
		break;
	case 2:
		edit();
		break;
	case 3:
		transact();
		break;
	case 4:
		see();
		break;
	case 5:
		erase();
		break;
	case 6:
		showAll();
	case 7:
		exit(EXIT_SUCCESS);
	default:
		menu();
		break;
	}
}


void Banking::new_acc() {
	system("CLS");


	std::string firstname;
	std::string lastname;
	std::string citizenShip;
	int phoneNumber;

	std::cout << "Your firstname: ";
	std::cin >> firstname;

	std::cout << "Your lastname: ";
	std::cin >> lastname;

	std::cout << "Your citizen: ";
	std::cin >> citizenShip;

	std::cout << "Your phone number: ";
	std::cin >> phoneNumber;


	Account acc = Account(accountVec.size() + 1, firstname, lastname, citizenShip, phoneNumber);

	accountVec.push_back(acc);

	std::cout << "\nYour account has been created succesfully!" << std::endl;

	continueScreen();
}


void Banking::edit() {
	system("CLS");

	std::cout << "Type in the name of the account you want to edit data for!" << std::endl;

	std::cout << "firstname: ";
	std::string firstname;
	std::cin >> firstname;

	std::cout << "lastname: ";
	std::string lastname;
	std::cin >> lastname;

	system("CLS");

	bool wasFound = false;
	for (auto& user : accountVec) {
		wasFound = true;
		if (user.getFirstName() == firstname && user.getLastName() == lastname) {

			//Firstname
			std::cout << "Type in a '-' if you dont wanna change the user data!" << std::endl;
			std::cout << "firstname: " << std::endl;
			std::cout << "old firstname: " << user.getFirstName() << std::endl;
			std::cout << "new firstname: ";

			std::string newFirstName;
			std::cin >> newFirstName;

			if (newFirstName != "-") {
				user.setFirstname(newFirstName);
			}
			system("CLS");

			//Lastname
			std::cout << "Type in a '-' if you dont wanna change the user data!" << std::endl;
			std::cout << "Lastname: " << std::endl;
			std::cout << "Old lastname: " << user.getLastName() << std::endl;
			std::cout << "New lastname: ";

			std::string newLastName;
			std::cin >> newLastName;

			if (newLastName != "-") {
				user.setLastname(newLastName);
			}
			system("CLS");


			//Citizenship
			std::cout << "Type in a '-' if you dont wanna change the user data!" << std::endl;
			std::cout << "Citizenship: " << std::endl;
			std::cout << "Old citizenship: " << user.getCitizenship() << std::endl;
			std::cout << "New citizenship: ";

			std::string newCitizenship;
			std::cin >> newCitizenship;

			if (newCitizenship != "-") {
				user.setCitizenship(newCitizenship);
			}
			system("CLS");


			//Phone number
			std::cout << "Type in a '0' if you dont wanna change the user data!" << std::endl;
			std::cout << "Phone Number: " << std::endl;
			std::cout << "Old phone Number: " << user.getPhoneNumber() << std::endl;
			std::cout << "New phone Number: ";

			int NewPhoneNumber;
			std::cin >> NewPhoneNumber;

			if (NewPhoneNumber != 0) {
				user.setPhoneNumber(NewPhoneNumber);
			}
			system("CLS");
		}
	}
	if (wasFound == false)
		std::cout << "No account with the firstname: " << firstname << " and the lastname: " << lastname << " was found!" << std::endl;

	std::cout << "The information you just changed was succesfully apllied!" << std::endl;

	continueScreen();
}


void Banking::transact() {

	system("CLS");

	std::cout << "Type in the account you wanna send money from!" << std::endl;

	
	std::cout << "Type in the first and secound name you want to send money from!" << std::endl;

	std::cout << "firstname: ";
	std::string firstname;
	std::cin >> firstname;

	std::cout << "lastname: ";
	std::string lastname;
	std::cin >> lastname;

	system("CLS");

	bool wasFound = false;
	for (auto &o : accountVec) {
		if (o.getFirstName() == firstname && o.getLastName() == lastname && o.getTradeStatus() == true) {
			wasFound = true;
			if (o.getTradeStatus() == true) {

				std::cout << "Type in the account you wanna send money to!" << std::endl;
				std::cout << "Type in the first and secound name you want to send money to!" << std::endl;

				std::cout << "firstname: ";
				std::string firstname2;
				std::cin >> firstname2;

				std::cout << "lastname: ";
				std::string lastname2;
				std::cin >> lastname2;

				system("CLS");

				bool wasFound2 = false;
				for (auto& o2 : accountVec) {
					if (o2.getFirstName() == firstname2 && o2.getLastName() == lastname2) {
						wasFound2 = true;
						if (o2.getTradeStatus() == true) {

							std::cout << "Enter the amount of money you want to send: ";
							int money;
							std::cin >> money;

							system("CLS");

							if (o.getBalance() >= money && money > 0) {
								o.setBalance(o.getBalance() - money);
								o2.setBalance(o2.getBalance() + money);

								std::cout << "You succesfully sent " << money << " to " << o2.getFirstName() << " " << o2.getLastName() << std::endl;
							}
							else
								std::cout << "You dont have enough money on your account " << o.getFirstName() << std::endl;
						}
						else
							std::cout << "You are not allowed to trade money! Your account is blocked!" << std::endl;
					}
				}
				if (wasFound2 != true)
					std::cout << "No account with the firstname: " << firstname2 << " and the lastname: " << lastname2 << " was found!" << std::endl;
			}
			else
				std::cout << "You are not allowed to trade money! Your account is blocked!" << std::endl;
		}

		if (wasFound != true)
			std::cout << "No account with the firstname: " << firstname << " and the lastname: " << lastname << " was found!" << std::endl;
	}

	continueScreen();
}


void Banking::see() {
	system("CLS");

	std::cout << "Type in 1 to filter for ID or Type in 2 to filter for firstname and lastname" << std::endl;

	int temp;
	std::cin >> temp;

	system("CLS");

	if (temp == 1) {

		std::cout << "Type in the id you want to get more information about: ";

		int id;
		std::cin >> id;

		system("CLS");

		bool wasFound = false;
		for (auto o : accountVec) {
			if (o.getId() == id) {
				getInfoForAccount(o);
				wasFound = true;
			}
		}
		if (wasFound != true)
			std::cout << "No account with the id: " << id << " was found!" << std::endl;

	}
	else if (temp == 2) {
		std::cout << "Type in the first and secound name of the account you want to get information about!" << std::endl;

		std::cout << "firstname: ";
		std::string firstname;
		std::cin >> firstname;

		std::cout << "lastname: ";
		std::string lastname;
		std::cin >> lastname;

		system("CLS");

		bool wasFound = false;
		for (auto o : accountVec) {
			if (o.getFirstName() == firstname && o.getLastName() == lastname) {
				getInfoForAccount(o);
				wasFound = true;
			}
		}
		if (wasFound != true)
			std::cout << "No account with the firstname: " << firstname << " and the lastname: "<< lastname << " was found!" << std::endl;
	}
	else {
		see();
	}

	continueScreen();
}


void Banking::showAll() {

	system("CLS");

	if (accountVec.size() >= 1) {
		for (auto o : accountVec) {

			getInfoForAccount(o);

			std::cout << std::endl << std::endl;
		}

	}
	else
		std::cout << "No Accounts registered!" << std::endl;

	continueScreen();
}


void Banking::erase() {
	system("CLS");

	std::cout << "Type in 1 to remove by ID or Type in 2 to remove by firstname and lastname" << std::endl;

	int temp;
	std::cin >> temp;

	system("CLS");

	if (temp == 1) {

		std::cout << "Type in the id you want to remove: ";

		int id;
		std::cin >> id;

		system("CLS");

		bool wasFound = false;
			if (id <= accountVec.size() && id >= 1) {
				removeAccountByID(id);
				std::cout << "The given account was succesfully deleted!" << std::endl;
				wasFound = true;
			}
		if (wasFound != true)
			std::cout << "No account with the id: " << id << " was found!" << std::endl;
	}
	else if (temp == 2) {
		std::cout << "Type in the first and secound name of the account you want to remove!" << std::endl;

		std::cout << "firstname: ";
		std::string firstname;
		std::cin >> firstname;

		std::cout << "lastname: ";
		std::string lastname;
		std::cin >> lastname;

		system("CLS");

		bool wasFound = false;
		for (auto o : accountVec) {
			if (o.getFirstName() == firstname && o.getLastName() == lastname) {

				removeAccountByID(o.getId());
				wasFound = true;
				std::cout << "The given account was succesfully deleted!" << std::endl;
			}
		}

		if (wasFound != true)
			std::cout << "No account with the firstname: " << firstname << " and the lastname: " << lastname << " was found!" << std::endl;
	}
	else {
		erase();
	}

	continueScreen();
}




void Banking::getInfoForAccount(Account o) {

	std::cout << "ID: " << o.getId() << std::endl;
	std::cout << "Firstname: " << o.getFirstName() << std::endl;
	std::cout << "Lastname: " << o.getLastName() << std::endl;
	std::cout << "Citizenship: " << o.getCitizenship() << std::endl;
	std::cout << "Phone Number: " << o.getPhoneNumber() << std::endl;
	std::cout << "Trade Status: " << o.getTradeStatus() << std::endl;
	std::cout << "Balance: " << o.getBalance() << std::endl;
	
}

void Banking::removeAccountByID(int id) {
	accountVec.erase(accountVec.begin() + id - 1);
}