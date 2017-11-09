#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   srand(time(0));
   for (int i = 0; i < 100; ++i)  {
      for (int j = 0; j < 6; ++j)  {
          int n = rand() % 16;
          if (n < 10)  {
             cout << n;
          } else if (n == 10)  {
               cout << "A";
          } else if (n == 11)  {
               cout << "B";
          } else if (n == 12)  {
               cout << "C";
          } else if (n == 13)  {
               cout << "D";
          } else if (n == 14)  {
               cout << "E";
          } else if (n == 15)  {
               cout << "F";
          } else {
               cout << "somnething's wrong.";
          }
      }
      cout << "\n";
     }
}

