/*
 * Jerome hayes Jr
 * stack.h
 * 6-9-14
 *This is a headerfile
*/

#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

template <typename T>
class Stack
{
    vector<T> container;
public:
    Stack(): container() {}
    void push(T x) { container.push_back(x);}
    void pop() 
    {
        if(!container.empty()) 
            container.pop_back();
        else;
    }
    T top() 
    {   
         if(!container.empty())
             return container.back();
         else
             return T();
    }
    bool empty() { return container.empty(); }
};

#endif
