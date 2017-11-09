// Jerome Hayes Jr
// file name: Bank.cpp
// 4-10-14
// Implementation of the functions I defind in the header file.

#include <iostream>
#include <string>
#include "Bank.h"

using namespace std;

Bank::Bank()
{
}

Bank::Bank(double savings_amount, double checking_amount)
{
}
void Bank::deposit(double amount, string account) // deposit money into accounts.
{
	if (account == "S")
	{
		savings.deposit(amount);
		cout << "Depost was Successful" << endl;
	}
	else if (account == "C")
	{
		checking.deposit(amount);
		cout << "Depost was Successful" << endl;
	}
	else
	{
		cout << "Not A Valid Account" << endl;
	}
}
void Bank::withdraw(double amount, string account) // Remove money from accounts.
{
		if (account == "S") // withdraws money from savings account
		{
			bool state = savings.withdraw(amount);
			if (bool state = true)
			{
				cout << "Insignificant funs, $5 penalty" << endl;
			}
			else
				cout << "Deposit Successful" << endl;
		}
		else if (account == "C") // withdraws money from checking account
		{
			bool state = checking.withdraw(amount);
			if (bool state = false)
			{
				cout << "Insignificant funs, $5 penalty" << endl;
			}
			else
				cout << "Deposit Successful" << endl;
		}
		else
		{
			cout << "Not A Valid Account" << endl;
		}
}
void Bank::transfer(double amount, string account) // transfer money between accounts.
{
	if (account == "S") // transfer money from savings account into checking account.
	{
		if (savings.withdraw(amount) == true)
		{
			checking.deposit(amount);
			cout << "transfer successful" << endl;
		}
		else
		{
			cout << "Insignificant funs, $5 penalty" << endl;
		}
	}
	else if (account == "C") // transfer money from checking account into saving account.
	{
		if (checking.withdraw(amount) == true)
		{
			savings.deposit(amount);
			cout << "transfer successful" << endl;
		}
		else
		{
			cout << "INsignificant funs, $ penalty" << endl;
		}
	}
	else
	{
		cout << " Not a valid account" << endl;
	}
}
void Bank::print_balances()
{
	cout << "Savings balance is " << savings.query() << endl;
	cout << "Checking balance is" << checking.query() << endl;
}