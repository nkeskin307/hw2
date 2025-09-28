//This is a test file for my parseStringToWords function
#include <iostream>
#include <set>
#include <string>
using namespace std;

std::set<std::string> parseStringToWords(string rawWords);

int main()
{

  std::set<std::string> random=parseStringToWords("Men's cloThing Nehir a I'll 123 2");

	//This will iterate through the fixed set of keywords that was created by my parseStringToWords function


	cout<<"{";
	for (std:: set<std::string>::iterator keyword=random.begin() ; keyword != random.end(); keyword++ ){
		cout<< *keyword<<", ";
	}
	cout<<"}"<<endl;

	 return 0;
}