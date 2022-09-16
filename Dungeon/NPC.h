#ifndef _NPC_
#define _NPC_
#include"item.h"
#include"character.h"
class NPC :public Character {
public:
	NPC() {};
	NPC(string name, int blood, int attack, int defense, int health, string skill_name, string story, Item Droped_reward, int have_killed);
	int skill()override;
	int attack(int )override;

	void set_have_killed(int i);
	string get_skill_name()const;
	string get_story()const;
	int get_have_killed()const;
	Item get_Droped_reward()const;
	string get_info()const;

private:
	string skill_name;
	string story;
	Item Droped_reward;
	int have_killed;
};


#endif 