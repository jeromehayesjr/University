/*
 Test Cases
 n = 2   prime
 n = 67  prime
 n = 4   is not prime
 n = 6   is not prime
 n = 10  is not prime
 n = 9   is not prime
 n = 5   prime
*/


#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char * args[])
{
   int n;
   cout << "Please enter a integer greater than one\n";
   cin >> n;

   bool nIsPrime = true;

   for (int i = 2; i < n; ++i)
   {
      if( n % i == 0 )
      {
          nIsPrime = false;
          break;
      }
   }

   if ( nIsPrime )
   {
      cout << n << " is prime.\n";
   }
   else
   {
      cout << n << " is not prime.\n";
   }   


}

