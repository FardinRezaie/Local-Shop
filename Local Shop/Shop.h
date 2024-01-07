#pragma once
#include "Inventory.h"
#include "Customer.h"
class Shop :
	public Inventory, public Customer
{
private:
	string name;
	string last_n;
	int code;
	int debt = 0;
	int asset = 0;
	long int cost = 0;
	long int price = 0;
	long int amount;
	string address;
	string number;
	string type;
	string date;
	string date1;

public:
	Shop();

	void Buy(vector<Inventory>&, vector<Customer>&);

	void file_s(vector<Shop>& shop1);

	void read(vector<Shop>&);

	void print(vector<Shop>&);

	void update(vector<Inventory>&);

	void setprice(int);
	int getprice() { return price; };

	void set_cost(int);
	int get_cost() { return cost; };

	void setdate1(string);
	string getdate1() { return date1; };

	void checkasset(int a);

	void checkdebt(int debt);

	~Shop();
};

