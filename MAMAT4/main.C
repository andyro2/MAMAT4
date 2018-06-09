#include "Person.H"
#include "Child.H"
#include "Teacher.H"
#include "Room.H"
#include "defs.H"
#include "Class.H"


int main() {
	Class cl(101, 10, 1.3, 2, 5);
//	Teacher t1("t1", 40, 4);
//	Child ch1("ch1", 2, "04444444");

	cl.Add_Teacher("t1", 40, 4);
	cl.Add_Teacher("t2", 40, 4);

	cl.Add_Child("ch1", 2, "04444444");
	cl.Add_Child("ch2", 2, "04444444");
	cl.Add_Child("ch3", 2, "04444444");

	cl.Print();

	return 0;
};
