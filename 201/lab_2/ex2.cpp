#include <iostream>
#include <cmath>

using namespace std;

int main( int argc, char * args[])
{
	double meters;
	cout << "meters = ";
	cin >> meters;

	int feet = meters / .3048;
	int inches = (meters/ .3048) * 12 - feet *12;

	cout << feet << " ft ";
	cout << inches << "in";

	cout << endl;
}
