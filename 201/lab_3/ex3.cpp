#include <iostream>
/*
Test Cases
   n = 6   ->2,3
   n = 12  ->2,2,3
   n = 15  ->3,5
   n = 100 ->2,2,5,5
   n = 3   ->3 
   n = 67  ->67
   n = 8   ->2,2,2
   n = 10  ->2,5
*/

using namespace std;

int main()
{
   cout << "Enter an integer greater than 1: ";
   int n;
   cin >> n;

   int k = 2;
   while (n > 1)
   {
      if (n % k == 0)
      {
         cout << k << " \n";
         n = n / k;
      }
         else
         {
            ++k;
         }
   }   

}
