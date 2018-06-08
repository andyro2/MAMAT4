#include "Child.H"

using std::cout;
using std::endl;

Child::Child(string name, int age, string phone, bool sick) 
	:Person(name, age), phone_(phone), sick_(sick) {};

string Child::GetPhone() const {
	return phone_;
}

void Child::SetPhone(string phone) {
	phone_ = phone;
	return;
}

Result Child::SetSick() {
	if (sick_ == false) {
		sick_ = true;
		return SUCCESS;
	}
	return FAILURE;
}

void Child::Print() const {
	Person::Print();
	cout << "Parent's Phone : " << phone_ << "\n" << "Is Sick : ";
	if (sick_)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
}
