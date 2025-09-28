#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "util.h"
#include "datastore.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"

/**
 * MyDataStore Interface needed for parsing and instantiating products and users
 *
 */


class MyDataStore: public DataStore {
public:
    MyDataStore() { }
    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p) override;

    /**
     * Adds a user to the data store
     */
    void addUser(User* u) override;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile) override;
		bool usernameMatch(const std::string& username); //to access the username to user map in the amazon.cpp, checking the validity of the username entered 
		void addCart(const std::string& username, Product* item);
		void viewCart(const std::string& username); 
		void buyCart(const std::string& username); 


private:

		//I will make the username a map, each username will be unique and will map to it's user
		std::map<std::string, User*> mapUsernameToUser;

		//Products will be stored in a vector
		std::vector<Product*> Products;
		std::vector<User*> Users;



		//I created a map that maps each keyword to the set of products that include that keyword
		//I used set for type to store products to avoid duplicates
		//This way, when a user searches a keyword, all products that match that keyword will be found instantly
		//This will reduce the time required for lookup, making it instantaneous
		std::map<std::string , std::set<Product*>> mapKeywordsToProducts;

		//This is my map for a user's cart
		std::map<std::string , std::vector<Product*>> cartMap;




};

#endif
