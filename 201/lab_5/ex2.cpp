#include <iostream>
#include <cassert>
#include "Number.h"

using namespace std;

int main (int argc, char * args[])
{
   cout << "Enter an interger greater than 1: ";
   int k;
   cin >> k;

   for (int n = 2; n <=k; ++n)
   {
      Number num(n);
      if (num.isPrime())
      {
         cout << n << " ";
      }
   }
   cout << " \n";

}

