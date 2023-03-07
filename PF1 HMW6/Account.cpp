#include "Account.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
Account::Account()
{
this->firstName = "None";
this->lastName = "None";
this->PIN = "0000";
this->accountNumber = "0000000000";
}
Account::Account(const string firstName, const string lastName, const string PIN, const string accountNumber)
{
this->firstName = firstName;
this->lastName = lastName;
this->PIN = PIN;
this->accountNumber = accountNumber;
}
Account::Account(const Account & copy)
{
this->firstName = copy.getFirstName();
this->lastName = copy.getLastName();
this->PIN = copy.getPIN();
this->accountNumber = copy.getAccountNumber();
}
Account::~Account()
{
//cout << "destroyed" << endl;
}

string Account::getFirstName() const
{
return this->firstName;
}

string Account::getLastName() const
{
return this->lastName;
}

string Account::getPIN() const
{
return this->PIN;
}
      
string Account::getAccountNumber() const
{
return this->accountNumber;
}

void Account::setFirstName(const string firstNameIn)
{
    cout << "setting" << endl;
firstName = firstNameIn;
    cout << "finished setting" << endl;
}

void Account::setLastName(const string lastNameIn)
{
lastName = lastNameIn;
}

void Account::setPIN(const string PINIn)
{
PIN = PINIn;
}

void Account::setAccountNumber(const string accountNumberIn)
{
accountNumber = accountNumberIn;
}

void Account::print() const
{
cout << this->firstName << " " <<  this->lastName << " " <<  this->PIN << " " <<  this->accountNumber << endl;
}