#ifndef ORDER_H
#define ORDER_H

class Order {
    private:
        string customerID, orderID;
        int quantity;
        double price;
    public: 
        Order() {
            customerID = "";
            orderID = "";
            quantity = 0;
            price = 0;
        }
        Order(string cID, string oID, int qty, double p) {
            customerID = cID;
            orderID = oID;
            quantity = qty;
            price = p;
        }
        string getcustomerID() {
            return customerID;
        }
        string getorderID(){
            return orderID;
        }
        int getquantity() {
            return quantity;
        }
        double getprice() {
            return price;
        }
};

#endif
