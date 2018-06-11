#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>
#include <iostream>

using std::string;
using std::boolalpha;

class Room {
public:
	Room(int const room_num, int size);
	int GetRoomNum() const;
	bool GetOccupied() const;

	void Fill_Room();
	void Free_Room();
	void Print() const;

protected:
	int size_;
	int room_num_;
	bool occupied_;
};

#endif
