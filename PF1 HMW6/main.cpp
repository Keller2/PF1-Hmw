#include<iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "Account.h"
#include "Transaction.h"
using namespace std;
string donnaAccountNumber;

void accountRead (const string filename, vector <Account> & accounts) 
{
  
ifstream actFile;
actFile.open (filename);
string firstName, lastName, PIN, accountNumber;

while (!actFile.eof ())
{
actFile >> firstName; 
//cout << firstName << " ";
actFile >> lastName;
actFile >> PIN;
actFile >> accountNumber;
Account account (firstName, lastName, PIN, accountNumber);
if (!actFile.eof())
{
accounts.push_back(account);
}
}
}


 
void accountWrite (string filename, vector <Account> accounts)
{
  
ofstream outfile;
  
outfile.open (filename);
  
for (int i = 0; i < accounts.size(); i++)
    {
      
outfile << accounts[i].getFirstName() << " " << accounts[i].getLastName() << " " << accounts[i].getPIN() << " " << accounts[i].getAccountNumber() << endl;
    
} 
outfile.close();

} 
void transactionRead(const string filename, vector<Transaction> & transactions)
{
    ifstream trctFile;
    trctFile.open(filename);
    string fromAccountNumber, toAccountNumber, amount;
    while (!trctFile.eof ())
{
trctFile >> fromAccountNumber; 
trctFile >> toAccountNumber;
trctFile >> amount;
Transaction actions (fromAccountNumber, toAccountNumber, amount);
if (!trctFile.eof())
{
transactions.push_back(actions);
}
}
trctFile.close();
}

void transactionWrite(const string filename, vector<Transaction> & transactions)
{
ofstream transactionsOut;
 cout <<  "opened" << endl; 
transactionsOut.open (filename);
  
for (int i2 = 0; i2 < transactions.size(); i2++)
    {
transactionsOut << transactions[i2].getFromAccountNumber() << " " << transactions[i2].getToAccountNumber() << " " << transactions[i2].getAmount() << endl;
} 
transactionsOut.close();    
}
void iterateAccounts(vector<Account> accounts){
    for(int i = 0; i < accounts.size(); i++)
    if(accounts[i].getFirstName() == "Donna")
    {
        //cout <<  i << endl;
        donnaAccountNumber = accounts[i].getAccountNumber();
        cout << accounts[i].getFirstName() << " " << accounts[i].getLastName() << "'s" << endl;
        cout << "account number is " << donnaAccountNumber << endl;
    }
}
int main() 
{
Account DonnasTransactionsandAccount(string donnaAccountNumber);
vector <Account> accounts;
vector <Transaction>  transactions; 
accountRead("accounts.txt", accounts);
for (int e = 0; e < accounts.size(); e++){
accounts[e].print();
} 
accountWrite("accountsCheck.txt", accounts);
iterateAccounts(accounts);
transactionRead("encryptedTransactions.txt", transactions);
cout << "-- Transactions before decryption --" << endl;
for (int f = 0; f < transactions.size(); f++){
transactions[f].print();
} 
cout << "read transactions" << endl;
for(int i = 0; i < transactions.size(); i++)
{
    int test = 0;
    double size;
    size = transactions.size();
    double percentage;
    percentage = (i / size);
    percentage = percentage * 100;  
    cout << fixed << setprecision(0) << percentage << " % of the way done. " <<  i << " " << size << endl;
  while(transactions[i].decrypt(accounts[test].getAccountNumber(), accounts[test].getPIN()) == false){
      test++;    
  }
  
}
cout << "-- decrypting --" << endl;
for (int f = 0; f < transactions.size(); f++){
transactions[f].print();
}
transactionWrite ("decryptedTransactions.txt", transactions);
cout << "done writing" << endl;
for(int i = 0; i < transactions.size(); i++)
    {
        
        if(transactions[i].getFromAccountNumber() == donnaAccountNumber || transactions[i].getToAccountNumber() == donnaAccountNumber)
        {
            if(transactions[i].getFromAccountNumber() == donnaAccountNumber){
            cout << "donna made an outgoing transaction ";
            }
            if(transactions[i].getToAccountNumber() == donnaAccountNumber){
            cout << "donna recieved an transaction ";
            }
            cout << transactions[i].getFromAccountNumber() << " " << transactions[i].getToAccountNumber() << " " << transactions[i].getAmount() << endl;
        }
    }
 
 
 

 
return 0;

}
