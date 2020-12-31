#pragma once


class Account
{
public:
	Account(const int id, const std::string firstname, const std::string lastname, const std::string citizenship, const int phoneNumber);
	
	//Getters
	int getId();
	std::string getFirstName();
	std::string getLastName();
	std::string getCitizenship();
	int getPhoneNumber();
	
	bool getTradeStatus();
	double getBalance();


	//Setters
	void setBalance(double);
	void setFirstname(std::string);
	void setLastname(std::string);
	void setCitizenship(std::string);
	void setPhoneNumber(int);


private:
	//Personal Information
	int id;
	std::string firstname;
	std::string lastname;
	std::string citizenship;
	int phoneNumber;

	//Money
	bool tradeStatus = true;
	double balance = 100;
};