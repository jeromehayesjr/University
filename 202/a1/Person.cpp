// Jerome Hayes Jr
// file name: Person.cpp
//4-18-14
// Displays the name and birthday of friends with the given month name.
#include <iostream>
#include <vector>
#include <string>
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

Person::Person()
{
}
Person::Person(string name, string month, string day, string year)
{
    name = name;
    month = month;
    day = day;
    year = year;
}
string Person::get_month()
{
    return month;
}
string Person::get_person()
{
    return name + " " + month + " " + day + " " + year;
}

int main()
{
    vector<Person> friends;

    friends.push_back(Person("Aunjane", "Jul", "20", "1995"));
    friends.push_back(Person("Jamil", "Jun", "21", "1999"));
    friends.push_back(Person("Chris", "May", "30", "1994"));
    friends.push_back(Person("Avery", "Apr", "22", "2000"));
    friends.push_back(Person("Jerome", "Aug", "26", "1994"));

    string input;
    cout << "Enter the first three letters of any month. \n";
    cin >> input;

    for (int i = 0; i < friends.size(); i++)
    {   
        if (input == friends[i].get_month() )
        {
            cout << friends[i].get_person() << endl;
        }
    }
}

