//  Generated by StarUML(tm) C++ Add-In
/*
Jerome Hayes Jr
5/5/14
student.h
Header file
*/


#include "Person.h"

#if !defined(_STUDENT_H)
#define _STUDENT_H

using namespace std;


class Student: public Person 
{
public:
    Student();
    Student(string n, string d, string g, string m);
    virtual void print();
protected:
    string major;
};

#endif  //_STUDENT_H
