#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
/*#include "customer.h"*/
using namespace std;

int main() {
    ifstream infile("customers.txt", ios::in); 
    ofstream outfile("results.txt", ios::out);
    char option;
    string last_name, line;
    Customer customer;
    cout << "Welcome to the business assissting program!\n\nPlease choose from one of the following options:\n";
    do {
        cout << "1 for adding a customer\n2 for looking up a customer by last name\n3 for exiting the program\n";
        cout << "Enter your option here: ";
        cin >> option;
        if (option == '1') {
            customer.input(); //the function that inputs customer info, can be renamed
            customer.writeToFile(outfile); //the function that writes the info to the customer.txt, can be renamed
            outfile.flush();
        }
        else if (option == '2') {
            cout << "Enter the last name: ";
            cin >> last_name;
            while (getline(infile, line)) {
                if (line.find(last_name) != string::npos) {
                    cout << line << endl;

                }
            }
        }
        else if (option != '3') {
            cout << "Please, enter one of the valid options:\n"; }
        } while (option != '3');
    return 0;
}
