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

        void setID(string newID);
        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setAddress(string newAddress);
        void setCity(string newCity);
        void setState(string newState);
        void setZIP(string newZIP);

        Customer (string id, string first, string last, string a, string c, string s, string z){
        	ID = id;
        	first_name = first;
        	last_name = last;
        	address = a;
        	city = c;
        	state = s;
        	zip = z;
        }
};

string Customer::getID(){
	return ID;
}

string Customer::getFirstName(){
	return first_name;
}

string Customer::getLastName(){
	return last_name;
}

string Customer::getAddress(){
	return address;
}

string Customer::getCity(){
	return city;
}

string Customer::getState(){
	return state;
}

string Customer::getZIP(){
	return zip;
}
#endif
