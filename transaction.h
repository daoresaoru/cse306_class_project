#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
    private:
        int customerID, orderID;
    public:
        Transaction() {
            customerID = 0;
            orderID = 0;
        }
        Transaction(int cID, int oID) {
            customerID = cID;
            orderID = oID;
        }
        int getcustomerID() {
            return customerID;
        }
        int getorderID(){
            return orderID;
        }
};
#endif