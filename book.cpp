//This is the Derived Book Class from Product Base Class
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "book.h" //Since the book.h file includes the product.h file, the base class will already be included 
#include "util.h" //To use the parseStringToWords

//Calling the derived constructor
Book::Book(const std::string category__, const std::string& name__, double price__, int qty__, const std::string& isbn__, const std::string& author__)
		:Product(category__, name__, price__,qty__) //inherits these from base class
{
	//Sets the corressponding book specific values
	isbn_=isbn__;
	author_=author__;
}


//Overriding the functions from the Product base class
std::set<std::string> Book:: keywords() const{

	//Creating a set to return the keywords for the specific Book product
	//I used set container to avoid duplicates in the keywords
	std::set<std::string> book_keywords;


	//According to specifications in our guide, the ISBN number is automatically a keyword, so I can insert it into the set
	book_keywords.insert(isbn_); 

	//For name_ and author_, we have to call the parseStringToWord() function
	//I will do a range insert(first,last), using begin() and end() which are functions of the <set> library
	std::set<std::string> Name= parseStringToWords(name_);
	book_keywords.insert(Name.begin(), Name.end());

	std::set<std::string> Author= parseStringToWords(author_);
	book_keywords.insert(Author.begin(), Author.end());

	return book_keywords;
}




std::string Book:: displayString() const {

	//we will use the stringstream library to display our products in wanted format
	std::ostringstream os;
	os<<name_<<std::endl;
	os<<"Author: "<<author_<<" ISBN: "<<isbn_<<std::endl;
	os<<price_<<" "<<qty_<<" left."<<std::endl; //setprecision arranges the number of decimals

	//The guide wants us to return the statement so I used the ostringstream library
	return os.str();

}


void Book::dump(std::ostream& os) const {

		//This code will output the database representation, which I looked from the guide
		os<<category_<<std::endl<<name_<<std::endl;
		os<<std::fixed<<std::setprecision(2)<<price_<<std::endl; //setprecision arranges the number of decimals
		os<<qty_<<std::endl<<isbn_<<std::endl<<author_<<std::endl;
}

		






