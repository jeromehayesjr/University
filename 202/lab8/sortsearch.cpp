/*
 * Jerome Hayes Jr
 * 6/2/14
 * sortsearch.cpp
 * description
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void selection_sort(vector<int> & arr)
{     
    int n = arr.size();
    int i, j;
    for(i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[i] > arr[j])                 
                swap(arr[i], arr[j]);
}

int binary_search(vector<int> v, int from, int to, int value)
{
    if(from >to)
        return -1;
    int mid = (from + to);
    if (v[mid] == value)
        return mid;
    else if (v[mid] < value)
        return binary_search(v, mid + 1, to , value);
    else
        return binary_search(v, from, mid - 1, value);
}

int string_to_int(string s)
{
    istringstream in_str(s);
    int n;
    in_str >> n;
    return n;
}

main()
{
    vector <int> data;
    ifstream in;
    in.open("input.txt");
    if (in.fail())
    {
        cout << " Problem opening file";
        return 1;
    }
    string line;
    getline(in,line); // puts whatever is on a single line into a single title "line).
    while(!in.eof())
    {
        int n = string_to_int(line);
        data.push_back(n);
        getline(in,line);
    }
    in.close();
    selection_sort(data);
    for (int i =0; i < data.size(); i++)
    {
        cout << data[i]<< endl;

    }
    int input;
    cout << " Enter a number to search" << endl;
    cin >> input;
    int hi = binary_search(data,0,data.size()-1,input);
    cout << endl;
    cout << "" << hi<< endl;
}
