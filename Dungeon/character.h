#ifndef _character_
#define _character_
#include"object.h"

//�ڥ��ӷQ�ޯઽ���ǥؼжi�h����ӵo�{�o�䤣��include NPC�]��NPC�O�L���l���O�A�ҥH���A�٬O�έ쥻���^�Ǿ��
class Character :public Object {//�򥻤W�Ǫ��򪱮a�@�����ڳ���W�ӤF
public:
	Character() {};
	Character(string name, int blood, int attack, int defense, int health);//�غc�l
	virtual int skill() = 0;//�|�ӧޯ��а_���o���M���v?�n�մN�o�ˡA�^�Ƕˮ`��
	virtual int attack(int light_imprint) = 0;//����
	int get_health()const;
	void health_setter(int a);
private:
	int health;//��U��q

};
#endif