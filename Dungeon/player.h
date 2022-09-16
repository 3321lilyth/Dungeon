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
	Player(string name, int blood, int attack, int defense, int health);//�غc�l
	//getter and setter
	Room* get_current_room()const;
	Room* get_previous_room()const;
	vector<Item>* item_getter()const;
	int get_light_imprint()const;

	void players_item_setter(vector<Item>* vptr);
	void current_room_setter(Room* for_current_room);
	void previous_room_setter(Room* for_previous_room);

	//��`���
	void move(Room* now, Room* next);//���ʥ�
	void check_map(vector<vector<Room*>> map) const;//�I�s�a�Ͽ��
	string get_info() const;
	void getitem(Item item);
	void equip_item(Item item);
	void delete_Amplifying_Tome(vector<Item> item);

	//�԰����
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