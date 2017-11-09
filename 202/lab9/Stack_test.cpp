/*
 * Jerome Hayes Jr
 * stack_test.cpp
 * 6-9-14
 * This program was used to confuse the ish out of me. Also to use a template class with stack
*/

#include <iostream>
#include <string>

#include "Stack.h"

main()
{
    Stack<int> s1;

    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
    Stack<string> s2;
    s2.push("Yoda said ");
    s2.push("something ");
    s2.push("to write ");
    while (!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }
    s2.pop();
    cout << s2.top();
    cout << endl;
}
