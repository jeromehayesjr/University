#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int countOccurrences(const vector<int> & v, int k){
  int n = 0;  
  for(int i = 0; i < v.size(); ++i){
     if(k == v[i]){
        n += 1;
     }
  }  
 return n;
}
                    
int main(int argc, char * args[]){
   vector<int> v;
   assert(v.size() == 0);
   v.push_back(1);
   v.push_back(4);
   v.push_back(5);
   v.push_back(7);
   assert(v.size() == 4);
   assert(countOccurrences(v,4) == 1);
   v.push_back(7);
   v.push_back(7);
   assert(countOccurrences(v,7) == 3);
   cout << "All test passed.\n";
}


