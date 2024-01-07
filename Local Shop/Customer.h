#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


class Customer
{
private:
	string name;
	string last_n;
	int code;
	int debt;
	int asset;
	string address;
	string number;
public:
	Customer(string = "", string = "", string = "", int = 0, int = 0, int = 0, string = "");

	void setname_c(string);
	string getname_c() { return name; };

	void setlast_n(string);
	string getlast_n() { return last_n; };

	void setaddress_c(string);
	string getaddress_c() { return address; };

	void setcode_c(int);
	int getcode_c() { return code; };

	void setdebt_c(int);
	int getdebt_c() { return debt; };

	void setasset_c(int);
	int getasset_c() { return asset; };

	void setnumber_c(string n);
	string getnumber_c() { return number; };

	void addcustomer(int, string, string, int, int, string, string);

	void Editcustomer(vector<Customer>&);
	void Deletecustomer(vector<Customer>&);

	void file_c(vector<Customer>&);

	void read_c(vector<Customer>&);

	void printCustomer(vector<Customer>&);

	~Customer();
};

