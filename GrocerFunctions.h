#ifndef _GROCER_
#define _GROCER_
#include <map>
#include <string>
class Grocer
{
public:
	void displayMenu();
	void importList();
	void displayItemFrequency();
	std::map<std::string, int> groceryItems;
	void clearScreen();
	void displayAllItems();
	void displayHistograms();

private:
	std::string currentItem;
	std::string specificItem;






};
#endif // _GROCER_