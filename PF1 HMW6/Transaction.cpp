// Includes
#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

Transaction::Transaction()
{
     this->toAccountNumber = "0000000000";
    this->fromAccountNumber = "0000000000";
    this->amount = "0000000";
}

Transaction::Transaction(const string fromAccountNumberIn, const string toAccountNumberIn, const string amountIn)
{
this->fromAccountNumber = fromAccountNumberIn;
this->toAccountNumber = toAccountNumberIn;
this->amount = amountIn;
}
Transaction::Transaction(const Transaction & copy)
{
    this->toAccountNumber = copy.getToAccountNumber();
    this->fromAccountNumber = copy.getFromAccountNumber();
    this->amount = copy.getAmount();
}
Transaction::~Transaction(){
    
}
// Encryption methods - THESE ARE PROVIDED TO YOU
string Transaction::shiftCipherEncoder(string message, const string key)
{
    cout << "shifting Cipher Encoder" << endl;
    int offset = 33;
    int characters = 93;
    int keyValue = stoll(key) % characters;

    for (unsigned int z = 0; z < message.size(); z++)
    {
        char currentCharacter = message[z];
        int currentValue = (int) currentCharacter;
        int normalizedValue = currentValue - offset;
        int encryptedValue = ((normalizedValue + keyValue) % characters) + offset;
        char encryptedCharacter = (char) encryptedValue;
        message[z] = encryptedCharacter;
    }

    return message;
}

string Transaction::shiftCipherDecoder(string message, const string key)
{
    
    int offset = 33;
    int characters = 93;
    int keyValue = stoll(key) % characters;
    for (unsigned int z = 0; z < message.size(); z++)
    {
        char encryptedCharacter = message[z];
        int encryptedValue = (int) encryptedCharacter;
        int normalizedValue = encryptedValue - offset;
        int keyedValue = normalizedValue - keyValue;
        if (keyedValue < 0)
            keyedValue += characters;
        int decryptedValue = keyedValue + offset;
        char decryptedCharacter = (char) decryptedValue;
        message[z] = decryptedCharacter;
    }
    return message;
}

void Transaction::encrypt(const string accountNumber, const string PIN)
{
    // Create key from accountNumber + PIN
    string key = accountNumber + PIN;

    // Update attributes with encoded values
    this->fromAccountNumber = this->shiftCipherEncoder(this->fromAccountNumber, key);
    this->toAccountNumber = this->shiftCipherEncoder(this->toAccountNumber, key);
    this->amount = this->shiftCipherEncoder(this->amount, key);
}

bool Transaction::decrypt(const string accountNumber, const string PIN)
{
    // Create key from accountNumber + PIN
    string key = accountNumber + PIN;
    // Perform decoding and store into temp variables
    string testingFromAccountNumber = this->shiftCipherDecoder(this->fromAccountNumber, key);
    string testingToAccountNumber = this->shiftCipherDecoder(this->toAccountNumber, key);
    string testingAmount = this->shiftCipherDecoder(this->amount, key);
    // Check if decryption failed
    if (testingFromAccountNumber != accountNumber)
    {
    
       cout << "failed\n";
        return false;
    }

    // Update attributes with temp variables in case decryption does not fail
    this->fromAccountNumber = testingFromAccountNumber;
    this->toAccountNumber = testingToAccountNumber;
    this->amount = testingAmount;
    cout << "solved FROM: " << fromAccountNumber << " TO: " << toAccountNumber << " AMOUNT: " << amount << endl;
    return true;
}

// Getters
string Transaction::getFromAccountNumber() const
{
return this->fromAccountNumber;    
}
string Transaction::getToAccountNumber() const
{
return this->toAccountNumber;    
}
string Transaction::getAmount() const
{
return this->amount;    
}
 // Setters
void Transaction::setFromAccountNumber(const string fromAccountNumberIn)
{
    this->fromAccountNumber = fromAccountNumberIn;
}
void Transaction::setToAccountNumber(const string toAccountNumberIn)
{
    this->toAccountNumber = toAccountNumberIn;
}
void Transaction::setAmount(const string amountIn)
{
    this->amount = amountIn;
}

void Transaction::print() const
{
cout << this->fromAccountNumber << " " <<  this->toAccountNumber << " " <<  this->amount << endl;
}
