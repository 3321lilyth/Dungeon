#ifndef _item_
#define _item_
#include"object.h"

class Item :public Object {
public:
	Item() {};
	Item(string name, int blood, int attack, int defense);//�غc�l�A�u��Jitem�S�����N�n�A��L����object��setter�h�]�w
	string get_info()const;//�����a�d�ݪ��󪺩ʽ�ΡA�o�Ө禡�򪱮a�٦��Ǫ�������

};

#endif