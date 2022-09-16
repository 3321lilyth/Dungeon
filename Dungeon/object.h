#ifndef _object_
#define _object_

#include<string>
using namespace std;

class Object {
public:
	Object();
	Object(string name, int blood, int attack, int defense);//建構子
	string get_name() const;
	int get_blood() const;//const代表不應該更改變數的值
	int get_attack_coffi() const;
	int get_defense_coffi() const;
	void blood_setter(int a);
	void attack_coffi_setter(int a);
	void defense_coffi_setter(int a);
	virtual ~Object() = default;//為了讓我的down casting可以過得而已
private:
	string name;
	int blood;//最高血量，或者物件的話就代表裝備她能提供的血量
	int attack_coffi;
	int defense_coffi;

};



#endif 