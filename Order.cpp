#include "Order.h"
//Constructor method
Order::	Order(int q,string d,string t){
			quantity=q;
			date=d;
			type=t;
			shipped=false; //Shipped is always false first
		}

//get/set methods
int Order::getQuantity() {
	return this->quantity;//returns quantity of order
}

bool Order::isShipped() {
	return this->shipped; //returns true/false
}
void Order::ship() {
	shipped=true; //sets shipped to true
}

string Order::getType() {
	return this->type; //returns type of order (Express/normal)
}
