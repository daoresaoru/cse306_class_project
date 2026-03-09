#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include "transaction.h"
#include "order.h"
vector<Order> orders;
map<int, Transaction> transactions;
/*#include "customer.h"*/
using namespace std;

int main() {
    ifstream infile("customers.txt", ios::in); 
    ifstream infile("orders.txt", ios::in);
    ofstream outfile("results.txt", ios::out);
    char option, sub_option;
    string last_name, line;
    int cID, quantity, oID;
    double price;
    //Customer customer;
    cout << "Welcome to the business assissting program!\n\nPlease choose from one of the following options:\n";
    do {
        cout << "1 for adding a customer\n2 for looking up a customer by last name\n3 for placing an order\n";
        cout << "4 for Rainbow Tribbles\n5 for exiting the program\n";
        cout << "Enter your option here: ";
        cin >> option;
        switch(option)
        {
            case '1':
                //customer.input(); //the function that inputs customer info, can be renamed
                //customer.writeToFile(outfile); //the function that writes the info to the customer.txt, can be renamed
                //outfile.flush();
                cout << "well duh\n";
                break;
            case '2':
                cout << "Enter the last name: ";
                cin >> last_name;
                while (getline(infile, line)) {
                    if (line.find(last_name) != string::npos) {
                        cout << line << endl;

                    }
                }
                break;
            case '3':
                cout << "Please enter your customer ID and a quantity of tribbles you want to buy:\n";
                cout << "1 tribble - $9.50;\n2 tribbles - $16.15;\n3 tribbles - $25.88;\n4 tribbles - $28.15;\n5 tribbles - $30.00.\n";
                cin >> cID;
                cin >> quantity;
                switch (quantity)
                {
                case 1:
                    price = 9.5;
                    break;
                case 2:
                    price = 16.15;
                    break;
                case 3:
                    price = 25.88;
                    break;
                case 4:
                    price = 28.15;
                    break;
                case 5:
                    price = 30;
                    break;
                default:
                    cout << "Please enter a number between 1 and 5";
                    break;
                }
                cout << cID << " | " << quantity << " tribble(s) " << " $" << price;
                orders.push_back(Order(oID, cID, quantity, price));
                transactions[oID] = Transaction(cID, oID);
                break;
            case '4':
                do {
                cout << "Please choose what you want to do with a Rainbow Tribble:\n";
                cout << "1 for adding a person;\n2 for selling a Rainbow Tribble to the next person\n";
                cin >> sub_option;
                switch(sub_option) {
                    case '1':
                        cout << "Please enter your customer ID and a quantity of tribbles you want to buy:\n";
                        
                    case '2':
                        //rainbow.remove();
                        
                    default:
                        cout << "Please, enter one of the valid options:\n";
                } } while (sub_option != '1' && sub_option != '2');
                break;
            case '5':
                return 0;
            default:
                cout << "Please, enter one of the valid options:\n";
        } } while (true);
    return 0;
}
