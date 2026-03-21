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
        Customer() {
            ID = "";
            first_name = "";
            last_name = "";
            address = "";
            city = "";
            state = "";
            zip = "";
        }

        Customer (string id, string first, string last, string a, string c, string s, string z){
        	ID = id;
        	first_name = first;
        	last_name = last;
        	address = a;
        	city = c;
        	state = s;
        	zip = z;
        }
        

        void setID(string newID);
        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setAddress(string newAddress);
        void setCity(string newCity);
        void setState(string newState);
        void setZIP(string newZIP);

        string getID() {
            return ID;
        }

        string getFirstName() {
            return first_name;
        }

        string getLastName() {
            return last_name;
        }

        string getAddress() {
            return address;
        }

        string getCity() {
            return city;
        }

        string getState() {
            return state;
        }

        string getZIP() {
            return zip;
        }

};


#endif
