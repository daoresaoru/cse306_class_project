#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include "transaction.h"
#include "order.h"
#include "customer.h"
#include "rainbow.h"

using namespace std;

vector<Order> orders;
vector<Customer> customers;
vector<Customer> searchList; // used for creating a menu of search results
map<string, Transaction> transactions;
vector<Rainbow> rainbows;

bool existsID(string search); //function to check if an ID already exists


int main() {
    ifstream infile("customers.txt", ios::in); 
    ifstream orders_file("orders.txt", ios::in);
    ifstream transactions_file("transactions.txt", ios::in);
    ifstream rainbow_file("rainbowList.txt", ios::in);
    ofstream customer("customers.txt", std::ios::app);
    ofstream order("orders.txt", std::ios::app);
    ofstream transaction("transactions.txt", std::ios::app);
    ofstream rainbow("rainbowList.txt", std::ios::app);

    char option, sub_option; //these are for menu and Rainbow Tribble sub-menu
    string last_name; //used for searching by last name 
    string search_id; // used for searching by ID
    string cID, oID; //customerID and orderID
    string line_orders, line_transactions, line_customers, line_rainbow; //strings used for reading from files
    string word, date; //other strings
    string first, last, id, address, city, state, zip; //variables used for customer class
    int quantity; 
    double price; 

    while(getline(infile, line_customers)) { //read from txt files and store into data structures
        stringstream ss(line_customers);
        for (int i=0; getline(ss, word, ';'); i++) //breaking down the string; loops until string ends
            {
                
                switch (i) //goes through every part of the line
                {
                case 0:
                    id = word;
                    break;
                case 1:
                    first = word; 
                    break;
                case 2:
                    last = word;
                case 3:
                    address = word;
                case 4:
                    city = word;
                case 5:
                    state = word;
                case 6:
                    zip = word;
                } 
            }
            customers.push_back(Customer(id, first, last, address, city, state, zip)); //create a vector of Customer objects
    }


    while(getline(transactions_file, line_transactions)) {
        stringstream ss(line_transactions);
        for (int i=0; getline(ss, word, ';'); i++) 
            {
                
                switch (i) 
                {
                case 0:
                    cID = word;
                    break;
                case 1:
                    oID = word; 
                    break;
                } 
            }
            transactions[oID] = Transaction(cID, oID); //creates transactions read from file
    }




    while (getline(orders_file, line_orders)) {
        stringstream ss(line_orders);
        for (int i=0; getline(ss, word, ';'); i++) 
            {
                
                switch (i) 
                {
                case 0:
                    oID = word; 
                    break;
                case 1:
                    date = word; 
                    break;
                case 2:
                    quantity = stoi(word); //stoi() function turns string into int
                    break;
                case 3:
                    price = stod(word); //stod() function turns string into double
                    break;
                
                } 
                cID = transactions[oID].getcustomerID();
            }
            orders.push_back(Order(oID, cID, quantity, price));
    }

    while(getline(rainbow_file, line_rainbow)) {
            id = line_rainbow;
            rainbows.push_back(Rainbow(id));
        }    
        




    cout << "Welcome to the business assisting program!\n\nPlease choose from one of the following options:\n";
    do {
        cout << "1 for adding a customer\n2 for looking up a customer by last name\n3 for placing an order\n";
        cout << "4 for managing Rainbow Tribble orders\n5 for exiting the program\n";
        cout << "Enter your option here: ";
        cin >> option;
        cout << endl;
        switch(option)
        {
            case '1':
                do {id = to_string(rand()%1000000);
                    while (id.length() < 6){
                        id = id.insert(0, "0");
                    }
                } while (existsID(id));
                cout << "Enter the first name of the customer: ";
                cin >> first;
                cout << "Enter the last name of the customer: ";
                cin >> last;
                cout << "Enter the address of the customer: ";
                cin.ignore();
                getline(cin, address);
                cout << "Enter the city the customer lives in: ";
                cin >> city;
                cout << "Enter the state the customer lives in: ";
                cin >> state;
                cout << "Enter the ZIP code of the customer: ";
                cin >> zip;

                customers.push_back(Customer(id, first, last, address, city, state, zip));
                
                
                customer << "\n" << customers[customers.size()-1].write();
                customer.close(); //adds a new Customer object to a vector
                cout << first << " " << last << " has been added.\n";
                break;
            case '2':
                int searchChoice;
                do{
                    cout << "Enter 1 to search by last name, 2 to search by ID or 0 to go back: ";
                    cin >> searchChoice;
                    if (searchChoice == 1){
                        cout << "Enter the last name: ";
                        cin >> last_name;
                        for (int i = 0; i<customers.size(); i++) {
                            if (last_name == customers[i].getLastName()) { //looks for a last name
                                searchList.push_back(customers[i]);
                            }
                        }
                        if (searchList.size() == 0){
                            cout << "No customers with last name " << last_name << " found.\n";
                        }
                        else if (searchList.size() == 1){
                            searchList[0].print(); //output customer with last name
                        }
                        else{
                            int listPosition;
                            cout << "Select from the following list of customers: \n";
                            for (int i = 0; i < searchList.size(); i++){
                                cout << (i + 1) << ". " << searchList[i].getFirstName() << " " << searchList[i].getLastName() << endl;
                            }
                            cin >> listPosition;
                            searchList[listPosition - 1].print(); //output chosen customer
                        }
                    }
                    else if (searchChoice == 2){
                        cout << "Enter the ID: ";
                        cin >> search_id;
                        for (int i = 0; i < customers.size(); i++){
                            if (customers[i].getID() == search_id){
                            customers[i].print(); //output customer with ID if found
                            }
                            else if (i == customers.size() - 1){
                                cout<< "Customer with ID " << search_id << " not found.\n";
                            }
                        }
                    }
                    else if (searchChoice != 0){
                        cout << "Invalid entry\n";
                    }
                } while (searchChoice != 1 && searchChoice != 2 && searchChoice != 0);
                searchList.clear();
                break;
            
            case '3':
                do{
                    cout << "Please enter the customer ID followed by the quantity of tribbles you want to buy:\n";
                    cout << "1 tribble - $9.50;\n2 tribbles - $16.15;\n3 tribbles - $25.88;\n4 tribbles - $28.15;\n5 tribbles - $30.00;\n"
                    << "0 to go back.\n";
                    cin >> cID >> quantity;
                    if (!existsID(cID) && quantity != 0){
                        cout << "ID not found.\n";
                        break;
                    }
                    if (quantity < 0 || quantity > 5){
                        cout << "Please enter a quantity of tribbles from 0 to 5";
                    }
                } while (quantity != 0 && !existsID(cID) && (quantity < 0 || quantity > 5));
                switch (quantity)
                {
                case 0:
                    break;
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
                    cout << "Please enter a number from 0 to 5";
                    break;
                }
                if (quantity != 0){
                    cout << cID << " | " << quantity << " tribble(s) |" << " $" << price << "\n";
                    orders.push_back(Order(oID, cID, quantity, price)); //adds a new Order object to a vector
                    order << "\n" << orders[orders.size() - 1].getorderID() << ";" << orders[orders.size() - 1].getcustomerID() << ";" 
                    << orders[orders.size() - 1].getquantity() << ";" << orders[orders.size() - 1].getprice();
                    order.close();
                    transactions[oID] = Transaction(cID, oID); //add a bew Transaction object to a map
                    transaction << "\n" << transactions[oID].getcustomerID() << ";" << transactions[oID].getorderID();
                    transaction.close(); 
                }
                break;
            case '4':
                do {
                cout << "Please choose what you want to do with a Rainbow Tribble:\n";
                cout << "1 for adding a person;\n2 for selling a Rainbow Tribble to the next person\n";
                cin >> sub_option;
                switch(sub_option) {
                    case '1':
                        cout << "Please enter the customer ID:\n";
                        cin >> id;
                        rainbows.push_back(Rainbow(id)); //adds a new Rainbow object to a vector
                        rainbow << rainbows[rainbows.size() - 1].getID();
                        rainbow.close();
                        break;
                        
                    case '2': {
                    cout << "Please enter your customer ID: ";
                        cin >> id;
                        for (int i=0; i<rainbows.size(); i++) {
                            if (rainbows[i].getID() == id) { //gets rid of a Rainbow object based on the inputted ID
                                rainbows.erase(rainbows.begin() + i);
                                break;
                            }
                        for (int i=0; i<rainbows.size(); i++) {
                            cout << "\n" << rainbows[i].getID() << endl;
                        }
                            
                        }
                        ofstream rainbow_two("rainbowList.txt");
                        for (int i=0; i<rainbows.size(); i++) {
                            rainbow_two << rainbows[i].getID() << endl;
                        }
                        rainbow_two.close();
                        break; }
                        
                        
                        
                        
                    default:
                        cout << "Please, enter one of the valid options:\n"; //validation
                } } while (sub_option != '1' && sub_option != '2' && sub_option != '0');
                break;
            case '5':
                return 0;
            default:
                cout << "Please, enter one of the valid options:\n"; //validation
        }
        cout << endl;
        } while (true);
    return 0;
}


bool existsID(string search){
    for (int i = 0; i < customers.size(); i++){
        if (customers[i].getID().compare(search) == 0){
            return true;
        }
    }
    return false;
}

