#ifndef ACCOUNT_H
#define ACCOUNT_H

// Jerome Hayes Jr
// file name: Account.h
// 4-3-14
// Headerfile

class Account
{
private:
    double balance;
    double interest_rate; // for example, interest_rate = 6 means 6%
public:
    Account();
    Account(double amount, double rate);
    void deposit(double);
    bool withdraw(double);  // returns true if there was enough money, otherwise fase
    double query();
    void set_interest_rate(double rate);
    double get_interest_rate();
    void add_interest();
};

#endif
