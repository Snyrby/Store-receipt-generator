#ifndef RECEIPT_H
#define RECEIPT_H

#include "sorted.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

/*****************************************************************************************
*  Class Name:  Receipt
*  Parameters:  none
*  Return Value: none
*  Purpose: process data from textfile. Stores data. Allows user to search through data
*****************************************************************************************/

class Receipt
{
private:
	SortedType ReceiptList; //Sorted list to store ages and names list
	SortedType UserProductNumber;
public:
	void ProcessItems(ifstream&);
	void PrintItems(ofstream&);
	void UserInput(ofstream&);
};

#endif