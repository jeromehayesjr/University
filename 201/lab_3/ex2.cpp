#include <iostream>
#include <cmath>

using namespace std;

/*
Test Cases:
   input   output
   2       2
   3       2 3 
   4       2 3
   8       2 3 5 7
   27      2 3 5 7 11 13 17 19 23

*/


int main(int argc, char * args[])
{
   int k;
   cout << "Please enter a integer greater than one\n";
   cin >> k;

   for (int n = 2; n <= k; ++n)
     {
       bool foundDivisonForN = false;

      for (int i = 2; i < n; ++i) 
      {
         if ( n % i == 0 ) foundDivisonForN = true;
      }
         {
            if (!foundDivisonForN)
            {
               cout << n << " \n";
            }
 
         }
      }  
 }


