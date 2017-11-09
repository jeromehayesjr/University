// Jerome Hayes Jr
// file name: Append.cpp
// 4-14-14
// Program asks user to input intergers into two different vectors. Then displays them in one new vector.

#include <iostream>
#include <vector>

using namespace std;

vector<int> append(vector<int> a, vector<int>b)
{
    vector<int> c;
    int i;
    for (i = 0; i < a.size(); i++)
        c.push_back(a[i]);
    for (i = 0; i < b.size(); i++)
        c.push_back(b[i]);
    
    return c;
}

main()
{
    vector<int> a, b, c;
    int entry;

    cout << " What is the intergers of group A? " <<  endl;
    cin >> entry;
    while(entry > -1)
    {
        a.push_back(entry);
        cout << " What is the intergers of group A? (enter -1 to end entry) " << endl;
        cin >> entry;
    }

    cout << " What is the intergers of group B? (ctrl-d ends group B) " << endl;
    cin >> entry;
    while(!cin.eof()) // means cin not equal to ctrl-d
    {
        b.push_back(entry);
        cout << "What is the intergers of group B? (ctrl-d ends group B) " << endl;
        cin >> entry;
    }
    
    c = append (a,b); // calls the append function
    int i;
    for (i = 0; i < c.size(); ++i)
    {
        cout << c[i] << endl;
    }
}
// 100%
