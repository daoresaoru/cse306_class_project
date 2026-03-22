#ifndef TRANSACTION_H
#define TRANSACTION_H

using namespace std;

class Transaction {
    private:
        string customerID, orderID;
    public:
        Transaction() {
            customerID = "";
            orderID = "";
        }
        Transaction(string cID, string oID) {
            customerID = cID;
            orderID = oID;
        }
        string getcustomerID() {
            return customerID;
        }
        string getorderID(){
            return orderID;
        }
};
#endif
