/*****************************************************************************************
*  Program Name: ProgrammingAssignment2
*  Created Date: 3/5/19
*  Created By: Shawn Ruby
*  Purpose: Creates a shopping list for the cash register
*  Acknowledgements: None
*****************************************************************************************/

#include <iostream>
#include <fstream>
#include "Receipt.h"

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::exception;
int main()
{
	try
	{
		ifstream inFile; //Get an input file of data to process
		inFile.open("Invent.txt"); //Get file ready to read input

		ofstream outFile; //Get an output file to write data out to
		outFile.open("Receipts.txt"); //Get file ready to write data to

		Receipt myReceipt;
		myReceipt.ProcessItems(inFile); //Read and process all names and ages
		myReceipt.PrintItems(outFile); //Print out all the names and ages to the output file
		myReceipt.UserInput(outFile);

		inFile.close(); //Need to close our input and output files
		outFile.close();
	}
	catch (exception& ex) //Catch any errors that occure and display them in the console to the user
	{
		cerr << "An error occured: " << ex.what() << endl;
		system("pause");
		return 1;
	}

	system("pause");
	return 0;
}