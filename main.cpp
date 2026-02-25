#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char option;
    cout << "Welcome to the business assissting program!\n\nPlease choose from one of the following options:\n";
    do {
        cout << "(A)dd a customer\n(L)ook up a customer by last name\n(E)xit\n";
        cout << "Enter your option here:";
        cin >> option;
        if (option == 'A' || option == 'a') {
            cout << "Enter the first name";
        }
        else if (option == 'L' || option == 'l') {
            cout << "Enter the last name";
        }
        else if (option != 'q' && option != 'Q') {
            cout << "Please, enter one of the valid options:\n"; }
        } while (option != 'q' && option != 'Q');
    return 0;
}