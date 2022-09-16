#include<iostream>
#include<string>
#include"player.h"

Player::Player(string name, int blood, int attack, int defense, int health) :Character(name, blood, attack, defense, health) {

}
//getter and setter
string Player::get_info()const {
	string s = "player property:\nmax blood: " + to_string(this->get_blood()) + "\ncurrent blood: " + to_string(this->get_health()) + "\nattack power:�@"
		+ to_string(this->get_attack_coffi()) + "\ndefense power: " + to_string(this->get_defense_coffi()) + "\ncurrent room: room" + to_string(this->get_current_room()->get_index())
		+ "\nhave items:";
	for (auto &i : *players_item) {//�ոլݡA����N���U��
		s += i.get_name() + "  ";
	}
	s += "\n";
	return s;
}
Room* Player::get_current_room()const {
	return this->current_room;
}
Room* Player::get_previous_room()const {
	return this->previous_room;
}
vector<Item>* Player::item_getter()const {
	return this->players_item;
}
int Player::get_light_imprint()const {
	return this->light_imprint;
}

void Player::players_item_setter(vector<Item>* vptr) {
	players_item = vptr;
}
void Player::current_room_setter(Room* for_current_room) {
	this->current_room = for_current_room;
}
void Player::previous_room_setter(Room* for_previous_room) {
	this->previous_room = for_previous_room;
}
//��`
void Player::move(Room* now, Room* next) {
	this->previous_room = now;
	this->current_room = next;
}
void Player::getitem(Item item) {
	(*players_item).push_back(item);

	//this->players_item->push_back(item);���ƻ򤣦�
	//*(this->players_item)->push_back(item);�S���ƻ򤣦�
}
void Player::equip_item(Item item) {
	this->defense_coffi_setter(item.get_defense_coffi());
	this->attack_coffi_setter(item.get_attack_coffi());
	this->blood_setter(item.get_blood());
	this->health_setter(item.get_blood());
}
void Player::check_map(vector<vector<Room*>> map)const {//�w�g�L�L�T�{�L�F
	system("cls");
	//�Ĥ@���
	cout << "room1          ||" << "                 " << (map[0][2]->get_have_entered() == 1 ? "room3          ||" : "                 ") << (map[0][3]->get_have_entered() == 1 ? "room4          ||\n" : "                 \n");
	cout << "Jarvan_IV      ||" << "                 " << (map[0][2]->get_have_entered() == 1 ? "               ||" : "                 ") << (map[0][3]->get_have_entered() == 1 ? "               ||\n" : "                 \n");
	cout << "====================================================================\n";
	//�ĤG���
	cout << (map[1][0]->get_have_entered() == 1 ? "room5          ||" : "                 ") << (map[1][1]->get_have_entered() == 1 ? "room6          ||" : "                 ") << (map[1][2]->get_have_entered() == 1 ? "room7          ||\n" : "                 \n");
	cout << (map[1][0]->get_have_entered() == 1 ? "               ||" : "                 ") << (map[1][1]->get_have_entered() == 1 ? "Gromp          ||" : "                 ") << (map[1][2]->get_have_entered() == 1 ? "Aatrox         ||\n" : "                 \n");
	cout << "====================================================================\n";
	//�ĤT���
	cout << (map[2][0]->get_have_entered() == 1 ? "room9          ||" : "                 ") << (map[2][1]->get_have_entered() == 1 ? "room10         ||" : "                 ") << (map[2][2]->get_have_entered() == 1 ? "room11         ||" : "                 ") << (map[2][3]->get_have_entered() == 1 ? "room12         ||\n" : "                 \n");
	cout << (map[2][0]->get_have_entered() == 1 ? "Sylas          ||" : "                 ") << (map[2][1]->get_have_entered() == 1 ? "               ||" : "                 ") << (map[2][2]->get_have_entered() == 1 ? "               ||" : "                 ") << (map[2][3]->get_have_entered() == 1 ? "Raptor         ||\n" : "                 \n");
	cout << "====================================================================\n";
	//�ĥ|���
	cout << (map[3][0]->get_have_entered() == 1 ? "room13         ||" : "                 ") << (map[3][1]->get_have_entered() == 1 ? "room14         ||" : "                 ") << (map[3][2]->get_have_entered() == 1 ? "room15         ||" : "                 ") << (map[3][3]->get_have_entered() == 1 ? "room16         ||\n" : "                 \n");
	cout << (map[3][0]->get_have_entered() == 1 ? "Krugs          ||" : "                 ") << (map[3][1]->get_have_entered() == 1 ? "               ||" : "                 ") << (map[3][2]->get_have_entered() == 1 ? "Wolve          ||" : "                 ") << (map[3][3]->get_have_entered() == 1 ? "Zoe            ||\n" : "                 \n");
	cout << "====================================================================\n";

}
void Player::delete_Amplifying_Tome(vector<Item> original_item) {
	players_item->erase(players_item->begin());	//���ε��@�Ӧ^�ǭȡA�b��players_item=�^�ǭȡA�o�Ӧ�k���_��
}

//�԰�
int Player::skill() {//���g
	this->light_imprint = 1;
	return (this->get_attack_coffi() * 2)+200 ;
}
void Player::runaway() {
	this->current_room_setter(this->get_previous_room());
}
int Player::attack(int light_imprint){
	if (light_imprint == 1) {		
		cout << "you break the light imprint(�����L�O),damage +200. ";
		this->light_imprint = 0;
		return this->get_attack_coffi() + 200;	}
	else {	
		return this->get_attack_coffi() ;
	}
}