/*--------------------------------------------------------------------------------------*
Jerome Hayes Jr
Person.h
4-28-14
The header file
-----------------------------------------------------------------------------------------*/
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
    string name;
    Person * best_friend;
    int popularity;
public:
    Person(): name(""), best_friend(0), popularity(0) { }
    Person(string n): name(n), best_friend(0), popularity(0) { }
    string get_name();
    string get_best_friend();
    int get_popularity();
    void set_best_friend(Person *);
};

#endif
