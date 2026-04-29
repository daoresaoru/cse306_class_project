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
        string encodedpw;
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

        Customer (string id, string pw, string first, string last, string a, string c, string s, string z){
        	ID = id;
            encodedpw = pw;
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
        void setPassword(string newPassword){
            encodedpw = newPassword;
        }

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

        string getPassword(){
            return encodedpw;
        }

        void print(){
            cout << ID << "; " << encodedpw << "; " << first_name << "; " << last_name << "; " << address << "; " << city << "; " << state << "; " << zip << endl;
        }

        string write(){
            string text = ID;
            text.append(";");
            text.append(encodedpw);
            text.append(";");
            text.append(first_name);
            text.append(";");
            text.append(last_name);
            text.append(";");
            text.append(address);
            text.append(";");
            text.append(city);
            text.append(";");
            text.append(state);
            text.append(";");
            text.append(zip);
            return text;
        }

};


#endif
