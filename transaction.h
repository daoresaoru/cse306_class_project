#ifndef TRANSACTION_H
#define TRANSACTION_H

using namespace std;

class Transaction {
    private:
        string customerID, orderID;
        int employeeID;
    public:
        Transaction() {
            customerID = "";
            orderID = "";
            employeeID = 0;
        }
        Transaction(string cID, string oID, int eID) {
            customerID = cID;
            orderID = oID;
            employeeID = eID;
        }
        string getcustomerID() {
            return customerID;
        }
        string getorderID(){
            return orderID;
        }
        int getemployeeID() {
            return employeeID;
        }
};
#endif
