#include "Room.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;

Room::Room(int const room_num, int size)
	:occupied_(false) {
	room_num_ = room_num;
	size_ = size;
};

int Room::GetRoomNum() const {
	return room_num_;
}

bool Room::GetOccupied() const {
	return occupied_;
}

void Room::Fill_Room() {
	occupied_ = true;
}

void Room::Free_Room() {
	occupied_ = false;
}

void Room::Print() const{
	cout << "Number : " << room_num_ << "\n" << "Size : " << size_ << " square meters" << endl;
	cout<<"Is Occupied : "<< boolalpha << occupied_ << endl;
}