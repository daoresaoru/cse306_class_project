#ifndef ORDER_H
#define ORDER_H

class Order {
    private:
        int customerID, orderID, quantity;
        double price;
    public: 
        Order() {
            customerID = 0;
            orderID = 0;
            quantity = 0;
            price = 0;
        }
        Order(int cID, int oID, int qty, double p) {
            customerID = cID;
            orderID = oID;
            quantity = qty;
            price = p;
        }
        int getcustomerID() {
            return customerID;
        }
        int getorderID(){
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