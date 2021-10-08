#include "Customer.h"

Customer::	Customer(int cNo,string cName){ //Constructor
	customerNo = cNo; //Setting Customer no and name values 
	customerName = cName;
}

int Customer::getCustomerNo() {
	return this->customerNo; //returns customer no
}

string Customer::toString(){
	//Returns customer no&name as a string
	return to_string(customerNo)+" "+customerName;
}

int Customer::getQuantity(){ //Returns total quantity of unshipped orders
	int total=0;
	for(int i=0;i<orders.size();i++){ //For each order;
		if(!orders[i].isShipped()){ //If order is not shipped
			total+=orders[i].getQuantity(); //add order quantity to total
		}
	}
	return total; //Then return it
}

void Customer::Ship(vector<Invoice> &iVec,int &invoiceNo,string date){ //Ships all orders and creates an invoice for customer
	if(getQuantity()>0){ //If customer has at least 1 order(Means quantity>0)
	 	iVec.insert(iVec.end(),Invoice(invoiceNo,to_string(customerNo),date,getQuantity())); //Then insert a new invoice to vector
	 	invoiceNo++; //Then add 1 to invoiceNo (1000, 1001, 1002..)
	 	for(int i=0;i<orders.size();i++){ //Then ship each order in vector
	 		orders[i].ship();
	 	}
	 }
}

void Customer::AddOrder(Order o){ //Adds new order to customers order vector
	orders.insert(orders.end(),o);
}


