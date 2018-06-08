#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>

using std::string;

class Person {
public:
	Person(const string name,int age); // constructor
	 int GetAge() const;
	 string GetName() const;
	 void Print() const;
protected:
	int age_ ;
	string name_ ;
};
#endif