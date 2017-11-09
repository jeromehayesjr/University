// Jerome Hayes Jr
// file name: Merge.cpp
// 4-14-14
// Merge two vectors, alternating their elements into a thrid vector.

#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> c;
    int i;
    for (i = 0; i < a.size() and i < b.size(); ++i)
    {
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    while (i < b.size())
    {
        c.push_back(b[i]);
        ++i;
    }
    while (i < a.size())
    {
        c.push_back(a[i]);
        ++i;
    }

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
    c = merge( a, b); // calls the merge function
    for (int i = 0; i < c.size(); ++i) // displays content of c.vector
    {
        cout << c[i] << endl;
    }
}
//100%
