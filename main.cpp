#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream infile("customers.txt", ios::in); 
    ofstream outfile("results.txt", ios::out);
    char option;
    cout << "Welcome to the business assissting program!\n\nPlease choose from one of the following options:\n";
    do {
        cout << "1 for adding a customer\n2 for looking up a customer by last name\n3 for exiting the program\n";
        cout << "Enter your option here: ";
        cin >> option;
        if (option == '1') {
            cout << "Enter the first name: ";
        }
        else if (option == '2') {
            cout << "Enter the last name: ";
        }
        else if (option != '3') {
            cout << "Please, enter one of the valid options:\n"; }
        } while (option != '3');
    return 0;
}