// Jerome Hayes Jr
// file name: Account_main2.cpp
// 4-7-14
// This program displays the amount of years it takes to double $10,000.00 with an annual interest rate of 6%.


#include <iostream>
#include "Account.h"
#include <cmath>

using namespace std;

main()
{
Account savings(10000, 6);

int i = 0;

while(savings.query() < 20000)
    {
        savings.add_interest();
         ++i;
    }
cout << i <<  endl;
}
