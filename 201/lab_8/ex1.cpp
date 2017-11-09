#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void mysort(vector<int> & v)
{
   for (int i = 0; i < v.size() - 1; ++i)
   {
      int k = i;
      for (int j = i + 1; j < v.size(); ++j)
      {
         if (v[j] < v[k]) k = j;
      }
   
   int temp = v[i];
   v[i] = v[k];
   v[k] = temp;
   }
}

int main(int argc, char * argv[])
{
   vector<int> v;
   v.push_back(8);
   v.push_back(2);
   v.push_back(6);
   v.push_back(1);
   v.push_back(5);

   mysort(v);

   assert(v[0] == 1);
   assert(v[1] == 2);
   assert(v[2] == 5);
   assert(v[3] == 6);
   assert(v[4] == 8);
  
   cout << "All tests passed .\n";
}
