// Jerome Hayes Jr
// file name: Account_main.cpp
// 4-3-14
// (description)

#include <iostream>
#include "Account.h"

using namespace std;

main()
{
    Account savings(100);

    savings.deposit(20);
    cout << savings.query() << endl;

    if (savings.withdraw(50))
        cout << "Successful withdraw.\n";
    else cout << "Not enough in the account, $5 penalty charged. \n";
    cout << savings.query() << endl;

    if (savings.withdraw(100))
        cout << "Successful withdraw. \n";
    else cout << "Not enough in the account, $5 penalty charged. \n";
    cout <<  savings.query() << endl;
}
