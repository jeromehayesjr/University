/*---------------------------------------------------------------
Jerome Hayes Jr
Person_main.cpp
4-28-14
Program asks user to input names and then the names bestfrined. Then display each person, their bestfriends, and the number of bestfriends they have.
----------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Person.h"

using namespace std;

main()
{
    string name;
    vector<Person *> people; // vector of pointers to objects of type Person
    Person * person_pointer;

    cout << "Enter the names, terminate with -1: ";
    cin >> name;
    while (name != "-1")
    {
        int i;
        for (i = 0; i < people.size(); i++) // checking for duplicates names
            if (people[i] -> get_name() == name)
                break;
        if (i == people.size())
        {
            person_pointer = new Person(name); // is a new person in array
            people.push_back(person_pointer);
        }
        else
        {
            cout << "name is a duplicate";
        }
        cout << "Enter another name, end  with -1: ";
        cin >> name;
        
    }
    
    int i, j;

    // for each person prompt for a best friend name
    for (i = 0; i < people.size();)
    {
        cout << "Who is " << people[i]->get_name() << "'s best friend? ";
        cin >> name;

        // search for best friend
        for (j = 0; j < people.size(); j++)
        {
            if (people[j]->get_name() == name)
            {
                break;
            }
        }
        if (j < people.size()) // found a best friend
        {   
            people[i]->set_best_friend(people[j]);
            i++;
        }
        else
        {
            cout << " Couldn't find best friend " << name << endl;
            cout << " Try again, what is another name? ";
        }
    }
    
    // List of name, best friend, and popularity count
    for (i = 0; i < people.size(); i++)
    {
        person_pointer = people[i];
        cout << left << setw(10) << person_pointer->get_name();
        cout << left << setw(10) << person_pointer->get_best_friend();
        cout << right << setw(2) << person_pointer->get_popularity() << endl;
    }

    // clean up
    for (i = 0; i < people.size(); i++)
        delete people[i];
}
