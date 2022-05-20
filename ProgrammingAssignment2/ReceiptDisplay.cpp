#include "Receipt.h"
#include <iostream>
#include <string>
#include "ItemType.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/*****************************************************************************************
*  function Name: UserInput(ifstream& inFile)
*  Parameters:  inFile
*  Return Value: none
*  Purpose: Stores all items from the txt file to a sorted list
*****************************************************************************************/

void Receipt::ProcessItems(ifstream& inFile)
{
	string CurrentDescription; //Store the current description from a text file
	int CurrentNumber; //Store the current product Number from a text file
	double CurrentPrice;
	string CurrentTax;
	ItemType New; //To store the item information

	while (inFile >> CurrentNumber >> CurrentDescription >> CurrentPrice >> CurrentTax) //Loop through each word in the file
	{
		New.Initialize(CurrentNumber, CurrentDescription, CurrentPrice, CurrentTax);
		if (!ReceiptList.IsFull())
		{
			ReceiptList.PutItem(New);
		}
		else
		{
			cerr << "Error: List is full!\n\n";
		}
	}
}

/*****************************************************************************************
*  function Name:  PrintItems(ofstream& outFile)
*  Parameters:  outFile
*  Return Value: none
*  Purpose: print each item in the sorted list 
*****************************************************************************************/

void Receipt::PrintItems(ofstream& outFile)
{
	ReceiptList.ResetList();
	ItemType item;
	for (int count = 0; count < ReceiptList.GetLength(); count++)
	{
		item = ReceiptList.GetNextItem();
		item.Print(outFile);
	}
}

/*****************************************************************************************
*  function Name: UserInput(ofstream& outFile)
*  Parameters:  outFile
*  Return Value: none
*  Purpose: contains all code for user input and printing user input and formatting the receipt
*****************************************************************************************/

void Receipt::UserInput(ofstream& outFile)
{
	/* variable to repeat for new customers */
	string Repeat = "y";

	/* product number to search the sorted list */
	int ProductNumber;

	/* item type to store the info from the list */
	ItemType Check;

	/* bool to determine if the product number is found */
	bool found;

	/* tax total for the receipt */
	double TaxTotal = 0;

	/* total for the receipt */
	double Total = 0;

	/* subtotal for the receipt */
	double SubTotal = 0;

	/* determines how many items there are of the product number */
	double items = 0;

	/* how many customers there are*/
	int customer = 1;

	/* cout statement for the customer */
	cout << "\n--------------------\nCustomer: " << customer << endl << endl;
	outFile << "\n--------------------\nCustomer: " << customer << endl << endl;

	/* loops through until there is no more customers */
	do
	{
		/* asks the user for which product number they would like to search by */
		cout << "Which product number would you like to use (XXXXX): ";
		cin >> ProductNumber;

		/* if product number is 0 then it switches to a new customer */
		if (ProductNumber == 0)
		{
			/* clears a sorted list filled with user inputs for the new customer */
			UserProductNumber.MakeEmpty();

			/* calculates total */
			Total = TaxTotal + SubTotal;

			/* passes total, tax and subtotal to a print function */
			Check.PrintTaxandTotal(outFile, Total, TaxTotal, SubTotal);

			while (Repeat != "Y" || Repeat != "y" || Repeat != "n" || Repeat != "N")
			{
				/* asks the user if there is any more customers */
				cout << "\nIs there another customer? (y/n): ";
				cin >> Repeat;
				if (Repeat == "Y" || Repeat == "y" || Repeat == "n" || Repeat == "N")
				{
					break;
				}
			}

			/* adds 1 to the customer */
			customer += 1;

			/* if there are more customers */
			if (Repeat == "y" || Repeat == "Y")
			{
				/* resets the total, tax and subtotal back to 0 */
				Total = 0;
				TaxTotal = 0;
				SubTotal = 0;

				/* new line for the new customer */
				cout << "\n--------------------\nCustomer: " << customer << endl << endl;
				outFile << "\n--------------------\nCustomer: " << customer << endl << endl;
			}

		}
		else
		{
			/* if the product number is not 0, it will initialize it and store it under the item type named check */
			Check.Initialize2(ProductNumber);

			/* checks if the product number is in the list named receipt list */
			Check = ReceiptList.GetItem(Check, found);

			if (found)
			{
				/* if the product number was found then it will check if the user has already inputted the product number */
				UserProductNumber.GetItem(Check, found);

				if (!found)
				{
					/* if the user has not inputted the product number then it will get items from the user input */
					items = Check.ReturnItems();

					/* calculates the Tax and Sub total */
					TaxTotal = Check.ReturnPrice() * Check.ReturnTax() * items + TaxTotal;
					SubTotal = Check.ReturnPrice() * items + SubTotal;

					/* puts the product number in a list that stores the user input */
					UserProductNumber.PutItem(Check);

					/* function for printing all of the data based on the product number */
					Check.PrintUser(outFile);
				}
				else
				{
					/* if the product number was found in the product number list then it will say that number is a duplicate */
					cout << "\nThe Product Number, " << ProductNumber << " is a duplicate.\n\n";
					outFile << "The Product Number, " << ProductNumber << " is a duplicate.\n\n";
				}
			}
			else
			{
				/* if the product number was not found in the receipt list then it will say that is an invalid input */
				cout << endl << "******* " << ProductNumber << " not found in the list. *******\n\n";
				outFile << "******* " << ProductNumber << " not found in the list. *******\n\n";
			}
		}
	} while (Repeat == "Y" || Repeat == "y");

	/* if the user selects no more customers, it closes the program */
	cout << "\nThank you for using the program.\n\n";
}
