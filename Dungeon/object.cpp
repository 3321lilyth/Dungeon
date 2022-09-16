#include<string>
#include"object.h"
using namespace std;
Object::Object() {};
Object::Object(std::string  name, int blood, int attack, int defense) {
	this->name = name;
	this->blood = blood;
	this->attack_coffi = attack;
	this->defense_coffi = defense;
}
int Object::get_attack_coffi() const {
	return this->attack_coffi;
}
int Object::get_blood()const {
	return this->blood;
}
int Object::get_defense_coffi()const {
	return this->defense_coffi;
}
string Object::get_name()const {
	return this->name;
}
void Object::attack_coffi_setter(int a) {
	this->attack_coffi += a;
}
void Object::defense_coffi_setter(int a) {
	this->defense_coffi += a;
}
void Object::blood_setter(int a) {
	this->blood += a;
}