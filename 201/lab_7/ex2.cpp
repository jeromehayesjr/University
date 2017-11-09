#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

bool binarySearch(const vector<int> & v, int k)
{
   int s = 0;
   int e = v.size() -1;
   int counter = 0;
   while (s <= e)
   {
      int m = (s + e) / 2;
      if (v[m] == k)
      {
         assert(counter <= log2(v.size() +1)); 
         return true;
      }
      else if (v[m] < k) s = m + 1;
      else  e = m - 1;
   }
   assert(counter <= log2(v.size() +1));
   return false;
}

int main(int argc, char * args[])
{
   vector<int> v;
   for (int i = 0; i < 1024; ++i)
   {
      v.push_back(2 * i);
   }
   assert(binarySearch(v, 0) == true);
  cout << "All tests passed .\n";
}
