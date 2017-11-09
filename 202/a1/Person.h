#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
// Jerome Hayes Jr
// file name: Person.h
// 4-18-14
// describition
//
using namespace std; 
class Person
{
private:
    string name;
    string day;
    string year;
    string month;
public:
    Person();
    Person(string name, string month, string day, string year);
    string get_person();
    string get_month();
};
#endif
