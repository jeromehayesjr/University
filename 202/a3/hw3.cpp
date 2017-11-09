/*
Jerome Hayes Jr
hw3.cpp
4-26-14
Program takes user input and search for a name that match and then display matching ssn, salary.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Record
{
    string key;
    string data;
public:
    Record(): key(""), data("") {}
    Record(string k, string d): key(k), data(d) {}
    string get_key() { return key; }
    string get_data() { return data; }
};
main()
{
    vector< Record > phones;
    vector< Record > socials;
    vector< Record > salaries;
    ifstream a_file;
    string phones_key, phones_data;
    a_file.open("phones.txt");
    while(!a_file.eof())
    {
        a_file >> phones_key >> phones_data;
        phones.push_back(Record(phones_key, phones_data)); 
    }
    a_file.close();

    ifstream b_file;
    string socials_key, socials_data;
    b_file.open("socials.txt");
    while(!b_file.eof())
    {
        b_file >> socials_key >> socials_data;
        socials.push_back(Record(socials_key, socials_data));
    } 
    b_file.close();

    ifstream c_file;
    string salaries_key, salaries_data;
    c_file.open("salaries.txt");
    while(!c_file.eof())
    {
        c_file >> salaries_key >> salaries_data;
        salaries.push_back(Record(salaries_key, salaries_data));
    }
    c_file.close();
    
    string input;
    cout << " Enter an telephone number (example: 000-000-0000)" << endl;
    cin >> input;

    while (!cin.eof())
    {
        bool work = true;
        int i, j, k;
        for (i = 0; i < phones.size() - 1; i++)
        {
            if (input == phones[i].get_data())
            {
                cout << "Name: " << phones[i].get_key() << endl;
                break;
            }
        }

        if (i == phones.size() - 1)
        {
            cout << "No Records for \"" << input << "\"" << endl;
            work = false;
        }

        if (work == true)
        {
            for (j = 0; j < socials.size() - 1; j++)
            {
                if (phones[i].get_key() == socials[j].get_key())
                {
                    cout << "SSN: " << socials[j].get_data() << endl;
                    break;
                }
            }
            if (j == socials.size() - 1)
            {
                cout << "No SSN under" << phones[i].get_key() << endl;
                cout << "No Salary under" << phones[i].get_key() << endl;
                work = false; 
            }
        }

        if (work == true)
        {
            for (k = 0; k < salaries.size() - 1; k++)
            {
                if(salaries[k].get_key() == socials[j].get_data())
                {
                    cout << "Salary: " << salaries[k].get_data() << endl;
                    break;
                }
            }
            if (k == salaries.size()-1)
            {
                cout << "No Salary under " << phones[i].get_key() << endl;
            }
            work = false;
        }
        cout << " Enter an telephone number (example: 000-000-0000)" << endl;
        cin >> input;
    }
}
