#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

string getrandomcolor()
{
   stringstream ss;
   for (int j = 0; j < 6; ++j)
   {
      int n = rand() % 16;
      if (n < 10){
         ss << n;
      } else if (n == 10) {
         ss << 'A';
      } else if (n == 11) {
         ss << 'B';
      } else if (n == 12) {
         ss << 'C';
      } else if (n == 13) {
         ss << 'D';
      } else if (n == 14) {
         ss << 'E';
      } else if (n == 15) {
         ss << 'F';
      } else {
         cout << "something's wrong.";
      }      
   }
   return ss.str();
}
int main (int argc, char * args[])
{
   srand(time(0));
   for (int i =0; i < 100; ++i)
   {
      cout << getrandomcolor() << "\n";
   }
   cout << "\n";
}   
