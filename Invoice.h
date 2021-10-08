#ifndef INVOICE_H
#define INVOICE_H
#include <iostream>
using namespace::std;

//Invoice class holds invoice information
class Invoice {
private:
	int invoiceNo; //Invoice number
	string customerNo; //Customer number
	string date; //Inv. Date 
	int quantity; //Total Quantity of orders
	bool delivered; //Is delivered or not

public:
	Invoice(int invoiceNo, string customerNo, string date, int quantity);

	string getCustomerNo();

	int getQuantity();

	string getDate();

	string toString();

	bool isDelivered();

	void deliver();
};

#endif
