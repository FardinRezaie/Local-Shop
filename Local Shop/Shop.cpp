#include "Shop.h"

Shop::Shop()
{

}

void Shop::setprice(int p)
{
	if (p <= 0) {
		throw invalid_argument("price is negative..");
	}
	else price = p;
}

void Shop::set_cost(int c)
{
	if (c <= 0) {
		throw invalid_argument("Cost is negative..");
	}
	else cost = c;
}

void Shop::setdate1(string d)
{
	if (d == "") {
		throw invalid_argument("String is Null...");
	}
	else date1 = d;
}

void Shop::checkasset(int a)
{
	if (debt > 0 && asset > debt) {
		asset = asset - debt;
		debt = 0;
	}
	else setdebt_c(debt);
}

void Shop::checkdebt(int debt)
{
	if (asset > 0 && debt > asset) {
		debt = debt - asset;
		asset = 0;
	}
	else setasset_c(debt);
}

void Shop::Buy(vector<Inventory>& inventory1, vector<Customer>& customer1)
{
	int code, c, total = 0;
	char ch;
	string d, l, n, n1;
	bool Bool = true;
	
	Shop shop;
	vector<Shop> shop1;

	cout << endl << "Choice the options that you want to Buy " << endl;
	do {
		do {
			cout << "Enter the code: ";
			cin >> code;

			if (code > inventory1.size()) {
				cout << "Wrong code...  try again." << endl;
			}
		} while (code > inventory1.size());

		shop.setcode(code);

		cout << ">>" << inventory1[code - 1].getname() << endl;

		shop.setname(inventory1[code - 1].getname());

		cout << "How many: ";
		do {
			cin >> amount;

			shop.setamount(amount);

			if (amount > inventory1[code - 1].getamount()) {
				cout << "We don't have enough amount of this item." << endl;
			}
		} while (amount > inventory1[code - 1].getamount());

		try {
			shop.setcost(inventory1[code - 1].getcost() * amount);
		}
		catch (invalid_argument& e) {
			cout << "Error(44)_S..." << e.what();
		}

		try {
			shop.setprice(inventory1[code - 1].getcost());
		}
		catch (invalid_argument& e) {
			cout << "Error(76)_S..." << e.what();
		}

		cout << "The Cost of your order is: ";
		cout << shop.getcost() << endl;
		total += shop.getcost();
		shop1.push_back(shop);

		cout << "Another Item!? (Y/N): ";
		cin >> ch;
		if (ch == 'N' || ch == 'n') {
			Bool = false;
		}
	} while (Bool);

	cout << "\nItems that you ordered." << endl;
	cout << "Item\t||" << "\tamount\t||" << "\tprise\t" << "=\tCost" << endl;
	for (int i = 0; i < shop1.size(); i++) {
		cout << shop1[i].getname() << "\t||";
		cout << "\t" << shop1[i].getamount() << "\t||";
		cout << "\t" << shop1[i].getprice() << "\t";
		cout << "=\t" << shop1[i].getcost() << "\n";
	}

	cout << "\nYour Total order price is :" << total << endl;

	cout << "Do you Want to pay it? (Y/N): ";
	cin >> ch;
	switch (ch) {
	case 'y':
	case 'Y':
		cout << "Enter amount for pay: ";
		cin >> c;

		if (c > total) {
			asset = c - total;
		}

		else if (c < total) {
			debt = total - c;
		}
		else cost = 0;

		c = customer1.size();
		c++;

		shop.addcustomer(c, name, last_n, asset, debt, address, number);
		customer1.push_back(shop);

		checkdate(date);
		shop.setdate(date);
		shop1.push_back(shop);

		for (int i = 0; i < shop1.size()-1; i++) {

			amount = inventory1[shop1[i].getcode() - 1].getamount() - shop1[i].getamount();

			try {
				inventory1[shop1[i].getcode() - 1].setamount(amount);
			}
			catch (invalid_argument& e) {
				cout << "Error(167)..." << e.what();
			}
		}
		shop.file_s(shop1);
		
		break;

	case 'n':
	case 'N':

		break;

	}

}

void Shop::update(vector<Inventory>&inventory1)
{
	for (int i = 0; i < inventory1.size(); i++) {
		if (inventory1[i].getamount() == 0) {
			inventory1.erase(inventory1.begin() + (i));
		}
	}
}

void Shop::file_s(vector<Shop>& shop1)
{
	string address, name, text;
	fstream Myfile;
	do {
		address = "F:/";
		name = "Shop.txt";

		Myfile.open(address + name, ios::app);

		if (!Myfile) {
			system("cls");
			cout << "The file could not be opened.......try again" << endl;
		}
	} while (!Myfile);
	Myfile << "Item\t" << "amount\t" << "prise\t" << "=\tCost" << endl;
	int i = 0;
	for (i = 0; i < shop1.size(); i++) {
		Myfile << shop1[i].getname();
		Myfile << "\t" << shop1[i].getamount();
		Myfile << "\t" << shop1[i].getprice();
		Myfile << "\t=\t" << shop1[i].getcost() << endl;
	}
	Myfile << "Date\t" << shop1[i-1].getdate() << endl;
	Myfile.close();
}

void Shop::read(vector<Shop>&shop)
{
	shop.clear();
	string name, address, text;
	ifstream Myfilein;
	Shop obj;
	string a, a1;
	int total = 0;

	address = "F:/";
	name = "Shop.txt";

	Myfilein.open(address + name, ios::in);
	Myfilein.seekg(0, ios::beg);

	if (!Myfilein.is_open()) {
		cerr << "Error opening file.\n";
		return;
	}

	getline(Myfilein, text);
	while (getline(Myfilein, text)) {
		stringstream inputString(text);
		try {
			getline(inputString, name, '\t');
			if (name == "Date") {
				obj.setdate(name);
				getline(inputString, name, '\n');
				obj.setdate1(name);
				break;
			}			
			obj.setname(name);
		}
		catch (invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		try {
			getline(inputString, text, '\t');
			obj.setamount(stoi(text));
		}
		catch (invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}
		
		try {
			getline(inputString, text, '\t');
			obj.setprice(stoi(text));
		}
		catch (invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}
		
		getline(inputString, name, '=');
		
		try {
			getline(inputString, text, '\n');
			obj.setcost(stoi(text));
		}
		catch (invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		text = "";
		shop.push_back(obj);
	}

	Myfilein.close();
}

void Shop::print(vector<Shop>& shop1) {
	int i = 0, t = 0;
	Shop shop;
	cout << "Item\t" << "amount\t" << "prise\t" << "=\tCost" << endl;
	for (i = 0; i < shop1.size(); i++) {
		cout << shop1[i].getname();
		cout << "\t" << shop1[i].getamount();
		cout << "\t" << shop1[i].getprice();
		cout << "\t=\t" << shop1[i].getcost() << endl;
		t += shop1[i].getcost();
	}
	cout << "Total Outcoming cost: " << t << "\n";
}

Shop::~Shop()
{
	//cout << "This is Destructor of Shop." << endl;
}
