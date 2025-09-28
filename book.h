//The heather file for the Derived Book Product class
#ifndef BOOK_H
#define BOOK_H

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include "product.h"


class Book: public Product{

public: //All functions will be ovverrided since each derived class needs it's own implementation

		//Constructor
		//We don't need a destructor since it will be inherited from the Product Base Class
		Book(const std::string category__, const std::string& name__, double price__, int qty__, const std::string& isbn__, const std::string& author__);

		//Overriding the functions from the Product base class
		std::string displayString() const override;
		
		
		void dump(std::ostream& os) const override;


		std::set<std::string> keywords() const override;

//We do not need to override the isMatch() from the base class product since it will be used by all of the 3 derived classes

private:
	//These data members are private since they won't be used by any other derived classes and only by the Book class
	//These data mambers isbn_ and author_ are book-class specific 
	//Other elements such as category_ name_ price_ and qty_ will be inherited from the product base class  
	std::string isbn_;
	std::string author_;


};

#endif