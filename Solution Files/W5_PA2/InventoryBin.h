#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//Forward class declaration
class InventoryBin;

//Function prototype for overloaded stream insertion operator - see InventoryBin.cpp for implementation
ostream &operator << (ostream &strm, const InventoryBin &obj);

class InventoryBin
{
private:
	int serialNum;
	string manufactDate;
	int lotNum;
public:
	//#######################################################################
	//Default constructor, sets all data members to 0 or empty.				#
	//#######################################################################
	InventoryBin()
	{
		serialNum = 0;
		manufactDate = " ";
		lotNum = 0;
	}

	//#######################################################################
	//Constructor that accepts parameters for the data members.				#
	//#######################################################################
	InventoryBin(int serial, string manf, int lot)
	{
		serialNum = serial;
		manufactDate = manf;
		lotNum = lot;
	}

	//#######################################################################
	//Destructor.															#
	//#######################################################################
	~InventoryBin()
	{

	}

	//#######################################################################
	//Display function to display a single InventoryBin item.				#
	//#######################################################################
	void display()
	{
		cout << "Serial Number: ";
		cout << serialNum << endl;
		cout << "Manufactured Date: ";
		cout << manufactDate << endl;
		cout << "Lot Number: ";
		cout << lotNum << endl;
	}

	//#######################################################################
	//Accessor functions to set each of the InventoryBin attributes.		#
	//#######################################################################

	int getSerial() const
	{
		return serialNum;
	}

	string getManDate() const
	{
		return manufactDate;
	}

	int getLot() const
	{
		return lotNum;
	}

	//#######################################################################
	//Mutator functions to set each of the InventoryBin attributes.			#
	//#######################################################################

	void setSerial(int num)
	{
		serialNum = num;
	}

	void setManDate(string date)
	{
		manufactDate = date;
	}

	void setLot(int num)
	{
		lotNum = num;
	}

	//#######################################################################
	//Overloaded operators													#
	//*Note: overloaded stream insertion operator is in InventoryBin.cpp.	#
	//#######################################################################
	void operator = (const InventoryBin &right)
	{
		serialNum = right.serialNum;
		manufactDate = right.manufactDate;
		lotNum = right.lotNum;
	}

	//#######################################################################
	//Friends																#
	//#######################################################################
	friend ostream &operator << (ostream &, const InventoryBin &);
};

