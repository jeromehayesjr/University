#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char * args[])

{
        double x;
        double y;
        double z;
       
	cout << "insert x value =";
        cin >> x;
       
	cout << "insert y value =";
        cin >> y;
        
	cout << "insert z value =";
        cin >> z;
		cin.get();
	double sumXYZ = x + y + z;
    cout<< "The sum of x, y and z is " << sumXYZ << ".\n";
	cout<< "The sine of x is " << sin(x) << ".\n";
	cout<< "The cosine of x plus y divided by z" << cos(x) + y/z << ".\n";
	cout<< "The average of x,y and z " << (x + y + z) / 3 << ".\n";
	//cout<< "The log2 of x " << log2 << ".\n";
}	