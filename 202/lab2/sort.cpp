// Jerome Hayes Jr
// file name Sort.cpp
// 4-14-14
// Sort and merge two vectors into one new vector.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b)
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

int main()
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
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    c = merge_sorted(a, b);
    sort(c.begin(), c.end());
    cout << "Results is..." << endl;
    for (int f = 0; f < c.size(); ++f) // display the contents of c.vector
    {
        cout << c[f] << endl;
    }
}
// 100%
