#ifndef ITEMTYPE_H
#define ITEMTYPE_H

// The following declarations and definitions go into file 
// ItemType.h. 

#include <fstream>
#include <string>
using std::string;

const int MAX_ITEMS = 50;
const int NUMBER_WIDTH = 5;
const int DESCRIPTION_WIDTH = 15;
enum RelationType  {LESS, GREATER, EQUAL};

/*****************************************************************************************
*  Class Name:  ItemType
*  Parameters:  none
*  Return Value: none
*  Purpose: header file that prints all data and gets all variables for data
*****************************************************************************************/

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int, string, double, string);
  void Initialize2(int);
  void PrintUser(std::ostream&) const;
  void PrintTaxandTotal(std::ostream& out, double Total, double TaxTotal, double Subtotal) const;
  double ReturnTax();
  double ReturnPrice();
  double ReturnItems();
private:
  int value;
  string Description;
  double price;
  string tax;
  double Total;
  double items;
};
 
#endif