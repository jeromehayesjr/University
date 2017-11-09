/*
Jerome Hayes Jr
palindrome.cpp
5-19-14
This program determine if the string enter is a palindrome regarding of Capsize.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool is_palindrome(string s)
{
    
    if (s.length() <= 1)
    {
        return true;
    }
    char first = s[0];
    char last = s[s.length()-1];
    if (!isalpha(first))
    {
        string shorter = s.substr(1, s.length()-1);
        return is_palindrome(shorter);
    }
    if (!isalpha(last))
    {
        string shorter = s.substr(0, s.length()-2);
        return is_palindrome(shorter);
    }
    if (tolower(first) == tolower(last))
    {
        string shorter = s.substr(1, s.length()-2);
        return is_palindrome(shorter);
    }
    return false;
}

main()
{
    cout << "Enter a string: ";
    string input;
    getline(cin, input);
    cout << "\'" << input << "\' is ";
    if (!is_palindrome(input))
    {
        cout << "not ";
    }
    cout << "a palindrome.\n";
}
