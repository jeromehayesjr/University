/*
Jerome hayes Jr
assignment4.cpp
6-2-14
answers homework assignment. Shows the reverse word of Mississippi and return true when it finds s in the string sip.
*/

#include <iostream>
#include <string>

using namespace std;

class Sentence
{
private:
    string word;
public:
    Sentence();
    Sentence(string w): word(w) {}
    string reverse();
    bool find(string w);
};

string Sentence:: reverse()
{
    if ( word.length() <= 1)
    {
        return word;
    }
    else
    {
        char first = word[0];
        Sentence tinyword(word.substr(1, word.length()));
        string reverseword = tinyword.reverse();
        return reverseword + first;
    }
}

bool Sentence:: find(string w)
{
    if(w[0] == 's')
    {
        return true;
    }   
    else
    {
        string shorter(w.substr(1, w.length()));
        return find(shorter);
    }
    return false;
}

main()
{
    Sentence s("Mississippi");
    cout << s.reverse() << endl; // outputs ippississiM
    bool b = s.find("sip"); // retruns true
    if (b == true)
    {
        cout << "found sentence starts with s" << endl;
    }
}
