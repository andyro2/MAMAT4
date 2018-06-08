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
	Office(const int room_num, int size, bool occupied = true);

protected:
	bool busy_;
	string sicl_child_;
	vector<Class> clsses_;
};

#endif
