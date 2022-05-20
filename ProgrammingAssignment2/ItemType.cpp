// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include <iomanip>
#include "ItemType.h"
#include <stdlib.h>

using std::cout;
using std::endl;
using std::setw;
using std::cin;

ItemType::ItemType()
{ 
  value = 0;
}

/*****************************************************************************************
*  function Name: ComparedTo(ItemType otherItem)
*  Parameters:  otherItem
*  Return Value: LESS, GREATER or EQUAL
*  Purpose: compares 2 values
*****************************************************************************************/

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

/*****************************************************************************************
*  function Name: Initialize(int number, string otherName, double otherPrice, string otherTax)
*  Parameters:  number, otherName, otherPrice, otherTax
*  Return Value: none
*  initialized the data from the text file to be stored
*****************************************************************************************/

void ItemType::Initialize(int number, string otherDescription, double otherPrice, string otherTax) 
{
  value = number;
  Description = otherDescription;
  price = otherPrice;
  tax = otherTax;
}
/* initializes the productnumber to be able to be searched and stored */
void ItemType::Initialize2(int ProductNumber)
{
	value = ProductNumber;
}

void ItemType::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
	cout << std::fixed;
	out << std::fixed;
	out << setw(NUMBER_WIDTH) << value << setw(DESCRIPTION_WIDTH) << Description << " " << " $" << std::setprecision(2) << price << " " << tax << endl;
	cout << setw(NUMBER_WIDTH) << value << setw(DESCRIPTION_WIDTH) << Description << " " << " $" << std::setprecision(2) << price << " " << tax << endl;
}

/* print function that prints all the data associated to the product number the user inputs */
void ItemType::PrintUser(std::ostream& out) const
{
	out << Description << " x" << std::setprecision(0) << items << " @ $" << std::setprecision(2) << price << " ea $" << price * items << " " << tax << "\n\n";
	cout << endl << Description << " x" << std::setprecision(0) << items << " @ $" << std::setprecision(2) << price << " ea $" << price * items << " " << tax << "\n\n";
}

/* print function for the subtotal, taxes and total price */
void ItemType::PrintTaxandTotal(std::ostream& out, double Total, double TaxTotal, double Subtotal) const
{	
	cout << "\nSubtotal: $" << Subtotal << endl;
	out << "Subtotal: $" << Subtotal << endl;
	cout << "Tax: $" << TaxTotal << endl;
	out << "Tax: $" << TaxTotal << endl;
	cout << "Total: $" << Total << endl;
	out << "Total: $" << Total << endl;
}

/* returns tax to calculate total and tax */
double ItemType::ReturnTax()
{
	/* if tax stored in the file type is a t then tax is 7.5%*/
	if (tax == "T")
	{
		return  0.075;
	}
	/* if there is an "N" then tax is 0 */
	else
	{
		return  0;
	}
}
/* returns the price to be calculated */
double ItemType::ReturnPrice()
{
	return price;
}
/* asks the user for how many items there are of the product number between 1 and 100*/
double ItemType::ReturnItems()
{
	do
	{
		cout << "How many items are there? ";
		cin >> items;
	} while (items > 100 || items < 1);


	return items;
}