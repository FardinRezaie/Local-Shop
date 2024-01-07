#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Inventory.h"
#include "Customer.h"
#include "Shop.h"
using namespace std;

static int counter = 1;

int n = 0, asset = 0, debt = 0, code = 0, cost = 0, amount = 0;
bool Bool = true;
char ch = 'n';
string name, name1, last_n, address, address1, type, date, text, number, password;


// Inventory    Code	||	Item	||	Type	||	Expire Date	||	Amount	||	Cost	|| 
// Customers    Code	||	Name	||	Last Name	||	Asset	||	Debt	||	Number	||	Address	||

/*
int searchItemCode(string search) {
	Item item;
	ifstream file;
	string filename = "shop.txt";
	string address = "F:/";
	file.open(address + filename, ios::in);
	if (!file) {
		cout << "Error opening file" << endl;
		return -1;
	}
	if (file.read((char*)&item, sizeof(item))) {
		while (!file.eof()) {
			if (item.getItemCode() == search) {
				cout << endl
					<< left << setw(15) << "ITEM CODE"
					<< left << setw(15) << "ITEM NAME"
					<< left << setw(15) << "ITEM PRICE" << endl;
				item.displayItem();
				break;
			}
			file.read((char*)&item, sizeof(item));
		}
	}
	else {
		cout << "Error reading from file" << endl;
		return -1;
	}
	file.close();
	cout << endl;
	return 0;
}
*/

void Menu()
{
	//system("cls");
	cout << "|-|=============== Menu ================|-|" << endl;
	cout << "\t\t.1. Files" << endl; Sleep(100);
	cout << "\t\t.2. Shop" << endl; Sleep(100);
	cout << "\t\t.3. Exit" << endl; Sleep(100);
	cout << "|-|============== Select ===============|-|" << endl;
}

void Menu_1()
{
	cout << "\n\n\t\t.1. New" << endl; Sleep(100);
	cout << "\t\t.2. Open" << endl; Sleep(100);
	cout << "\t\t.3. Edit" << endl; Sleep(100);
	cout << "\t\t.4. Delete" << endl; Sleep(100);
	cout << "\t\t.5. Back" << endl; Sleep(100);

}
/*
void ccolor(int clr) {

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

//the above code displays colorful background. if you want colorful then you can remove the above comment but not the code, only comment//
}
void loadingbar(void) {

	for (int i = 15; i <= 100; i += 5) {

		system("cls");

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t", i);

		printf("");

		for (int j = 0; j < i; j += 2) {

			ccolor(160 + j);
			printf(" ");
			ccolor(26);

		}
		Sleep(100);
		if (i == 90 || i == 50 || i == 96 || i == 83) {
			Sleep(100);
		}

	}

}
*/


int main()
{
	Customer customer;
	vector<Customer> customer1;
	Inventory inventory;
	vector<Inventory> inventory1;
	Shop shop;
	vector<Shop> shop1;
	

	//loadingbar();
	do {
		

		Menu();
		cout << "Please Select: ";
		cin >> n;


		switch (n) {

		case 1:
			cin.ignore();
			cout << "Enter the Password: ";
			getline(cin, password);

			do {
				if (password != "fardin03") {
					system("cls");
					cout << "Incorrect password..." << endl;
					cout << "Enter the Password: ";
					getline(cin, password);
				}
			} while (password != "fardin03");

			do {																								// ........... Files
				Menu_1();
				cout << "Please Select: ";
				cin >> n;

				switch (n)
				{
					//.............................: Case 1 : Creat a file : ...........................\\

				case 1:

					system("cls");
					cout << "|-|.......... New file ..........|-|" << endl << endl;

					cout << ".1. Inventory" << endl;
					cout << ".2. Customers" << endl;
					cout << "Select: ";
					cin >> n;
					//.............................: Switch,case : ...........................\\

					switch (n)
					{

					case 1:
						//.......................: Case 1.1 : Inventory : ...........................\\

						inventory.read(inventory1);
						inventory.printInventory(inventory1);
						counter = inventory1.size();
						counter++;
						cout << "|-|.......... Inventory ..........|-|\n" << endl;
						cout << "Enter the Information of item(0 for exit):" << endl;
						while (ch != '0') {
							inventory.additem(counter, name, type, date, amount, cost);
							counter++;
							inventory1.push_back(inventory);
							cout << "Another item!? (0 for exit): ";
							cin >> ch;
							if (ch == '0')
								break;
						}
						inventory.file(inventory1);
						break;   //.... End of Case 1.1


					case 2:
						//.......................: Case 1.2 : Customers : ...........................\\

						customer.read_c(customer1);
						customer.printCustomer(customer1);
						counter = customer1.size();
						counter++;
						cout << "|-|.......... Customers ..........|-|" << endl;
						cout << "Enter the Information of Customer($3 for exit):" << endl;
						while (ch != '$') {
							customer.addcustomer(counter, name, last_n, asset, debt, address, number);
							counter++;
							customer1.push_back(customer);
							cout << "Another item!? ($ for exit): ";
							cin >> ch;
							if (ch == '$')
								break;
						}
						customer.file_c(customer1);
						break;   //.... End of Case 1.2
					}
					break;											                                   //............. End of Case 1


				case 2:
					system("cls");
					cout << "|-|.......... Open a file ..........|-|" << endl << endl;

					cout << ".1. Inventory" << endl;
					cout << ".2. Customers" << endl;
					cout << "Select: ";
					cin >> n;
					//.............................: Switch,case : ...........................\\

					switch (n)
					{
					case 1:
						//.......................: Case 1.1 : Inventory : ...........................\\

						system("cls");
						cout << "|-|.......... Inventory ..........|-|\n" << endl;

						inventory.read(inventory1);
						inventory.printInventory(inventory1);

						break;   //.... End of Case 1.1
					case 2:
						//.......................: Case 1.2 : Customers : ...........................\\

						system("cls");
						cout << "|-|.......... Customers ..........|-|" << endl;

						customer.read_c(customer1);
						customer.printCustomer(customer1);

						break;   //.... End of Case 1.2
					}

					break;											                                   //............. End of Case 2

					//.............................: Case 2 : Edit a file : ...........................\\

				case 3:
					system("cls");
					cout << "|-|.......... Edit a file ..........|-|" << endl << endl;

					cout << ".1. Inventory" << endl;
					cout << ".2. Customers" << endl;
					cout << "Select: ";
					cin >> n;
					//.............................: Switch,case : ...........................\\

					switch (n)
					{
					case 1:
						//.......................: Case 1.1 : Inventory : ...........................\\

						cout << "|-|.......... Inventory ..........|-|\n" << endl;
						inventory.read(inventory1);
						system("cls");
						inventory.printInventory(inventory1);
						inventory.Edititem(inventory1);
						inventory.file(inventory1);
						break;   //.... End of Case 1.1
					case 2:
						//.......................: Case 1.2 : Customers : ...........................\\

						cout << "|-|.......... Customers ..........|-|" << endl;

						customer.read_c(customer1);
						system("cls");
						customer.printCustomer(customer1);
						customer.Editcustomer(customer1);
						customer.file_c(customer1);

						break;   //.... End of Case 1.2
					}

					break;																				//............. End of Case 3

					//.............................: Case 4 : Delete from file : ...........................\\

				case 4:
					system("cls");
					cout << "|-|.......... Delete from file ..........|-|" << endl << endl;

					cout << "|1|.......... Inventory ..........|1|" << endl;
					cout << "|2|.......... Customers ..........|2|" << endl;
					cout << "Select: ";
					cin >> n;
					//.............................: Switch,case : ...........................\\

					switch (n)
					{
					case 1:
						//.......................: Case 1.1 : Inventory : ...........................\\

						system("cls");
						cout << "|-|.......... Inventory ..........|-|\n" << endl;
						inventory.read(inventory1);
						inventory.printInventory(inventory1);
						inventory.Deleteitem(inventory1);
						inventory.file(inventory1);
						break;   //.... End of Case 1.1
					case 2:
						//.......................: Case 1.2 : Customers : ...........................\\

						system("cls");
						cout << "|-|.......... Customers ..........|-|" << endl;
						customer.read_c(customer1);
						customer.printCustomer(customer1);
						customer.Deletecustomer(customer1);
						customer.file_c(customer1);
						break;   //.... End of Case 1.2
					}

					break;																				//............. End of Case 4

					//.............................: Case 5 : Back to first menu : ...........................\\

				case 5:
					Bool = false;
					break;																				//............. End of Case 5
				}
			} while (Bool == true);
			// ........... Shop
			break;

		case 2:

			do {
				//system("cls");
				cout << "\t\t>> 1. Buy\n";
				cout << "\t\t>> 2. Cost of incoming goods\n";
				cout << "\t\t>> 3. Cost of outcoming goods\n";
				cout << "\t\t>> 4. Back\n";
				cout << "Select: ";
				cin >> n;
				switch (n) {
				
				case 1:
					system("cls");
					inventory.read(inventory1);
					customer.read_c(customer1);
					inventory.printInventory(inventory1);
					shop.Buy(inventory1, customer1);
					shop.update(inventory1);
					customer.file_c(customer1);
					inventory.file(inventory1);
				
					break;

				case 2:
					inventory.read(inventory1);
					inventory.update(inventory1);
					inventory.printInventory(inventory1);
					int i;
					for (i = 0; i < inventory1.size() - 1; i++);
					cout << "Total cost: " << inventory1[i].gettotalcost() << "\n";

					break;

				case 3:
					shop.read(shop1);
					shop.print(shop1);
					cout << endl;
					break;
				
				case 4:
					Bool = false;
					break;
				}
			} while (Bool);

			break;

		case 3:
			system("cls");
			cout << "\n\t\t\t     The programm Closed.." << endl << endl; Sleep(400);
			cout << "\t\tH a  v  e"; Sleep(300); cout << "\ta\t"; Sleep(300);
			cout << " G  o  o  d\t"; Sleep(300); cout << "d  a  y  !\n" << endl; Sleep(300);
			return 0;
			break;
		}

		Bool = true;
	
	} while (Bool);

}
