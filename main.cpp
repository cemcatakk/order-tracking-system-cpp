#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Customer.h"
using namespace::std;


int getCustomer(int customerNo,vector<Customer> cVec){ //Searches for a customer in vector by customerNo
	for(int i=0;i<cVec.size();i++){ //For each customer in vector
		if(cVec[i].getCustomerNo()==customerNo){ //If customer no equals to parameter cNo
			return i; //Then return index of customer
		}
	}
	cout<<"ERROR OCCURED: No customer found with no "<<customerNo<<endl;
	return -1; //Otherwise return -1 and print error
}
void printInvoices(vector<Invoice> &iVec){ //Print each invoice(Deliver)
	for(int i=0;i<iVec.size();i++){ //For each invoice in vector
		if(!iVec[i].isDelivered()){ //If invoice is not delivered(Also means not printed before)
		 	cout<<"OP: customer "<<setfill('0') <<setw(4)<<iVec[i].getCustomerNo()<<": shipped quantity "<<iVec[i].getQuantity()<<endl; //Print information
			cout<<"SC: "<<iVec[i].toString()<<endl; //Print customer information
			iVec[i].deliver(); //Then deliver invoice
		}
	}
}

void readFile(string fileName,vector<Customer> &cVec,vector<Invoice> &iVec){ //Reads each customer&order from given file and inserts them to given vectors
	 string line,strCustomerNo,customerName,strQuantity; //String variables
	 int customerNo,invoiceNo=1000; //Integer variables and invoiceNo integer to count each invoice
	 fstream file; //fstream object to read file line-by-line
	 file.open(fileName,ios::in);  //Open given file
  	 if (file.is_open()){  //If file opened successfully
      while(getline(file, line)){  //Then read each line until EOF
         char type = line[0]; //First get type of command
		 if(type=='C'){ //C means new customer
		 	 strCustomerNo=line.substr(1,4); //Get customer no by using substring method
		 	 customerName = line.substr(5,40); //Same here
		 	stringstream strToInt(strCustomerNo); //Then convert customerNo string to integer
		 	strToInt>>customerNo; //Then set customerNo
         	cVec.insert(cVec.end(),Customer(customerNo,customerName)); //Insert new customer to vector using constructor
         	cout<<"OP: customer "<<strCustomerNo<<" added"<<endl; //Then print system message
		 }
		 else if(type=='S'){ //S means order
		 	int quantity; 
			string orderDate = line.substr(1,8); //Get order date using substring
		 	char orderType = line[9]; //Order type is 9. character
		 	string type = orderType=='N'?"normal":"EXPRESS"; //If ordertype is N, its normal order, otherwise its EXPRESS order
		 	strCustomerNo=line.substr(10,4); //Same with date & quantity
		 	strQuantity = line.substr(14,3);
		 	//Convert quantity & customerNo to integer using stringstream
		 	stringstream strToInt(strQuantity);
		 	stringstream custStrToInt(strCustomerNo);
		 	//Then set their values to it
		 	strToInt>>quantity;
		 	custStrToInt>>customerNo;
		 	//Print system message
		 	cout<<"OP: customer "<<strCustomerNo<<": "<<type<<" order: "<<"quantity "<<quantity<<endl;
		 	//Then find index of customer in vector
		 	int customerIndex = getCustomer(customerNo,cVec);
		 	if(orderType=='N'){
		 		//If its normal order, just add it to customers orders
			 cVec[customerIndex].AddOrder(Order(quantity,orderDate,"normal"));
			 }
			 else{
			 	//Otherwise add orders and ship all orders of customer then print invoices
			 	cVec[customerIndex].AddOrder(Order(quantity,orderDate,"EXPRESS"));
			 	cVec[customerIndex].Ship(iVec,invoiceNo,orderDate);
		 		printInvoices(iVec);
			 }
		 }
		 else if(type=='E'){ //E Means end of day
		 	string date = line.substr(1,8); //Get date using substring
		 	cout<<"OP: end of day "<<date<<endl; //Print system message
		 	for(int i=0;i<cVec.size();i++){ //Foreach customer, ship their orders if they have
	 			cVec[i].Ship(iVec,invoiceNo,date);
			 }
		 	printInvoices(iVec); //Then print invoices
		 }
      }
  	}
  	else{
  		cout<<"ERROR: File could not found."<<endl; //If file does not exists, print error message
  		exit(0);//And exit application
	  }
      file.close();  //Close file
}

int main(int argc, char** argv) {
	if(argc!=2){
		cout<<"Invalid arguments"; //Only 1 argument will given
	}
	else{
		vector<Customer> customers;
		vector<Invoice> invoices;
	     readFile(argv[1],customers,invoices);
	}
	return 0;
}
