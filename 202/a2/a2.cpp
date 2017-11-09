#include <iostream>
using namespace std;

double average(double * a, int a_size)
{
    double total = 0.0;
    for (int i; i < a_size; i++, a++)
    {
        total += *a;
    }
    return total / a_size;
}

double * maximum(double * a, int a_size)
{
    if (a_size == 0)
    {
        return NULL;
    }
    double *highest = a;
    double *p = a + 1;
    int count = a_size - 1;
    
    while (count > 0)
   {
       if (*p > *highest)
       {
           highest = p;
       }
       p++;
       count--;
   }
   return highest;
}
int main()
{
    double a[10];
    double * a_pointer = a;
    double input;
    int counter = 0;
    cout << " Enter a numbers (ctrl-d to end entry)" << endl;
    cin >> input;

    while (!cin.eof())
    {
        a[counter] = input; 
        cin >> input;
        counter++;
    }
    cout << "average: " << average(a_pointer, counter) << endl;
    cout << "maximum: " << *maximum(a_pointer, counter) << endl;
}
