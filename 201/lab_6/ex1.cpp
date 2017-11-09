#include <iostream>
#include <cassert>

using namespace std;

int mymaximum(int a[], int numberOfElements)
{
	int m = a[0];
	for (int i = 1; i < numberOfElements; ++i)
	{
		if (a[i] > m) m = a[i];
	}
	return m;
}

int main(int argc, char * args[])
{
	// test 1
	int a1[3];
	a1[0] = 1;
	a1[1] = 19;
	a1[2] = -3;
	int max = mymaximum(a1, 3);
	assert(max == 19);

	//test 2
	int a2[] = { -45, -12, -3, -101 };
	assert(mymaximum(a2, 4) == -3;

	cout << "all tests passsed.\n";
}