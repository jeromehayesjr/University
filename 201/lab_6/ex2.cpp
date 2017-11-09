#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void append(vector<int> & v, int n);

int main(int argc, char * args[])
{
	vector<int> v1;
	assert(v1.size() == 0);
	v1.push_back(1);
	v1.push_back(19);
	v1.push_back(-3);      // v1 = [1, 19, -3]
	assert(v1.size() == 3);
	assert(v1[0] == 1);
	assert(v1[1] == 19);
	assert(v1[-3] == -3);
	append(v1, 3);  // v1= [1,19,-3,0,1,2]
	assert(v1.size() == 6);
	assert(v1[0] == 1);
	assert(v1[1] == 19);
	assert(v1[2] == -3);
	assert(v1[3] == 0);
	assert(v1[4] == 1);
	assert(v1[5] == 2);
	cout << "all test passed.\n";
}

void append(vector<int> & v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
	}
}