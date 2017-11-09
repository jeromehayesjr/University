#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

bool binarySearch(const vector<int> & v, int k)
{
   int s = 0;
   int e = v.size() -1;
   while (s <= e)
   {
      int m = (s + e) / 2;
      if (v[m] == k) return true;
      else if (v[m] < k) s = m + 1;
      else
      {
         assert(v[m] > k);
         e = m - 1;
      }
   }
   return false;
}

int main(int argc, char * args[])
{
   vector<int> v5;
   v5.push_back(1);
   v5.push_back(3);
   v5.push_back(5);
   v5.push_back(7);
   v5.push_back(9);
   assert(binarySearch(v5, 3) == true);

  cout << "All tests passed .\n";
}
