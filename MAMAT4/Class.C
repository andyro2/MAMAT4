#include "Class.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;

Class::Class(int const room_num, int size, double max_ratio, int ages, int max_capacitence, bool occupied)
	:Room(room_num, size, occupied), max_ratio_(max_ratio), ages_(ages), max_capacitence_(max_capacitence) {};

int Class::Get_Num_Teachers() const {
	return teachers_.size();
}

int Class::Get_Ages() const {
	return ages_;
}

double Class::Get_Ratio() const {
	return max_ratio_;
}

string Class::Get_Child_Phone(string const child_name) const {
	for (int i = 0 ; i<children_.size(); ++i) {
		if (child_name == children_[i].GetName())
			return children_[i].GetPhone();
	}

	return "No Child";
}