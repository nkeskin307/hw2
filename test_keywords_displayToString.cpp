//This is a test file for my parseStringToWords function
#include <iostream>
#include <set>
#include <string>
#include "book.h" 
#include "clothing.h" 
#include "movie.h" 
#include "util.h"
using namespace std;


int main()
{

	//Creating a book
	Book myBook("book", "Harry Potter 2", 15.32, 5, "102012390129320931209321093", "JK. Rowling");

	std::set<string> words=myBook.keywords();

	//Printer function to test
	cout<<"Keywords for book item: ";
	cout<<"{ ";
	for (std::set<string>::const_iterator it=words.begin(); it!=words.end(); it++){
		cout<<*it<<", ";
	}
	cout<<"}"<<std::endl;

	cout<<std::endl;
	cout<<"Now displaying the book"<<std::endl;
	cout<<std::endl;
	cout<<myBook.displayString()<<std::endl;



	//Creating a clothing
	Clothing myClothing("clothing", "dress", 15.30, 5, "mEdiym", "h&m");

	std::set<string> words_=myClothing.keywords();

	//Printer function to test
	cout<<"Keywords for clothing item: ";
	cout<<"{ ";
	for (std::set<string>::const_iterator it2=words_.begin(); it2!=words_.end(); it2++){
		cout<<*it2<<", ";
	}
	cout<<"}"<<std::endl;

	cout<<std::endl;
	cout<<"Now displaying the clothing"<<std::endl;
	cout<<std::endl;
	cout<<myClothing.displayString()<<std::endl;


	//Creating a clothing
	Movie myMovie("movie", "How to Loose a guy in 10 days!!!", 14.302, 5, "comedy", "1");

	std::set<string> words__=myMovie.keywords();

	//Printer function to test
	cout<<"Keywords for movie item: ";
	cout<<"{ ";
	for (std::set<string>::const_iterator it3=words__.begin(); it3!=words__.end(); it3++){
		cout<<*it3<<", ";
	}
	cout<<"}"<<std::endl;


	cout<<std::endl;
	cout<<"Now displaying the movie"<<std::endl;
	cout<<std::endl;
	cout<<myMovie.displayString()<<std::endl;


	//Creating a book
	Book myBook2("book", "I'll Men's J. normalizing new Norms_0kkk", 15.32, 5, "978-000000000-1", "Anna f lorely K.");

	std::set<string> words1=myBook2.keywords();

	//Printer function to test
	cout<<"Keywords for book item: ";
	cout<<"{ ";
	for (std::set<string>::const_iterator it=words1.begin(); it!=words1.end(); it++){
		cout<<*it<<", ";
	}
	cout<<"}"<<std::endl;

	cout<<std::endl;
	cout<<"Now displaying the book"<<std::endl;
	cout<<std::endl;
	cout<<myBook2.displayString()<<std::endl;



	return 0;

}