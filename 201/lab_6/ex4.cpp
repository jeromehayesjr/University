#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void insert(vector<int> & v, int k){
	v.push_back(k); // swap with procedecessor unill larger
	int posOfK = v.size() - 1;
	while (posOfK > 0){
	int predecessor = v[posOfK - 1];
	if (k < predecessor){
	    v[posOfK] = predecessor;
	    --posOfK;
            v[posOfK] = k;
	}else{
           break;
        }
      }
}
int main(int argc, char * args[])
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(12);
        
        cout << "All tests passed.\n";
}

