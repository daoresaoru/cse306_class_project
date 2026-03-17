#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

#include <customer.cpp>
#include <LinkedList.cpp>

using namespace std;

int main() {
	CustomerList list;
    ifstream infile("customers.txt", ios::in);
    ofstream outfile("results.txt", ios::out);
    char option, sub_option;
    string last_name, line;
    //Customer customer;
    cout << "Welcome to the business assisting program!\n\nPlease choose from one of the following options:\n";
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
            	string first, last, id, address, city, state, zip;
                cout << "Enter the first name of the customer: ";
                cin >> first;
                cout << "Enter the last name of the customer: ";
                cin >> last;
                cout << "Enter the ID of the customer: ";
                cin >> id;
                cout << "Enter the address of the customer: ";
                cin >> address;
                cout << "Enter the city the customer lives in: ";
                cin >> city;
                cout << "Enter the state the customer lives in: ";
                cin >> state;
                cout << "Enter the ZIP code of the customer: ";
                cin >> zip;
                
                list.addCustomer(Customer(id, first, last, id, address, city, state, zip));
                cout << first << " " << last << " has been added.";
                break;
            case '2':
            	CustomerList results;
                cout << "Enter the last name: ";
                cin >> last_name;
                for (int i = 0; i++; i < list.getSize()){
                	if (last_name == list.at(i).getData().getLastName()){
                		results.addCustomer(list.at(i).getData());
                	}
                }
                int size = results.size();
                if (size == 1){
                	results.at(0).getData().print();
                }
                else if (size >= 1){
                	int select;
                	cout << "Multiple customers found. Select the option that you want to view:";
                	for (int i = 0; i < results.size(); i++){
                		cout << (i + 1) + ". " + results.at(i).getData().print();
                	}
                	cin >> select;
                	results.at(select - 1).getData().print();
                }
                break;
            case '3':
            	string id;
            	int amount;
                cout << "Please enter your customer ID: ";
                cin >> id;
                cout << "Please enter the number of tribbles being purchased: ";
                cin >> amount;
                cout << "1 tribble - $9.50;\n2 tribbles - $16.15;\n3 tribbles - $25.88;\n4 tribbles - $28.15;\n5 tribbles - $30.00.\n";
                //cin >> order.id >> number;
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
