#include <iostream>
#include "GrocerFunctions.h"
#include <map>
using namespace std;


int main() {
	Grocer Corner;
	Corner.displayMenu();
	int menu = 0;

	try {
		Corner.importList();
	}
	catch (std::runtime_error) {
		cout << endl << "Error reading or writing to file." << endl;
		return 0;
	}



	while (menu != 4) {
		cin >> menu;
		switch (menu) {
		case 1:
			Corner.displayItemFrequency();
			break;
		case 2:
			Corner.displayAllItems();
			break;
		case 3:
			Corner.displayHistograms();
			break;
		case 4:
			return 0;
		default:
			Corner.clearScreen();
			cout << endl << "Invalid input. Please enter a numerical value between 1 and 4." << endl << endl;
			Corner.displayMenu();
			cin.clear();
			cin.ignore();
			break;
		}
	}

}