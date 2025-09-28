//The heather file for the Derived Clothing Product class
#ifndef CLOTHING_H
#define CLOTHING_H

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include "product.h"


class Clothing: public Product{

public: //All functions will be ovverrided since each derived class needs it's own implementation

		//Constructor
		//We don't need a destructor since it will be inherited from the Product Base Class
		Clothing(const std::string category__, const std::string& name__, double price__, int qty__, const std::string& size__, const std::string& brand__);

		//Overriding the functions from the Product base class
		std::string displayString() const override;
		
		
		void dump(std::ostream& os) const override;


		std::set<std::string> keywords() const override;

//We do not need to override the isMatch() from the base class product since it will be used by all of the 3 derived classes

private:
	//These data members are private since they won't be used by any other derived classes and only by the Clothing class
	//These data mambers size_ and brand_ are clothing-class specific 
	//Other elements such as category_ name_ price_ and qty_ will be inherited from the product base class  
	std::string size_;
	std::string brand_;


};

#endif