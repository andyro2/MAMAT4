#ifndef _TEACH_H_
#define _TEACH_H_
#include "Person.H"
#include <string>
#include <iostream>

class Teacher : public Person {
public:
	Teacher(string const name, int age, int seniority);
	int GetSeniority() const;
	void Print() const;
protected:
	int seniority_;
};

#endif
