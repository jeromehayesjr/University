#include <iostream>
#include <cassert>

using namespace std;

bool isPrime(int n)
{
   assert (n > 1);
   bool foundDivisorForN = false;
      for (int i = 2; i < n; ++i)
      {
         if (n % i == 0) foundDivisorForN = true;
      }
      return foundDivisorForN == false;
}
 int main (int argc, char * args[])
{
   cout << "Enter an interger greater than 1: ";
   int k;
   cin >> k;

   for (int n = 2; n <=k; ++n)
   {
      if (isPrime(n))
      {
         cout << n << " ";
      }
   }
   cout << "\n";
}
