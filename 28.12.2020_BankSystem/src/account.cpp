#include <string>

#include "account.hpp"


Account::Account(const int id, const std::string firstname, const std::string lastname, const std::string citizenship , const int phoneNumber) 
	: id(id), firstname(firstname), lastname(lastname), citizenship(citizenship), phoneNumber(phoneNumber) {}


//Getters
int Account::getId() {
	return id;
}

std::string Account::getFirstName() {
	return firstname;
}

std::string Account::getLastName() {
	return lastname;
}

std::string Account::getCitizenship() {
	return citizenship;
}

int Account::getPhoneNumber() {
	return phoneNumber;
}

bool Account::getTradeStatus() {
	return tradeStatus;
}

double Account::getBalance() {
	return balance;
}



//Setters
void Account::setBalance(double amount) {
	balance = amount;
}

void Account::setFirstname(std::string NewFirstname){
	firstname = NewFirstname;
}

void Account::setLastname(std::string NewLastname) {
	lastname = NewLastname;
}

void Account::setCitizenship(std::string NewCitizenship) {
	citizenship = NewCitizenship;
}

void Account::setPhoneNumber(int NewPhoneNumber) {
	phoneNumber = NewPhoneNumber;
}