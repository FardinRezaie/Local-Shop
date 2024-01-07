#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Inventory
{
private:
	string name;
	int code;
	int totalcost;
	unsigned long int cost;
	unsigned long int amount;
	string type;
	string date;

public:
	Inventory(string = ".", int = 1, int = 0, int = 0, int = 0, string = "", string = "");

	void setname(string);
	string getname() { return name; };

	void setcode(int);
	int getcode() { return code; };

	void setcost(int);
	int getcost() { return cost; };

	void settotalcost(int);
	int gettotalcost() { return totalcost; };

	void setamount(int);
	int getamount() { return amount; };

	void settype(string);
	string gettype() { return type; };

	void setdate(string);
	void checkdate(string&);
	string getdate() { return date; };

	void additem(int, string, string, string, int, int);

	void Edititem(vector<Inventory>&);

	void Deleteitem(vector<Inventory>&);

	void file(vector<Inventory>&);

	void read(vector<Inventory>&);

	void update(vector<Inventory>&);

	void printInventory(vector<Inventory>&);

	~Inventory();
};

