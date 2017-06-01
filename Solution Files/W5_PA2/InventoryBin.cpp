#include "InventoryBin.h"

//#######################################################################
//Overloaded stream insertion operator, for displaying the values		#
//stored in an instance of InventoryBin.								#
//#######################################################################
ostream &operator << (ostream &strm, const InventoryBin &obj)
{
	cout << "Serial Number: ";
	strm << obj.serialNum << endl;
	cout << "Manufactured Date: ";
	strm << obj.manufactDate << endl;
	cout << "Lot Number: ";
	strm << obj.lotNum << endl;

	return strm;
}