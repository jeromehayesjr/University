#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using namespace std;

long  mysort(vector<int> & v)
{
   long innerLoopCOunt = 0;  
   for (int i = 0; i < v.size() - 1; ++i)
   {
      int k = i;
      for (int j = i + 1; j < v.size(); ++j)
      {
         if (v[j] < v[k]) k = j;
         ++innerLoopCOunt;
      }
   int temp = v[i];
   v[i] = v[k];
   v[k] = temp;
   }
   return innerLoopCOunt;
}

int main(int argc, char * argv[])
{
   srand(1);
   vector<int> v;
   for (int i = 0; i < 100000; ++i)
   {
     v.push_back(rand());
   }
   cout <<  mysort(v) << endl;
}
