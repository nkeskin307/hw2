//This is the Derived Clothing Class from Product Base Class
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "clothing.h" //Since the clothing.h file includes the product.h file, the base class will already be included 
#include "util.h" //To use the parseStringToWords

//Calling the derived constructor
Clothing::Clothing(const std::string category__, const std::string& name__, double price__, int qty__, const std::string& size__, const std::string& brand__)
		:Product(category__, name__, price__,qty__) //inherits these from base class
{
	//Sets the corressponding clothing specific values
	size_=size__;
	brand_=brand__;
}


//Overriding the functions from the Product base class
std::set<std::string> Clothing:: keywords() const{

	//Creating a set to return the keywords for the specific Clothing product
	//I used set container to avoid duplicates in the keywords 
	std::set<std::string> clothing_keywords;


	
	//For name_ and brand_, we have to call the parseStringToWord() function
	//I will do a range insert(first,last):
	//I will use begin() and end() which are functions of the <set> library
	std::set<std::string> Name= parseStringToWords(name_);
	clothing_keywords.insert(Name.begin(), Name.end());

	std::set<std::string> Brand= parseStringToWords(brand_);
	clothing_keywords.insert(Brand.begin(), Brand.end());

	return clothing_keywords;
}

std::string Clothing:: displayString() const {

	//we will use the stringstream library to display our products in wanted format
	std::ostringstream os;
	os<<name_<<std::endl;
	os<<"Size: "<<size_<<" Brand: "<<brand_<<std::endl;
	os<<std::fixed<<std::setprecision(2)<<price_<<" "<<qty_<<" left."<<std::endl; //setprecision arranges the number of decimals

	//The guide wants us to return the statement so I used the ostringstream library
	return os.str();

}


void Clothing::dump(std::ostream& os) const {

		//This code will output the database representation, which I looked from the guide
		os<<category_<<std::endl<<name_<<std::endl;
		os<<std::fixed<<std::setprecision(2)<<price_<<std::endl; //setprecision arranges the number of decimals
		os<<qty_<<std::endl<<size_<<std::endl<<brand_<<std::endl;
}

		






