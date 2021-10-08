#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Order.h"
#include "Invoice.h"
#include <vector>
#include <iostream>
using namespace::std;
class Customer {

private:
	int customerNo; //Each customer has a customer number and name
	string customerName;
	vector<Order> orders; //Alsa each customer has their orders

public:
	int getCustomerNo();

	string toString();

	int getQuantity();

	void Ship(vector<Invoice> &iVec,int &invoiceNo,string date);

	void AddOrder(Order o);

	Customer(int cNo, string cName);
};

#endif
