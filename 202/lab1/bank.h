#ifndef BANK_H
#define BANK_H

// Jerome Hayes Jr
// file name: Account.h
// 4-3-14
// Headerfile

#include <string>
#include "Account.h"

using namespace std;

class Bank
{
private:
    Account savings;
    Account checking;
public:
    Bank();
    Bank(double savings_amount, double checking_amount);
    void deposit(double amount, string account);
    void withdraw(double amount, string account);
    void transfer(double amount, string account);
    void print_balances();
};

#endif
