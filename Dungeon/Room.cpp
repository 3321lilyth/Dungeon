#include"room.h"
Room::Room(int index, NPC* own_npc, Item own_item, Room* up, Room* down, Room* left, Room* right, int have_entered) {
	this->down = down;
	this->left = left;
	this->right = right;
	this->up = up;
	this->index = index;
	this->own_item = own_item;
	this->own_npc = own_npc;
	this->have_entered = have_entered;
}

//getter
int Room::get_index()const {
	return this->index;
}
Room* Room::get_down_room()const {
	return this->down;
}
Room* Room::get_left_room()const {
	return this->left;
}
Room* Room::get_right_room()const {
	return this->right;
}
Room* Room::get_up_room()const {
	return this->up;
}
Item Room::get_own_item()const {
	return this->own_item;
}
NPC* Room::get_own_npc()const {//­×¥¿
	return this->own_npc;
}
int Room::get_have_entered()const {
	return this->have_entered;
}

//setter
void Room::right_room_setter(Room* a) {
	this->right = a;
}
void Room::down_room_setter(Room*a) {
	this->down = a;
}
void Room::have_entered_setter(int i) {
	this->have_entered = i;
}