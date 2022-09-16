#ifndef _player_
#define _player_
#include<vector>
#include"character.h"//ok
#include"item.h"
#include"room.h"//ok
#include"NPC.h"//not ok
class Player :public Character {
public:
	Player() {};
	Player(string name, int blood, int attack, int defense, int health);//建構子
	//getter and setter
	Room* get_current_room()const;
	Room* get_previous_room()const;
	vector<Item>* item_getter()const;
	int get_light_imprint()const;

	void players_item_setter(vector<Item>* vptr);
	void current_room_setter(Room* for_current_room);
	void previous_room_setter(Room* for_previous_room);

	//日常選單
	void move(Room* now, Room* next);//移動用
	void check_map(vector<vector<Room*>> map) const;//呼叫地圖選單
	string get_info() const;
	void getitem(Item item);
	void equip_item(Item item);
	void delete_Amplifying_Tome(vector<Item> item);

	//戰鬥選單
	void runaway();
	int skill()override;
	int attack(int light_imprint)override;


private:
	int light_imprint = 0;
	vector<Item>* players_item;
	Room* current_room;
	Room* previous_room;
};



#endif