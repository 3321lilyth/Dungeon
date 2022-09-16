#include<iostream>
#include"character.h"
Character::Character(string name, int blood, int attack, int defense, int health) :Object(name, blood, attack, defense), health(health) {
}
int Character::get_health() const { return this->health; }
void Character::health_setter(int a) { this->health += a; }