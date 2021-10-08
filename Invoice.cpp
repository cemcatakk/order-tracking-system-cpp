#include "Invoice.h"

Invoice::Invoice(int invoiceNo,string customerNo,string date,int quantity){ //Constructor
	this->invoiceNo = invoiceNo; //Each of variables set from parameters
	this->customerNo=customerNo;
	this->date=date;
	this->quantity=quantity;
	delivered=false; //And delivered is false at first
}

string Invoice::getCustomerNo() {
	return this->customerNo; //returns customerNo of object
}

int Invoice::getQuantity() {
	return this->quantity; //returns quantity of object
}

string Invoice::getDate() {
	return this->date; //returns date of object
}

string Invoice::toString() {
	//returns a string with following format:
	return "customer "+customerNo+": invoice "+to_string(invoiceNo)+": date "+date+": quantity: "+to_string(quantity);
}

bool Invoice::isDelivered() {
	return this->delivered; //returns if invoice is delivered or not
}

void Invoice::deliver() {
	//delivers the invoice, this method used to print each invoice once
	delivered=true;
}
