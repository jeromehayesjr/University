#include <iostream>
#include <cassert>

/*
 413 is not a prime number.
 47 is a prime number.
 2 is a prime number.
 167 is a prime number.
 213 is not a prime number.
 57 is not a prime number.
 1427 is a prime number.
 367893 is not a prime number.
*/

using namespace std;

bool isPrime(int n)
{
   assert (n > 1);
   bool foundDivisorForN = false;
      for (int i = 2; i < n; ++i)
      {
         if(n % i == 0) foundDivisorForN = true;
      }
      return foundDivisorForN == false;
}

int main (int argc, char * args[])
{
   assert (!isPrime(413));
   assert (isPrime(47));
   assert (isPrime(2));
   assert (isPrime(167));
   assert (!isPrime(213));
   assert (!isPrime(57));
   assert (isPrime(1427));
   assert (!isPrime(367893));
   cout << "All tests passed. \n";
}
