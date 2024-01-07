#include "Customer.h"

Customer::Customer(string n, string l, string d, int c, int d1, int a, string n1)
{
	//cout << "This is a Customer Constractor.." << endl;
	name = n;
	last_n = l;
	address = d;
	code = c;
	debt = d1;
	asset = a;
	number = n1;
}

void Customer::setname_c(string n)
{
	if (n == "") {
		throw invalid_argument("String is Null.");
	}
	else if (n[0] >= 'a' && n[0] <= 'z') {
		n[0] -= 32;
		name = n;
	}
	else {
		name = n;
	}
}

void Customer::setlast_n(string l)
{
	if (l == "") {
		throw invalid_argument("String is Null.");
	}
	else if (l[0] >= 'a' && l[0] <= 'z') {
		l[0] -= 32;
		last_n = l;
	}
	else {
		last_n = l;
	}
}

void Customer::setaddress_c(string d)
{
	if (d == "") {
		throw invalid_argument("Address of customer is Empty...");
	}
	else address = d;
}

void Customer::setcode_c(int c)
{
	if (c <= 0) {
		throw invalid_argument("Code customer is Empty...");
	}
	else code = c;
}

void Customer::setasset_c(int a)
{
	if (a < 0) {
		throw invalid_argument("Asset is Negative...");
	}
	else asset = a;
}

void Customer::setdebt_c(int d)
{
	if (d < 0) {
		throw invalid_argument("Debt is Negative...");
	}
	else debt = d;
}

void Customer::setnumber_c(string n)
{
	if (n == "") {
		throw invalid_argument("Number of customer is Empty...");
	}
	else number = n;
}

void Customer::addcustomer(int c, string n, string l, int a, int a1, string d, string n1)
{
	//....... code
	do {
		try {
			setcode_c(c);
		}
		catch (invalid_argument& e) {
			cout << "Error(117)..." << e.what();
		}
	} while (c <= 0);

	//.............. set name
	do {
		cout << "Name : ";
		cin.ignore();
		getline(cin, n);
		try {
			setname_c(n);
		}
		catch (invalid_argument& e) {
			cout << "Error(95_c)..." << e.what();
		}
	} while (n == "");

	//.............. set last name
	do {
		cout << "last name : ";
		getline(cin, l);
		try {
			setlast_n(l);
		}
		catch (invalid_argument& e) {
			cout << "Error(107_c)..." << e.what();
		}
	} while (l == "");

	//.............. Asset
	do {

		try {
			setasset_c(a);
		}
		catch (invalid_argument& e) {
			cout << "Error(120_c)..." << e.what();
		}
	} while (a < 0);

	//.............. Debt
	do {
		try {
			setdebt_c(a1);
		}
		catch (invalid_argument& e) {
			cout << "Error(132_c)..." << e.what();
		}
	} while (a1 < 0);

	//.............. address
	do {
		cout << "Address: ";
		getline(cin, d);
		try {
			setaddress_c(d);
		}
		catch (invalid_argument& e) {
			cout << "Error(145_c)..." << e.what();
		}
	} while (d == "");

	//.............. Number
	do {
		cout << "Number: ";
		getline(cin, n1);
		try {
			setnumber_c(n1);
		}
		catch (invalid_argument& e) {
			cout << "Error(157_c)..." << e.what();
		}
	} while (n1 == "");


}

void Customer::Editcustomer(vector<Customer>& customer)
{
	{
		int n = 0, code = 0;
		string name, address, text;
		ifstream Myfilein;
		stringstream inputString(text);
		Customer obj;

		address = "F:/";
		name = "Customers.txt";

		Myfilein.open(address + name, ios::in);
		Myfilein.seekg(0, ios::beg);

		if (!Myfilein.is_open()) {
			cerr << "Error opening file.\n";
			return;
		}

		do {
			cout << endl;
			cout << "Enter the code customer that you want to Edit: ";
			cin >> code;

			if (code > customer.size()) {
				cout << "Wrong code...  try again." << endl;
			}
		} while (code > customer.size());

		cout << "Which information of this customer do you want to edit!?." << endl;
		cout << "(1 for Name),(2 for Last name),(3 for Asset),(4 for Debt),(5 for Number),(6 for Address): ";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Enter new Name: ";
			cin.ignore();
			getline(cin, text);
			customer[code - 1].setname_c(text);
			break;

		case 2:
			cout << "Enter new Last name: ";
			cin.ignore();
			getline(cin, text);
			customer[code - 1].setlast_n(text);
			break;
			break;

		case 3:
			cout << "Enter new Asset: ";
			cin.ignore();
			getline(cin, text);
			customer[code - 1].setasset_c(stoi(text));
			break;

		case 4:
			cout << "Enter new Debt: ";
			cin.ignore();
			getline(cin, text);
			customer[code - 1].setdebt_c(stoi(text));
			break;

		case 5:
			cout << "Enter new Number: ";
			cin.ignore();
			getline(cin, text);
			customer[code - 1].setnumber_c(text);
			break;

		case 6:
			cout << "Enter new Address: ";
			cin.ignore();
			getline(cin, text);
			customer[code - 1].setaddress_c(text);
			break;
		}

		cout << "The file was edited" << endl;
		Myfilein.close();
	}
}

void Customer::Deletecustomer(vector<Customer>& customer)
{
	{
		int n = 0, code = 0;
		string name, address, text;
		ifstream Myfilein;
		stringstream inputString(text);
		Customer obj;

		address = "F:/";
		name = "Customers.txt";

		Myfilein.open(address + name, ios::in);
		Myfilein.seekg(0, ios::beg);

		if (!Myfilein.is_open()) {
			cerr << "Error opening file.\n";
			return;
		}

		do {
			cout << endl;
			cout << "Enter the code customer that you want to Delete: ";
			cin >> code;

			if (code > customer.size()) {
				cout << "Wrong code...  try again." << endl;
			}
		} while (code > customer.size());

		customer.erase(customer.begin() + (code - 1));

		cout << "The file was Deleted" << endl;
		Myfilein.close();
	}
}

void Customer::file_c(vector<Customer>& customer1)
{
	string name, address, text;
	fstream Myfile1;

	address = "F:/";
	name = "Customers.txt";

	Myfile1.open(address + name, ios::out);

	Myfile1 << "Code\t||" << "Name\t||" << "Last Name\t||" << "Asset\t||" << "Debt\t||" << "Address\t||" << "Number\t||" << endl;
	for (int i = 0; i < customer1.size(); i++) {

		Myfile1 << customer1[i].getcode_c() << "\t";
		Myfile1 << customer1[i].getname_c() << "\t";
		Myfile1 << customer1[i].getlast_n() << "\t";
		Myfile1 << customer1[i].getasset_c() << "\t";
		Myfile1 << customer1[i].getdebt_c() << "\t";
		Myfile1 << customer1[i].getaddress_c() << "\t";
		Myfile1 << customer1[i].getnumber_c() << "\n";
	}
	Myfile1.close();

}

void Customer::read_c(vector<Customer>& customer)
{
	customer.clear();
	string text;
	ifstream Myfilein;
	Customer obj;
	string null;
	address = "F:/";
	name = "Customers.txt";

	Myfilein.open(address + name, ios::in);
	Myfilein.seekg(0, ios::beg);

	if (!Myfilein.is_open()) {
		cerr << "Error opening file.\n";
		return;
	}

	getline(Myfilein, text);
	while (getline(Myfilein, text)) {
		stringstream inputString(text);

		//........code
		try {
			getline(inputString, text, '\t');
			obj.setcode_c(stoi(text));
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		//........name
		try {
			getline(inputString, name, '\t');
			obj.setname_c(name);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		//........last name
		try {
			getline(inputString, text, '\t');
			obj.setlast_n(text);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		//........Asset
		try {
			getline(inputString, text, '\t');
			obj.setasset_c(stoi(text));
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		//........Debt
		try {
			getline(inputString, text, '\t');
			obj.setdebt_c(stoi(text));
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		//........Address
		try {
			getline(inputString, text, '\t');
			obj.setaddress_c(text);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		//........Number
		try {
			getline(inputString, text, '\n');
			obj.setnumber_c(text);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		text = "";
		customer.push_back(obj);
	}

	Myfilein.close();
}

void Customer::printCustomer(vector<Customer>& customer1) {
	cout << "\t\t|-| ..........Customers .......... |-|\n\n";
	cout << "Code\t||" << "\tName\t||" << "\tLast Name\t||" << "\tAsset\t||" << "\tDebt\t||" << "\tAddress\t||" << "\tNumber\t" << endl;
	for (int i = 0; i < customer1.size(); i++) {

		cout << customer1[i].getcode_c() << "\t||";
		cout << "\t" << customer1[i].getname_c() << "\t||";
		cout << "\t" << customer1[i].getlast_n() << "\t||";
		cout << "\t" << customer1[i].getasset_c() << "\t||";
		cout << "\t" << customer1[i].getdebt_c() << "\t||";
		cout << "\t" << customer1[i].getaddress_c() << "\t||";
		cout << "\t" << customer1[i].getnumber_c() << "\n";

	}
}

Customer::~Customer() {
	//cout << "This is a Customer Destructor" << endl;
}