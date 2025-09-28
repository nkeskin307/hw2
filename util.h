#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

	//We will define a set to return the intersection of the two input sets
	std::set<T> intersection;

	//If one of the sets are empty, I will make the function return the empty set
	if (s1.empty() || s2.empty()){
		return intersection;
	}

	std::set<T> greaterSet=s2;
	std::set<T> smallerSet=s1;

	//We need to figure out which set is greater than the other:
	if (s1.size()>s2.size()){
		greaterSet=s1;
		smallerSet=s2;

	}

	for(typename std::set<T>::const_iterator it=smallerSet.begin(); it!=smallerSet.end(); it++){
		//if it didn't make it till the end of the list, that means that the match is found, so I will insert it to the intersection
		if(greaterSet.end()!=greaterSet.find(*it)){
			intersection.insert(*it); //since it iterator is a pointer, we insert the value at that location *it 
		}
		//This is in O(nlog(n))
	}

	//returning the intersection of the two sets
	return intersection;

}


template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	//We begin with creating a new set and copying all elements of one of the sets into it
	std::set<T> unionS;

	//if both sets are empty, I will return the empty set
	if (s1.empty() && s2.empty()){
		return unionS;
	}

	unionS =s2;
	//Using the .insert() function from set library, we insert the second list as well. 
	unionS.insert(s1.begin(), s1.end());

	//returning the union of the two sets
	return unionS;
}



/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
