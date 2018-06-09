#ifndef _OFFICE_H_
#define _OFFICE_H_

#include <string>
#include <vector>

#include "Room.H"
#include "defs.H"
#include "Class.H"

using std::string;
using std::vector;

class Office : public Room {
public:
	Office(const int room_num = 1, int size = 20);
	Result Add_Class(int size, double max_ratio, int ages, int max_cappacitence);
	Result Add_Child(const string name, int age, string phone);
	Result Add_Teacher(string const name, int age, int seniority);
	Result Remove_Child(string const name);
	Result Remove_Teacher(string const name);
	Result Remove_Class(int ages);
	Result Set_Sick_Child(string const name);
	void Print() const;

	int Find_Class_Ages(int ages);
	int Find_Empty_Class();
	bool All_Classes_Ratio_0();
	int Find_Lowest_Num_Teachers();
	int Find_Highest_Ratio();
	int Find_Child_Class(string const name);

protected:
	bool busy_;
	string sick_child_;
	vector<Class> classes_;

	
};

#endif
