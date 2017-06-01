//This program demonstrates a dynamic class stack template implemented with an InventoryBin class.
#include <iostream>
#include <string>
#include "DynamicStack.h"
#include "InventoryBin.h"
using namespace std;

//Function prototypes
int menu();												//Display the menu of choices for the user
void pushItem(DynamicStack<InventoryBin>* stack);		//Push an item onto the stack
void popItem(DynamicStack<InventoryBin>* stack);		//Pop an item off the stack

int main()
{
	char again;			//Do-while loop to repeat program
	int selection;		//For the user's choice

	DynamicStack<InventoryBin> testStack;

	do
	{
		selection = menu();

		switch (selection)
		{
		case 1:
			pushItem(&testStack);
			break;
		case 2:
			popItem(&testStack);
			break;
		case 3:
			testStack.displayStack();
			break;
		case 4:
			return 0;		//DynamicStack destructor is called here, and user sees each item that is deleted
		}

	} while (selection != 4);
}

//###########################################################################	
//Display the program menu for the user.									#
//###########################################################################
int menu()
{
	int choice;		//To hold the user's menu selection

	cout << "Main Menu:" << endl;
	cout << "\t1. Push an item onto the InventoryBin stack" << endl;
	cout << "\t2. Pop an item off the InventoryBin stack" << endl;
	cout << "\t3. Display the items currently on the stack" << endl;
	cout << "\t4. Delete all items from the stack and quit" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 4)
	{
		cout << "You must enter a valid menu option.  Please try again." << endl;
		cout << "Enter your choice: ";
		cin >> choice;
	}

	return choice;
}

//###########################################################################	
//Push an item onto the stack.												#
//###########################################################################
void pushItem(DynamicStack<InventoryBin>* stack)
{
	InventoryBin temp;		//Temp InventoryBin item to hold the user's inputs
	int sn;					//Holder for serial number input
	string md;				//Holder for manufacture date input
	int ln;					//Holder for lot number input

	cout << endl << "Enter the following information for the item you would like to push onto the stack:" << endl;
	cout << "Serial Number: ";
	cin >> sn;
	temp.setSerial(sn);
	cout << "Manufacture Date: ";
	cin >> md;
	temp.setManDate(md);
	cout << "Lot Number: ";
	cin >> ln;
	temp.setLot(ln);

	cout << endl;
	cout << "Now pushing your item onto the stack..." << endl;

	//The temp InventoryBin object now contains the information the user entered.
	//Push it onto the stack using the DynamicStack member function.
	stack->push(temp);

	cout << "Done." << endl << endl;
}

//###########################################################################	
//Pop an item off the stack and display it.									#
//###########################################################################
void popItem(DynamicStack<InventoryBin>* stack)
{
	bool success;			//Flag to determine whether the pop operation was successful or not
	InventoryBin temp;		//Temporary holder for the item popped off the stack

	cout << endl << "Now popping an item off the stack..." << endl;
	success = stack->pop(temp);		//Pop an item off the stack and store it in temp

	//If the stack was empty, return an error message.
	if (!success)
	{
		cout << "The pop operation you requested was unsuccessful." << endl << endl;
	}

	//Otherwise, display the item that was popped.
	else
	{
		cout << "Pop operation successful." << endl;
		cout << "The following item was popped off the stack:" << endl;
		cout << temp << endl;
	}
}