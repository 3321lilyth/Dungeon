#include<iostream>
#include"NPC.h"

NPC::NPC(string name, int blood, int attack, int defense, int health, string skill_name, string story, Item Droped_reward, int have_killed) :Character(name, blood, attack, defense, health) {
	this->skill_name = skill_name;
	this->story = story;
	this->Droped_reward = Droped_reward;
	this->have_killed = have_killed;
}
string NPC::get_info()const {
	return  "\n\n" + this->get_name() + " property: \nhealth: " + to_string(this->get_health()) + "\nattack power:¡@"
		+ to_string(this->get_attack_coffi()) + "\ndefense power: " + to_string(this->get_defense_coffi())
		+ "\nhave items:" + this->get_Droped_reward().get_name();
}
int NPC::skill() {
	if (this->get_name()== "Aatrox(¤ÌÂÄ´µ)--¤pBOSS") {
		this->health_setter(300);
		this->attack_coffi_setter(70);
	}
	else if(this->get_name()=="Zoe(¬X¥ì)--¤jBOSS") {
	}
	else {
		cout << "wrong NPC";
		exit(1);
	}
	return (this->get_attack_coffi() * 2) + 200;
}
void NPC::set_have_killed(int i) {
	this->have_killed = i;
}
int NPC::get_have_killed()const {
	return this->have_killed;
}
string NPC::get_skill_name()const {
	return this->skill_name;
}
string NPC::get_story()const {
	return this->story;
}
Item NPC::get_Droped_reward()const {
	return this->Droped_reward;
}
int NPC::attack(int zoe_flash) {
	return this->get_attack_coffi() + 300;
}
