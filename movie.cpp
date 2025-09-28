//This is the Derived Movie Class from Product Base Class
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "movie.h" //Since the movie.h file includes the product.h file, the base class will already be included 
#include "util.h" //To use the parseStringToWords

//Calling the derived constructor
Movie::Movie(const std::string category__, const std::string& name__, double price__, int qty__, const std::string& genre__, const std::string& rating__)
		:Product(category__, name__, price__,qty__) //inherits these from base class
{
	//Sets the corressponding movie specific values
	genre_=genre__;
	rating_=rating__;
}


//Overriding the functions from the Product base class
std::set<std::string> Movie:: keywords() const{

	//Creating a set to return the keywords for the specific Movie product
	//I used set container to avoid duplicates in the keywords
	std::set<std::string> movie_keywords;


	//According to specifications in our guide, the genre of the movie is a searchable keyword, so we can insert it into the set
	std:: string genrE= convToLower(genre_);
	movie_keywords.insert(genrE); 

	//For name_ , we have to call the parseStringToWord() function
	//I will do a range insert(first,last):
	//I will use begin() and end() which are functions of the <set> library
	std::set<std::string> Name= parseStringToWords(name_);
	movie_keywords.insert(Name.begin(), Name.end());

	return movie_keywords;
}

std::string Movie:: displayString() const {

	//we will use the stringstream library to display our products in wanted format
	std::ostringstream os;
	os<<name_<<std::endl;
	os<<"Genre: "<<genre_<<" Rating: "<<rating_<<std::endl;
	os<<std::fixed<<std::setprecision(2)<<price_<<" "<<qty_<<" left."<<std::endl; //setprecision arranges the number of decimals

	//The guide wants us to return the statement so I used the ostringstream library
	return os.str();

}


void Movie::dump(std::ostream& os) const {

		//This code will output the database representation, which I looked from the guide
		os<<category_<<std::endl<<name_<<std::endl;
		os<<std::fixed<<std::setprecision(2)<<price_<<std::endl; //setprecision arranges the number of decimals
		os<<qty_<<std::endl<<genre_<<std::endl<<rating_<<std::endl;
}

		






