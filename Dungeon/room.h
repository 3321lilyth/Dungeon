#ifndef _room_
#define _room_
#include"NPC.h"
#include"item.h"
class Room {//�A�Ӧ������m�����ЩM�o��class
public:
	Room(int index, NPC* own_npc, Item own_item, Room* up, Room* down, Room* left, Room* right, int have_entered);//�غc�l
	int get_index()const;
	Room* get_up_room()const;
	Room* get_down_room()const;
	Room* get_left_room()const;
	Room* get_right_room()const;
	NPC* get_own_npc()const;
	Item get_own_item()const;
	int get_have_entered()const;

	//setter
	void down_room_setter(Room* a);
	void right_room_setter(Room* a);
	void have_entered_setter(int i);
private:
	int index;
	Room* up;
	Room* down;
	Room* left;
	Room* right;
	NPC* own_npc;//�qNPC�令NPC*
	Item own_item;
	int have_entered;
};

#endif