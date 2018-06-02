#include "Teacher.H"
using std::string;
using std::cout;
using std::endl;

Teacher::Teacher(string const name, int age, int seniority) 
	: Person(name, age), seniority_(seniority) {};

int Teacher::GetSeniority() const{
	return seniority_;
}

void Teacher::Print() const {
	Person::Print();
	cout << "Seniority : " << seniority_ << endl;
}