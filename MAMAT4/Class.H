#ifndef _CLASS_H_
#define _CLASS_H_

#include <string>
#include <iostream>
#include <vector>
#include "defs.H"
#include "Room.H"
#include "Child.H"
#include "Teacher.H"

using std::string;
using std::vector;

class Class : public Room {
public:
	
	Class(int const room_num, int size, double max_ratio, int ages, int max_cappacitence, bool occupied = false);
	int Get_Num_Teachers() const;
	int Get_Ages() const;
	double Get_Ratio() const;
	string Get_Child_Phone(string const child_name) const;

	void Add_Teacher(string const name, int age, int seniority);
	Result Add_Child(const string name, int age, string phone);
	Result Remove_Teacher(string const name);
	Result Remove_Child(string const name);
	Result Set_Sick_Child(string const name);
	void Print() const;

	int Find_Teacher_Pos(string const name); //cant implement static
	int Find_Child_Pos(string const name);

private:
	double max_ratio_;
	int  max_capacitence_;
	int ages_;
	vector <Child> children_;
	vector <Teacher> teachers_;
};

#endif