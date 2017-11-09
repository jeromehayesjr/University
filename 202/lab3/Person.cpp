// Samuel Montes
// Person.cpp
// April 17 2014
// descr

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person(): name()  { }

Person::Person(string name, string month, string day, string year): name(name), month(month), day(day), year(year) { }

string Person::get_person()
{
	return name + " " + month + " " + day + " " + year;
}

string Person::get_month()
{
	return month;
}

using namespace std;

int main()
{
	vector<Person> friends;

	string name;
	string month;
	string day;
	string year;
    string usern;

	ifstream file("names");
	cout << "Enter the first three letters of a month here: ";
	cin >> usern;

	while (file.good()) {
		file >> name >> month >> day >> year;
		friends.push_back(Person(name, month, day, year));
	}
	file.close();

	for (int i = 0; i < friends.size() - 1; i++) {
		if (friends[i].get_month() == usern) {	
	        cout << friends[i].get_person() << endl;
		}
	}	
}
