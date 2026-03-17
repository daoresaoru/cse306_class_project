#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <customer.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

class LinkedList {
    private:
        Customer first;
    public:
        

 };
 
 class CustomerList::Node{
	private:
		Customer data;
		Node next;

	public:
		Node(Customer hold){
			data = hold;
		}
		Customer getData(){
			return data;
		}
};
 
 class CustomerList{
	private:
		class Node;
		Node first;
		Node last;
		int size;

	public:
		int getSize();
		void addCustomer(Customer);
		int search(Customer);
		Node at(int);
		void removeCustomer(Customer);
};
 
 


CustomerList::CustomerList(){
	size = 0;
}



void CustomerList::addCustomer(Customer add){
	Node n(add);
	if (size == 0){
		first = n;
	}
	else {
		last.next = n;
	}
	last = n;
	size++;
}

int CustomerList::search(Customer target){
	Node n = first;
	int index = 0;
	for (int i=0; i < size; i++){
		if (n.getData() == target){
			return index;
		}
		else{
			n = n.next;
			index++;
		}
	}
	return -1; //not found
}

Node CustomerList::at(int index){
	Node n = first;
	for (int i = 0; i < index; i++){
		n = n.next;
	}
	return n;
}

void CustomerList::removeCustomer(Customer remove){
	int index = search(remove);
	if (index != -1){
		cout << "Customer not found";
	}
	else{
		at(index - 1).next = (at(index + 1));
	}
}
}

#endif
