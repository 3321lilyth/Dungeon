#include<iostream>

#include"item.h"
Item::Item(string name, int blood, int attack, int defense) :Object(name, blood, attack, defense) {}
string Item::get_info() const {
	return  this->get_name() + "\nprovide: \nblood: " + to_string(this->get_blood()) + "\nattack power:¡@"
		+ to_string(get_attack_coffi()) + "\ndefense power: " + to_string(get_defense_coffi());
}
