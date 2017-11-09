#ifndef PERSON_H
#define PERSON_H

// Jerome Hayes Jr
// Person.h
// April 17 2014
// descr

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string month; 
	string day; 
	string year;
public:
    Person();
    Person(string name, string month, string day, string year);
	string get_person();
	string get_month();
};

#endif
