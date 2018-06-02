#ifndef _CHILD_H_
#define _CHILD_H_
#include "Person.H"
#include "defs.H"
#include <string>
#include <iostream>

using std::string;
using std::boolalpha;

class Child : public Person {
public:
	Child(const string name, int age, string phone, bool sick = false);
	string GetPhone() const;
	void Print() const;

	void SetPhone(string phone);
	Result SetSick();
	
private:
	string phone_;
	bool sick_;
};

#endif
