#ifndef _character_
#define _character_
#include"object.h"

//我本來想技能直接傳目標進去但後來發現這邊不能include NPC因為NPC是他的子類別，所以放棄，還是用原本的回傳整數
class Character :public Object {//基本上怪物跟玩家共有的我都放上來了
public:
	Character() {};
	Character(string name, int blood, int attack, int defense, int health);//建構子
	virtual int skill() = 0;//四個技能放憶起讓她跳清單選ㄇ?好啦就這樣，回傳傷害值
	virtual int attack(int light_imprint) = 0;//普攻
	int get_health()const;
	void health_setter(int a);
private:
	int health;//當下血量

};
#endif