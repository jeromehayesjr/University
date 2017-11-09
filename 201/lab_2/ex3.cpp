#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
     srand(time(0));
     int i = 0;
     for (i = 0; i < 100; i++)
     {
          cout << rand() << endl;
     }

}
