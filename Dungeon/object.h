#ifndef _object_
#define _object_

#include<string>
using namespace std;

class Object {
public:
	Object();
	Object(string name, int blood, int attack, int defense);//�غc�l
	string get_name() const;
	int get_blood() const;//const�N�����ӧ���ܼƪ���
	int get_attack_coffi() const;
	int get_defense_coffi() const;
	void blood_setter(int a);
	void attack_coffi_setter(int a);
	void defense_coffi_setter(int a);
	virtual ~Object() = default;//���F���ڪ�down casting�i�H�L�o�Ӥw
private:
	string name;
	int blood;//�̰���q�A�Ϊ̪��󪺸ܴN�N��˳Ʀo�ണ�Ѫ���q
	int attack_coffi;
	int defense_coffi;

};



#endif 