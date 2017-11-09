#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[])
{
   srand(0);
   vector<int> v;
   for (int i = 0; i < 100000; ++i)
   {
     v.push_back(rand());
   }
   sort(v.begin(), v.end());
   cout << "done." << endl;
}
