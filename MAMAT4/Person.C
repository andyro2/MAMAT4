#include "Person.H"

using std::string;
using std::cout;
using std::endl;

Person::Person(const string name, int age)
 {
	name_ = name;
	age_ = age;
};

int Person::GetAge() const {
	return age_;
}
string Person::GetName() const {
	return name_;
}
void Person::Print() const {
	cout << "Name : " << name_ << "\n" << "Age : " << age_ << endl;
}

