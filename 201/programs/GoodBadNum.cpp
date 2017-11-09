#include <iostream>

using namespace std;

int main ()
{

    int num1;
    
    cout<<"Please enter a number that is between 3 and 12:"<<endl;
    cin>>num1;

    if((num1>3)&&(num1<12))
    {
        cout<< "Good number";
    }
    else
    {
        cout<< "bad number";
    }

}