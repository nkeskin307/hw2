//This is a test file for my setUnion setIntersection functions
#include <iostream>
#include <set>
#include <string>
#include "util.h"
using namespace std;


//Printer function to test
template <typename T>
void printer(const std::set<T>& st){
	cout<<"{ ";
	for (typename std::set<T>::const_iterator it=st.begin(); it!=st.end(); it++){
		cout<<*it<<", ";
	}
	cout<<"}"<<std::endl;
}

int main()
{

	std::set<int> st;

	cout<<"setUnion for the sets: {1,4,5,2} and {2,5,7,4}: "<<std::endl;
	std::set<int> s1={1,4,5,2};
	std::set<int> s2={2,5,7,4};
	st=setUnion(s1,s2);
	printer(st);
	cout<<"setIntersection: "<<std::endl;
	st=setIntersection(s1,s2);
	printer(st);

	cout<<"setUnion for the sets: {0} and {2,5,7,4}: "<<std::endl;
	s1={0};
	s2={2,5,7,4};
	st=setUnion(s1,s2);
	printer(st);
	cout<<"setIntersection: "<<std::endl;
	st=setIntersection(s1,s2);
	printer(st);

	cout<<"setUnion for the sets: {0} and {0}: "<<std::endl;
	s1={0};
	s2={0};
	st=setUnion(s1,s2);
	printer(st);
	cout<<"setIntersection: "<<std::endl;	
	st=setIntersection(s1,s2);
	printer(st);


	cout<<"setUnion for the sets: {} and {}: "<<std::endl;
	s1={};
	s2={};
	st=setUnion(s1,s2);
	printer(st);
	cout<<"setIntersection: "<<std::endl;	
	st=setIntersection(s1,s2);
	printer(st);

	cout<<"setUnion for the sets: {1,2} and {}: "<<std::endl;
	s1={1,2};
	s2={};
	st=setUnion(s1,s2);
	printer(st);
	cout<<"setIntersection: "<<std::endl;	
	st=setIntersection(s1,s2);
	printer(st);

	cout<<"setUnion for the sets: {1,2} and {}: "<<std::endl;
	s2={1,2};
	s1={};
	st=setUnion(s1,s2);
	printer(st);
	cout<<"setIntersection: "<<std::endl;	
	st=setIntersection(s1,s2);
	printer(st);



	return 0;


}