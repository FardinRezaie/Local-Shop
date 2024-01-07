#include "Inventory.h"

Inventory::Inventory(string n, int c, int c1,int tc, int a, string t, string d)
{
	//cout << "This is a Inventory Constractor.." << endl;
	name = n;
	code = c;
	cost = c1;
	totalcost = tc;
	amount = a;
	type = t;
	date = d;
}

void Inventory::setname(string n)
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

void Inventory::setcode(int c)
{
	if (c <= 0) {
		throw invalid_argument("Code is negative..");
	}
	else code = c;
}

void Inventory::setcost(int c)
{
	if (c <= 0) {
		throw invalid_argument("Cost is negative..");
	}
	else cost = c;
}

void Inventory::settotalcost(int c)
{
	if (c < 0) {
		throw invalid_argument("Total Cost is negative..");
	}
	else totalcost = c;

}

void Inventory::setamount(int a)
{
	if (a < 0) {
		throw invalid_argument("Amount is negative..");
	}
	else amount = a;
}

void Inventory::settype(string t)
{
	if (t == "") {
		throw invalid_argument("String is Null.");
	}
	else type = t;
}

void Inventory::setdate(string d)
{
	if (d == "") {
		throw invalid_argument("String is Null...");
	}
	else date = d;
}
void Inventory::checkdate(string& d)
{
	int year = 0, month = 0, day = 0;

	do {
		cin.ignore();
		cout << "Enter a date in the format (YYYY/MM/DD): ";
		getline(cin, d);

		istringstream ss(d);
		string token;
		vector<int> components;

		while (getline(ss, token, '/')) {
			int value = stoi(token); // Convert each section to integer
			components.push_back(value);
		}

		if (components.size() != 3) {
			cout << "Invalid date format! Please enter a date in the format (YYYY/MM/DD)." << endl;
			continue;
		}

		year = components[0];
		month = components[1];
		day = components[2];

		if (month < 1 || month > 12) {
			cout << "Invalid month! Month should be between 1 and 12." << endl;
			continue;
		}

		if (day < 1 || day > 31) {
			cout << "Invalid day! Day should be between 1 and 31." << endl;
			continue;
		}

		break; // Exit loop if date components are valid

	} while ((month < 1 || month > 12) || (day < 1 || day > 31));
	try {
		setdate(d);
	}
	catch (invalid_argument& e) {
		cout << "Error(154)..." << e.what();
	}
}

void Inventory::additem(int c, string n, string t, string d, int a, int p)
{
	//cout << "\tCode\t||" << "\tItem\t||" << "\tType\t||" << "\tExpire Date\t||" << "\tAmount\t||" << "\tCost\t|| " << endl;


				//....... code
	do {
		try {
			setcode(c);
		}
		catch (invalid_argument& e) {
			cout << "Error(117)..." << e.what();
		}
	} while (c <= 0);

	//....... Item
	do {
		cout << "Enter the name of item: ";
		cin.ignore();
		getline(cin, n);
		try {
			setname(n);
		}
		catch (invalid_argument& e) {
			cout << "Error(130)..." << e.what();
		}
	} while (n == "");

	//........Type
	do {
		cout << "Type: ";
		getline(cin, t);
		try {
			settype(t);
		}
		catch (invalid_argument& e) {
			cout << "Error(140)..." << e.what();
		}
	} while (t == "");

	//....Date
	do {
		cout << "Expire Date. " << endl;
		try {
			checkdate(d);
			setdate(d);
		}
		catch (invalid_argument& e) {
			cout << "Error(154)..." << e.what();
		}
	} while (d == "");

	//.....Amount
	do {
		cout << "Amount: ";
		cin >> a;

		try {
			setamount(a);
		}
		catch (invalid_argument& e) {
			cout << "Error(167)..." << e.what();
		}
	} while (a < 0);

	//..... cost
	do {
		cout << "Cost: ";
		cin >> p;

		try {
			setcost(p);
		}
		catch (invalid_argument& e) {
			cout << "Error(180)..." << e.what();
		}
	} while (p <= 0);

}

void Inventory::Edititem(vector<Inventory>& inventory1)
{
	int n = 0, code = 0;
	string name, address, text;
	ifstream Myfilein;
	stringstream inputString(text);
	Inventory obj;

	address = "F:/";
	name = "Inventory.txt";

	Myfilein.open(address + name, ios::in);
	Myfilein.seekg(0, ios::beg);

	if (!Myfilein.is_open()) {
		cerr << "Error opening file.\n";
		return;
	}

	do {
		cout << endl;
		cout << "Enter the code item that you want to Edit: ";
		cin >> code;

		if (code > inventory1.size()) {
			cout << "Wrong code...  try again." << endl;
		}
	} while (code > inventory1.size());

	cout << "Which part of this item do you want to edit!?." << endl;
	cout << "(1 for Name) / (2 for Type) / (3 for Date) / (4 for Amount) / (5 for Cost): ";
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, text);
		inventory1[code - 1].setname(text);
		break;

	case 2:
		cout << "Enter new type: ";
		cin.ignore();
		getline(cin, text);
		inventory1[code - 1].settype(text);
		break;

	case 3:
		checkdate(text);
		inventory1[code - 1].setdate(text);
		break;

	case 4:
		cout << "Enter new Amount: ";
		cin.ignore();
		getline(cin, text);
		inventory1[code - 1].setamount(stoi(text));
		break;

	case 5:
		cout << "Enter new Cost: ";
		cin.ignore();
		getline(cin, text);
		inventory1[code - 1].setcost(stoi(text));
		break;
	}
	cout << "The file was edited" << endl;
	Myfilein.close();

}

void Inventory::Deleteitem(vector<Inventory>& inventory1)
{
	int n = 0, code = 0;
	string name, address, text;
	ifstream Myfilein;
	stringstream inputString(text);
	Inventory obj;

	address = "F:/";
	name = "Inventory.txt";

	Myfilein.open(address + name, ios::in);
	Myfilein.seekg(0, ios::beg);

	if (!Myfilein.is_open()) {
		cerr << "Error opening file.\n";
		return;
	}

	do {
		cout << endl;
		cout << "Enter the code item that you want to Deleted: ";
		cin >> code;

		if (code > inventory1.size()) {
			cout << "Wrong code...  try again." << endl;
		}
	} while (code > inventory1.size());

	inventory1.erase(inventory1.begin() + (code - 1));

	int counter = 1;
	for (int i = 0; i < inventory1.size(); i++) {
		inventory1[i].setcode(counter);
		counter++;
	}

	cout << "The file was Deleted" << endl;
	Myfilein.close();
}

void Inventory::file(vector<Inventory>& inventory1)
{
	string name, address, text;
	fstream Myfile;
	do {
		address = "F:/";
		name = "Inventory.txt";

		Myfile.open(address + name, ios::out);

		if (!Myfile) {
			system("cls");
			cout << "The file could not be opened.......try again" << endl;
		}
	} while (!Myfile);

	Myfile << "Code\t||" << "Item\t||" << "Type\t||" << "Expire Date\t||" << "Amount\t||" << "Cost" << endl;	
	for (int i = 0; i < inventory1.size(); i++)
	{
		Myfile << inventory1[i].getcode() << "\t";
		Myfile << inventory1[i].getname() << "\t";
		Myfile << inventory1[i].gettype() << "\t";
		Myfile << inventory1[i].getdate() << "\t";
		Myfile << inventory1[i].getamount() << "\t";
		Myfile << inventory1[i].getcost() << "\n";
	}
	Myfile.close();
}

void Inventory::read(vector<Inventory>& inventory1)
{
	inventory1.clear();
	string name, address, text;
	ifstream Myfilein;
	Inventory obj;
	string a, a1;
	address = "F:/";
	name = "Inventory.txt";

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
			getline(inputString, text, '\t');
			if (text == "Total cost:") {
				break;
			}
			obj.setcode(stoi(text));
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}
		catch (const std::out_of_range& e) {
			cerr << "Out of range: " << e.what() << endl;
		}

		try {
			getline(inputString, name, '\t');
			obj.setname(name);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		try {
			getline(inputString, text, '\t');
			obj.settype(text);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		try {
			getline(inputString, text, '\t');
			obj.setdate(text);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		try {
			getline(inputString, text, '\t');
			obj.setamount(stoi(text));
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		try {
			getline(inputString, text, '\n');
			obj.setcost(stoi(text));
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid argument: " << e.what() << endl;
		}

		text = "";
		inventory1.push_back(obj);
	}


	Myfilein.close();
}

void Inventory::update(vector<Inventory>& inventory1)
{
	int i = 0, t = 0;
	Inventory inventory;

	//........... Calculate the Total cost of Inventory.
	for (int i = 0; i < inventory1.size(); i++) {
		t += inventory1[i].getcost() * inventory1[i].getamount();
	}

	inventory.settotalcost(t);
	inventory1.push_back(inventory);
}

void Inventory::printInventory(vector<Inventory>& inventory) {
	int i = 0;
	cout << "\t\t|-| ..........Inventory Items .......... |-|\n\n";
	cout << "Code\t||" << "\tItem\t||" << "\tType\t||" << "\tExpire Date\t||" << "\tAmount\t||" << "\tprice\t" << endl;
	for (i = 0; i < inventory.size(); i++) {

		cout << inventory[i].getcode() << "\t||";
		cout << "\t" << inventory[i].getname() << "\t||";
		cout << "\t" << inventory[i].gettype() << "\t||";
		cout << "\t" << inventory[i].getdate() << "\t||";
		cout << "\t" << inventory[i].getamount() << "\t||";
		cout << "\t" << inventory[i].getcost() << "\n";

	}
}

Inventory::~Inventory()
{
	//cout << "This is a Inventory Destructor.." << endl;
}