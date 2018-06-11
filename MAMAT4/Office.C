#include "Office.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::boolalpha;

Office::Office(const int room_num, int size) :Room(room_num, size, true) {}; // can be done with Fill_Room() but seems unnecessary

Result Office::Add_Class(int size, double max_ratio, int ages, int max_cappacitence) {
	if (busy_)
		return FAILURE;
	if (Find_Class_Ages(ages) == -1)
		return FAILURE;
	Class c(classes_.size() + 2, size, max_ratio, ages, max_cappacitence);
	classes_.push_back(c);
	return SUCCESS;
}

int Office::Find_Class_Ages(int ages) {
	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Get_Ages() == ages)
			return i;
	}
	return -1;
}

Result Office::Add_Child(const string name, int age, string phone) {
	if (busy_)
		return FAILURE;
	int i = Find_Class_Ages(age);
	if (i == -1) {
		//cout<<"No class for child age\n";
		return FAILURE;
	}
	if (classes_[i].Add_Child(name, age, phone) == FAILURE)
		return FAILURE;

	return SUCCESS;
}

Result Office::Add_Teacher(string const name, int age, int seniority) {
	if (busy_)
		return FAILURE;
	int i;
	if (classes_.size() == 0) {
		cout << " No Classes" << endl;
		return FAILURE;
	}
	if ((i = Find_Empty_Class()) != -1) {
		classes_[i].Add_Teacher(name, age, seniority);
		return SUCCESS;
	}
	if(All_Classes_Ratio_0()) {
		i = Find_Lowest_Num_Teachers();
		classes_[i].Add_Teacher(name, age, seniority);
		return SUCCESS;
	}
	if((i = Find_Highest_Ratio()) != -1) {
		classes_[i].Add_Teacher(name, age, seniority);
		return SUCCESS;
	}

	return FAILURE;

}

int Office::Find_Empty_Class() {
	for (int i = 0; i < classes_.size(); i++) {
		if (!classes_[i].GetOccupied())
			return i;
	}
	return -1;
}

bool Office::All_Classes_Ratio_0() {
	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Get_Curr_Ratio() != 0.0)
			return false;
	}
	return true;
}

int Office::Find_Lowest_Num_Teachers() {
	int min, min_ind;
	min = classes_[0].Get_Num_Teachers();
	min_ind = 0;
	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Get_Num_Teachers() < min) {
			min = classes_[i].Get_Num_Teachers();
			min_ind = i;
		}
	}
	return min_ind;
}

int Office::Find_Highest_Ratio() {
	int max_ind;
	double max = classes_[0].Get_Curr_Ratio();
	max_ind = 0;
	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Get_Num_Teachers() > max) {
			max = classes_[i].Get_Num_Teachers();
			max_ind = i;
		}
	}
	return max_ind;
}

Result Office::Remove_Child(string const name) {
	if (busy_ && name != sick_child_)
		return FAILURE;

	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Remove_Child(name) == SUCCESS)
			if (busy_) 
				busy_ = false;
			return SUCCESS;
	}
	return FAILURE;
}

Result Office::Remove_Teacher(string const name) {
	if (busy_)
		return FAILURE;
	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Remove_Teacher(name) == SUCCESS)
			return SUCCESS;
	}
	return FAILURE;
}

Result Office::Remove_Class(int ages) {
	if (busy_)
		return FAILURE;
	if (int i = Find_Class_Ages(ages) != -1) {
		//classes_[i].Delete();                // not sure if needed, no malloc was assigned
		classes_.erase(classes_.begin() + i);
		return SUCCESS;
	}
	return FAILURE;
}

Result Office::Set_Sick_Child(string const name) {
	if (busy_)
		return FAILURE;

	if (int i = Find_Child_Class(name) != -1) {
		string phone = classes_[i].Check_Valid_Phone(name);
		if (phone != "Failure") {
			busy_ = true;
			sick_child_ = name;
			classes_[i].Set_Sick_Child(name);
			cout << "Reporting sick child : " << name << endl;
			cout << "Parent's phone number : " << phone << endl;
			return SUCCESS;
		}
	}
	return FAILURE;
}

int Office::Find_Child_Class(string const name) {
	for (int i = 0; i < classes_.size(); i++) {
		if (classes_[i].Find_Child_Pos(name) != -1)
			return i;
	}
	return -1;
}

void Office::Print() const {
	cout << "Printing office status :\n" << "========================" << endl;
	Room::Print();
	cout << "Office is busy : " << boolalpha << busy_ << endl;
	if(busy_)
		cout << "Sick Child : " << sick_child_ << "\n" <<endl;
	if (classes_.size() > 0) {
		for (int i = 0; i < classes_.size(); i++)
			classes_[i].Print();
	}
	return;
}