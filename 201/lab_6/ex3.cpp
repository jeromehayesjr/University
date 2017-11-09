#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void append(vector<int> & v, const vector<int> & w)
{
	for (int i = 0; i < w.size(); ++i)
	{
		v.push_back (w[i]);
	}

}
int main(int argc, char * args[])
{
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(5);      // v1 = [4, 2, 5]
	vector<int> w1;
	w1.push_back(11);
	w1.push_back(3);  // w1 = [11,3]
	append(v1, w1);  // v1 = [4,2,5,11,3]
	assert(v1[0] == 4);
	assert(v1[1] == 2);
	assert(v1[2] == 5);
	assert(v1[3] == 11);
	assert(v1[4] == 3);
	cout << "all test passed.\n";
}

