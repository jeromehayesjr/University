/*----------------------------------------------------------------------------------
Jerome Hayes Jr
Person.cpp
4-28-14
Impementations of all the stuff I declared in the header file.
-----------------------------------------------------------------------------------*/

#include "Person.h"

string Person::get_name()
{
    return name;
}

string Person::get_best_friend()
{
    if (best_friend !=0) // check for null pointer
        return best_friend ->name;
    else return "";
}

int Person::get_popularity()
{
    return popularity;
}

void Person::set_best_friend(Person *bf)
{
    best_friend = bf;
    (bf->popularity)++;
}
