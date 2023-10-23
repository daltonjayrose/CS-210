#include <iostream>
#include "GrocerFunctions.h"
#include <map>
#include <fstream>
#include <string>
using namespace std;

// Displays the menu for the Corner Grocer Program.
void Grocer::displayMenu() {
	cout << "Corner Grocer Menu" << endl;
	cout << "----------------------------------------" << endl;
	cout << "1. Display frequency for a specific item." << endl;
	cout << "2. Display a list of all items and their frequencies." << endl;
	cout << "3. Display histogram of all items and their frequencies." << endl;
	cout << "4. Exit Program." << endl;
	cout << "Please select an option from the menu by entering a number between 1 and 4." << endl;
}

// Imports a list of items and creates a map with the provided data. Stores the frequency of each item in a created file (frequency.dat) as a backup.
void Grocer::importList() {
	ifstream groceryFS;
	groceryFS.open("GroceryList.txt");

	if (!groceryFS.is_open()) {
		throw std::runtime_error("Unable to read from file.");
	}

	// Iterates through the input file, calculating the frequency of each item and storing that value in a map. 
	while (!groceryFS.fail()) {
		groceryFS >> currentItem;

		if (groceryItems.count(currentItem) == 0) {
			groceryItems.emplace(currentItem, 1);
			groceryFS.ignore();
		}

		else if (groceryItems.count(currentItem) == 1) {
			++groceryItems[currentItem];
			groceryFS.ignore();
		}
	}
	groceryFS.close();
	
	// Creates a backup of the calculated frequencies by iterating through the map and storing each item name and frequency in the created file frequency.dat.
	ofstream backupFS;
	backupFS.open("frequency.dat");

	if (!backupFS.is_open()) {
		throw std::runtime_error("Unable to write to file.");
	}

	for (std::map<string, int>::iterator i = groceryItems.begin(); i != groceryItems.end(); i++) {
		backupFS << i->first << " " << i->second << endl;
	}
}

// Prints 40 blank lines to clear the screen
void Grocer::clearScreen() {
	for (int i = 0; i < 40; ++i)
		cout << endl;
}

// Prompts user to item name then outputs that item frequency.
void Grocer::displayItemFrequency() {
	cout << "Please enter the name of the item you'd like to search for: " << endl;
	cin >> specificItem;
	clearScreen();
	if (groceryItems.count(specificItem) == 1) {
		cout << "Item Name: " << specificItem << endl << "Frequency: " << groceryItems.at(specificItem) << endl << endl;
		displayMenu();
	}
	else if (groceryItems.count(specificItem) == 0) {
		cout << "Item not found." << endl << endl;
		displayMenu();
	}

}

// Iterates through the map and outputs all items and their frequencies.
void Grocer::displayAllItems() {
	clearScreen();
	for (std::map<string, int>::iterator i = groceryItems.begin(); i != groceryItems.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}
	cout << endl;
	displayMenu();
}

// Iterates through the map and displays the items and their frequencies via histogram.
void Grocer::displayHistograms() {
	clearScreen();
	for (std::map<string, int>::iterator i = groceryItems.begin(); i != groceryItems.end(); i++) {
		cout << i->first << " ";
		for (int j = 0; j < i->second; j++) {
			cout << "*";
		}
		cout << endl;
		}
	cout << endl;
	displayMenu();
}