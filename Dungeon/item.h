#ifndef _item_
#define _item_
#include"object.h"

class Item :public Object {
public:
	Item() {};
	Item(string name, int blood, int attack, int defense);//建構子，只輸入item特有的就好，其他的用object的setter去設定
	string get_info()const;//讓玩家查看物件的性質用，這個函式跟玩家還有怪物重載喔

};

#endif