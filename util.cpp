#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <set>
#include <string>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
	//This is my set of keywords to return at the end
	std::set<std::string> key_words;

	//This will trim both sides of the given string to get rid of extra whitespace
	std::string trimmed_string= trim(rawWords);

	//This for loop checks for punctuation, if true, replaces with space
	for (size_t i=0; i<trimmed_string.size(); i++){
			if (ispunct(trimmed_string[i])){
				trimmed_string[i]=' ';
			}
	}

	//This will convert all characters to lowercase, I used the provided function above
	std::string ready_string= convToLower(trimmed_string);


	std::string keyword;
	std::istringstream iterator(ready_string); //this will iterate a word using >> till whitespace, part of the string library, works just like cin


	while (iterator>>keyword){
		if (2<=keyword.size()){//this checks whether the word is equal to or longer than 2 chars
			key_words.insert(keyword); //if true, it will insert the word into our key_words set 
		}
	}
	return key_words; 
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
