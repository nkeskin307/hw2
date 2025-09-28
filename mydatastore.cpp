#include <set>
#include <vector>
#include <map>
#include <string> 
#include <iostream>
#include "util.h"
#include "mydatastore.h"
#include "datastore.h"

using namespace std;

MyDataStore::~MyDataStore() {//Destructor

	 for (size_t i=0; i< Products.size(); i++){
		delete Products[i];
	 }

	for (size_t i=0; i< Users.size(); i++){
		delete Users[i];
	 }


	
}
    /**
     * Adds a product to the data store
     */
void MyDataStore:: addProduct(Product* p){

					//I am adding the specific product to the vector of products
					Products.push_back(p);

					//I am accessing/generating the set of keywords for the certain product					
					std::set<std::string> productKeywords= p->keywords();

					//I am creating a map, keys are each keyword, they map to the set of products that contain them
					for(std::set<std::string>::const_iterator it=productKeywords.begin(); it!=productKeywords.end(); it++){
						//Iterating through the keywords of one product
						//Setting the keyword as a key, inserting the product to the set of products that contain that keyword
						mapKeywordsToProducts[*it].insert(p);
					}
}



    /**
     * Adds a user to the data store
     */
void MyDataStore::addUser(User* u){
			Users.push_back(u);
			// The username is the key and it maps to the user
			//I used a map for Users to perform fast lookups
			mapUsernameToUser[u->getName()]=(u);
}



    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
std::vector<Product*> MyDataStore:: search(std::vector<std::string>& terms, int type) {

	std::vector<Product*> finalVMatch;
	std::set<Product*> match;//I am creating an empty set of products to compare
	bool firstRound=true; //first iteration

	//I will first check for the case that the search is empty, no terms entered
	if (terms.empty()){ return finalVMatch;}


	//Search through the entered terms
	for(std::vector<std::string>::const_iterator it=terms.begin(); it!=terms.end(); it++){

		//If search is AND and even if one of the terms entered is not found in the keyword map, returns empty 
		if ((type==0)&&(mapKeywordsToProducts.find(*it)==mapKeywordsToProducts.end())){
			return finalVMatch;
		}

		else{ 
			if(mapKeywordsToProducts.find(*it)!=mapKeywordsToProducts.end()){ //If a match is found

				if (firstRound){ //Checking whether this is the first match 
						match=mapKeywordsToProducts.find(*it)->second; 
						firstRound=false;
				}else{
					if(type==0){
						match=setIntersection(mapKeywordsToProducts.find(*it)->second, match); //Compare with second match
					}
					else{
						match=setUnion(mapKeywordsToProducts.find(*it)->second, match);
					}
				}
				
			}
		}

	}
	finalVMatch.assign(match.begin(),match.end());
	//The return type is a vector however I have a set, therefore I will convert it to a vector
	return finalVMatch;

}

//Implementation of ADD method
//Create a cart, a map: Key:username->products
//I am going to store the products in a list so that I can do FIFO and have duplicates

void MyDataStore:: addCart(const std::string& username, Product* item){

	Product *productToAdd=item;
	//Pushes back into the username's list of products
	if (mapUsernameToUser.find(username)!=mapUsernameToUser.end()){
			cartMap[username].push_back(productToAdd);	
	}
	else{
		std::cout<<"Invalid request"<<std::endl;
	}


}

//Implementation of VIEWCART method
void MyDataStore:: viewCart(const std::string& username){

	//Finding the products of the specific username:
	std::vector<Product*> productsInCart= cartMap.find(username)->second;

	for(size_t i=0; i<productsInCart.size(); i++){ 
		Product* p = productsInCart[i];
				std::cout<<"Item " << (i+1) <<std::endl << p->displayString()<<std::endl;
			}
}

//Implementation of BUYCART method

void MyDataStore:: buyCart(const std::string& username){
	
	//I am getting the value of the User from the map:
	User* curUser= mapUsernameToUser[username];
	std::vector<Product*> finalCart;


	//Finding the products of the specific username:
	std::vector<Product*>& productsInCart= cartMap[username];
	if (!productsInCart.empty()){ //Check if cart has elements
		for(std::vector<Product*>::iterator it=productsInCart.begin(); it!=productsInCart.end(); it++){

			//Checking whether the item is in stock and if the current credit of user is enough
			if ((((*it)->getQty())>=1)&& ((curUser->getBalance())>=((*it)->getPrice()))){ 
				(*it)->subtractQty(1); //subtracting the stock amount
				curUser->deductAmount((*it)->getPrice()); //subtracting from the user's balance
			}
			else{
					finalCart.push_back(*it); //Creating a vector to store the products that the user bought
					
			}
		} 
	}
	productsInCart=finalCart; //I am returning the bought items

}



    /**
     * Reproduce the database file from the current Products and User values
     */
void MyDataStore::dump(std::ostream& ofile){


	//Wanted section seperators for database format
	ofile<<"<products>"<<std::endl;
	
	for (std::vector<Product*>::const_iterator it=Products.begin(); it!= Products.end(); it++){

		//I have previousky implemented a dump function inside each of the derived book, clothing and movie classes
		//Here, Iam calling the dump function for each of the specific product
		(*it)->dump(ofile);
		//This will output all of the products in the wanted database format
	}
	ofile<<"</products>"<<std::endl<<"<users>"<<std::endl;

	for (std::vector<User*>::const_iterator it=Users.begin(); it!= Users.end(); it++){

		//I will call the given dump function in the User Class
		(*it)->dump(ofile);
		//This will output all of the users in the wanted database format

	}

	ofile<<"</users>"<<std::endl;

}

//Check if username is valid
bool MyDataStore::usernameMatch(const std::string& username){
	if (mapUsernameToUser.find(username)!=mapUsernameToUser.end()){
		return true;
	}
	return false;
} 