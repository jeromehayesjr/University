#include <iostream>

using namespace std;

int main ()
{
	int num1, num2, answer;

	num1 = 0;

	cout<< " Please enter a number: " << endl;
	cin>> num2;
 
	answer = 0; 

	for(double y=num1; y<= num2; y++)
	{
		answer += y; 
	}

    cout<< " The sum through the two numbers is  "<< answer;
}