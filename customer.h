#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Customer {
    private:
        string ID;
        string first_name;
        string last_name;
        string address;
        string city;
        string state;
        string zip;
    public:
        string getID();
        string getFirstName();
        string getLastName();
        string getAddress();
        string getCity();
        string getState();
        string getZIP();
        void print();
        
};
#endif
