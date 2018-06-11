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

int Class::Get_Num_Children() const {
	return children_.size();
}

int Class::Get_Ages() const {
	return ages_;
}

double Class::Get_Ratio() const {
	return max_ratio_;
}

string Class::Get_Child_Phone(string const child_name) const {
	for (int i = 0 ; i < children_.size(); ++i) {
		if (child_name == children_[i].GetName())
			return children_[i].GetPhone();
	}

	return "No Child";
}

void Class::Add_Teacher(string const name, int age, int seniority) {
	Teacher t(name, age, seniority); //dosen't work with new
	teachers_.push_back(t);
	this->Fill_Room();
	return;
}

Result Class::Add_Child(const string name, int age, string phone) {
	if ((double)(children_.size() + 1) / (double)teachers_.size() <= max_ratio_ && (children_.size() + 1) <= max_capacitence_) {
		Child c(name, age, phone);
		children_.push_back(c);
		this->Fill_Room();
		return SUCCESS;
	}
	return FAILURE;
}

Result Class::Remove_Teacher(string const name) {
	if ((double)children_.size() / (double)(teachers_.size() -1) <= max_ratio_) {
		int i = Find_Teacher_Pos(name);
		if (i != -1) {
			teachers_.erase(teachers_.begin() + i);  // not sure
			if (teachers_.size() == 0)
				this->Free_Room();
			return SUCCESS;
		}
	}
	return FAILURE;
}

int Class::Find_Teacher_Pos(string const name) {
	for (int i = 0; i < teachers_.size(); i++) {
		if (teachers_[i].GetName() == name)
			return i;
	}
	return -1;
}

Result Class::Remove_Child(string const name) {
	
	int i = Find_Child_Pos(name);
	if (i != -1) {
		children_.erase(children_.begin() + i);  // not sure
		return SUCCESS;
	}
return FAILURE;
}

int Class::Find_Child_Pos(string const name) {
	for (int i = 0; i < children_.size(); i++) {
		if (children_[i].GetName() == name)
			return i;
	}
	return -1;
}

Result Class::Set_Sick_Child(string const name) {
	int i = Find_Child_Pos(name);
	if (i != -1) {
		children_[i].SetSick();  // not sure
		return SUCCESS;
	}
	return FAILURE;
}

double Class::Get_Curr_Ratio() const {
	return (double)children_.size() / (double)teachers_.size();
}

void Class::Print() const {
	cout << "Printing class status :\n" << "========================" << endl;
	Room::Print();
	cout << "Max number of children : " << max_capacitence_ << endl;
	cout << "Number of children : " << children_.size() << endl;
	cout << "Number of teachers : " << teachers_.size() << endl;
	cout << "Max value for ratio : " << max_ratio_ << endl;
	if (teachers_.size() != 0)
		cout << "Current ratio : " << children_.size()/ teachers_.size() << endl;
	else
		cout << "Current ratio : 0" << endl;
	cout << "Children age range : " << ages_ << " - " << ages_+1 << "\n"<<endl;
	if (children_.size() > 0) {
		cout << "Printing childrens status :\n" << "========================" << endl;
		for (int i = 0; i < children_.size(); i++)
			children_[i].Print();
	}
	if (teachers_.size() > 0) {
		cout << "\nPrinting teachers status :\n" << "========================" << endl;
		for (int i = 0; i < teachers_.size(); i++)
			teachers_[i].Print();
	}
	cout << endl;


}

string Class::Check_Valid_Phone(string const name) {
	int i = this->Find_Child_Pos(name);
	if (i != -1) {
		string phone = children_[i].GetPhone();
		if (phone[0] == '0' && phone[1] == '5' && phone.length() == 10)
			return phone;
	}
	return "Failure";
}