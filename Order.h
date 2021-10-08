#ifndef ORDER_H
#define ORDER_H

#include <iostream>
using namespace::std;
//Order class is going to hold information about orders
class Order {

private:
	int quantity; //Each order has quantity, date, type and shipped value
	string date;
	string type;
	bool shipped;

public:
	Order(int q, string d, string t);

	int getQuantity();

	bool isShipped();

	void ship();

	string getType();
};

#endif
