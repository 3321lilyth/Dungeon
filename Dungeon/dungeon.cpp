#include <cstdlib>//for istream�Mostream
#include <iostream>//system("pause");�γo�ӨӤ@�Ӥ@�ӥX�r�A��p �L�X.  �M�Ũt��  �L�X.. �M�Ũt��  �L�X...//system("CLS")�O�M�ŵe��
#include<string>
#include<vector>
#include<math.h>
#include<windows.h> //for sleep() function
#include<fstream>
#include <sstream>//for StringStream
#include<time.h>
#include<stdio.h>

#include"item.h"
#include"room.h"
#include"player.h"
#include"object.h"
#include"NPC.h"
#include"character.h"
using namespace::std;
extern int already_skill = 0;
int count_rest_times = 0;
int NPC_attack = 0;
int fighting_manu(Player& lux, NPC* target); //�԰��ɿ��
void regular_manu(Player& lux);//��`�ɿ��
int save_and_load(Player& lux);//�s��Ū�ɿ��
void print_info(Object*);

vector<vector<Room*>> map;
const string story1 = "�G�ƪ��_��-- \n\n�ԧJ����o�������\�۳��X�ͩ󸦺���Ȫ����߻ȥ��C�L�̬O�W�n�㻮���ӫa�u�îa�ڪ��䤤�@���A�����@�@�N�N���u�@�۸�����Ȫ����x�C\n\n�ԧJ���o�{�o�����������O�A���]�k���g�N�Ť�j�����V��������t�A�Ӹ�����ȬO�ƭӹ��]�k�`�c�h�����a�Ϥ��@�C\n\n�o�Ӥ��ꪺ�\�h�ǻ����b�y�z�ۯ¼䪺���F�O�p��Q�]�k���b�ӼZ�J�·t�`�W�C�o���ߦo����O�Q�o�{�A���N�|�����ӫa�a�ڪ����d�C\n\n�M�Ӧb�@������˧L���L�{���A�ԧJ�����F�����@�쥢�h�����å���L�h���i�h���e�����������@��A�N�o���]�k�����`�J�i�h���j���A���H�]���]�k�����ߦӱN�o�˷O�d���欰������:�ԧJ���N���H�̫᪺�ͩR�������l���F�C\n\n�H�ߴq�q�A���F�����ֽ׻P�w�����ߡA�ӫǨM�w���ԧJ���i�J�`�I�a�����g�c���I�C\n\n�Y�o������ۨ��X�ӡA�ña�X���㪺�g�c�a�ϡA�K�ҩ��F�o���������O�������j�A������ȴN�N�����o���s�b�A�o�N�M�\�ۤ@�ˡA�����Ӯa�@�ö��X�L�ץ��W���@���C\n\n���Y���Ѧo�N���h�Ӯa�u�ê����A�ìy����æ�A�û��L�k��J�o���a�m�K�K\n";
const string story2 = "�{�椧�ɡA������Ȱ���Ť�|�@�N�W�T���y�ػP�A�A�Ʊ�A���\�׹L�����A�����Ӯa�u�áA�P���êӧ@��\n\n��o�W�T���y--�����O+100\n\n";
const string story3 = "�~�J������Ⱥʺ��A�J���ɰǴ��C\n\n��Ǵ��X�ͦb������Ȫ��@�ӽa�W�a�x���A���O�۱q�Q�o�{��ޱ��]�k�}�l�A�N�Q�����e��F�j�]�H���̦ۭ��C\n\n�b�o�{��Դ����P���L�H�]�k����O�H��A�N�Q�Q�ΨӴM���L�h�W���k�v�C\n\n���]���@�I�l�����ߡA�O�@�@�Ӥp�k�Īk�v�����F�T�W�j�]�H�C\n\n�q���H��L�N�����F�w����ȳ̦M�I���k�v�A�Q����b�ʺ����̲`�̷t���a��A�ٳQ�����W�F�T�]�ۡC\n";
const string story4 = "���Ĵ��O���j�ɥN��Ĭ�线�Ұꪺ�ܰ��Ԥh�A���b�ϧܭx����X�u��šv��A���M�̫ᦨ�\����u��šv�X���AĬ�线���M�Q�F�z�]���F\n\n�өҦ����̰��Ԥh�̡A�]�t���Ĵ��B�n�v�M�k���h�A���h�@�P�u�@���ؼЩM�@�P��ܪ��ĤH\n\n�̲פ]�Q�u��šv���v�T�A�����z���Ĭ�Ӷ}�ԡA�b�H�������ܰ��Ԥh�w�ܦ��u�ߦ�ڡv�C\n\n�Ӳ{�b�A���J�F���Ĵ�����a�A�����d�~�����j�Ԥh�A���{���C\n";
const string story5 = "�Ať��q����ǨӤp�k�Ī�����n��--�ԧJ��?�A���b�o�̥�A�N�O�ڪ��F!�o�ȱo��n���k�B�͡A�ӥ@�H���|�H���A���b�g�c�̪�~������~!\n\n�w���@�@�A��ӬO�A���u�n�D��H�v��A�纸�S�o��C\n\n�X��۱q�Ĥ@�������A�N���w�W�F�L�A�b��A���e�L�O�@�Ө��_�_�A���b�u�n�L���b���A�����N�ܦ����ʪ��p���D\n\n�ר��A�M�ԧJ�O������Ȥ@�綠�{�����Q�A�X���O�B�B�w��ԧJ��\n\n�o���o�]�����D�O�q���̱o���g�c�X�f����m�A���M�b�o�䵥�ݩԧJ����ӡA�Q�b�o���h�O�ܪ��ɭԱN�ԫȵ��@�|���...\n";
//�A�A�P�ɰǴ���n
const string story6 = "���ѬX���A�ԧJ���ש�A������a���������A���\���}�a���g�c�C\n\n�O�H�N�Ƥ��~���O:�g�c���X�f���M�O�b������Ȫ����D���A�åB���b�����ɰǴ������D!!!\n\n�A�Pı�쨭�骺�O�q���b�v���Q�Ǫ�......\n\n�ɰǴ���--HIJACK(�s�޸T��)�T���F�A��������q�åB����X�ӡA�O���F��D�H�M�����H���C\n\n�ߦ��A�A�]���@���{�ɰ_�N�ػP�L���W�T���y�A���A���������ߤ@�S���Q�ˮ`���H...\n";
//�A�L���ɰǴ�
const string story7 = "���ѬX���A�ԧJ���ש�A������a���������A���\���}�a���g�c�C\n\n�O�H�N�Ƥ��~���O:�g�c���X�f���M�O�b������Ȫ����D���A�åB���b�����ɰǴ������D!!!\n\n�A�Pı�쨭�骺�O�q���b�v���Q�Ǫ�......\n\n�ɰǴ���--HIJACK(�s�޸T��)�T���F�A��������q�åB����X�ӡA�O���F��D�H�M�����H���A�A�L�i�קK���]����1000�I�ˮ`......\n";

//�˳ƪ��ܡA�ж���NPC���i�H�֦�
Item item_for_nothing("nothing", 0, 0, 0);
Item Amplifying_Tome("Amplifying_Tome(�W�T���y)", 0, 100, 0);
Item Null_Magic_Mantle("Null-Magic-Mantle(���]���O)", 0, 0, 200);
Item Ruby_crystal("ruby_crystal(������)", 500, 0, 0);
Item Blasting_wand("Blasting_wand(�z���]��)", 0, 150, 0);
Item Void_staff("Void_staff(��Ť���)", 0, 200, 0);
Item Cloth_Armor("Cloth_Armor(����)", 0, 0, 100);
Item Giant_belt("giant��s_belt(���H�y�a)", 1500, 0, 0);
Item Needlessly_large_rod("needlessly_large_rod(�L�Τj��)", 0, 200, 0);

//�ж��֦�����A�Ӥ��O����b���өж��C�M��G�Ƹ��npc�Ӥ��O��۩ж�
NPC npc_for_nothing("nothing", 0, 0, 0, 0, "nothing", "no story", item_for_nothing, 0);
NPC Jarvan_IV("Jarvan_IV(�Ť�|�@)", 100, 100, 100, 100, "nothing", story2, Amplifying_Tome, 1);
NPC Sylas("Sylas(�ɰǴ�)", 100, 100, 100, 100, "nothing", story3, item_for_nothing, 0);
NPC Aatrox("Aatrox(���Ĵ�)--�pBOSS", 2000, 400, 400, 2000, "WORLD ENDER--�|�^��300�üW�[70�����O", story4, Needlessly_large_rod, 0);
NPC Zoe("Zoe(�X��)--�jBOSS", 3300, 700, 400, 3000, "PADDLE STAR!!--�|�{�קA���U������", story5, item_for_nothing, 0);
NPC Gromp("Gromp(����)", 1300, 200, 200, 1300, "nothing", "no story", Null_Magic_Mantle, 0);
NPC Krugs("Krugs(���Y)", 1300, 200, 200, 1300, "nothing", "no story", Ruby_crystal, 0);
NPC Wolve("Wolve(�T�T)", 2000, 300, 400, 2000, "nothing", "no story", Blasting_wand, 0);
NPC Raptor("Raptor(����)", 2000, 400, 400, 2000, "nothing", "no story", Void_staff, 0);
//�ж�
Room room1(1, &Jarvan_IV, item_for_nothing, NULL, NULL, NULL, NULL, 0);
Room room3(3, &npc_for_nothing, item_for_nothing, NULL, NULL, NULL, NULL, 0);
Room room4(4, &npc_for_nothing, Giant_belt, NULL, NULL, &room3, NULL, 0);
Room room5(5, &npc_for_nothing, item_for_nothing, &room1, NULL, NULL, NULL, 0);
Room room6(6, &Gromp, item_for_nothing, NULL, NULL, &room5, NULL, 0);
Room room7(7, &Aatrox, item_for_nothing, &room3, NULL, &room6, NULL, 0);
Room room9(9, &Sylas, item_for_nothing, &room5, NULL, NULL, NULL, 0);
Room room10(10, &npc_for_nothing, item_for_nothing, &room6, NULL, &room9, NULL, 0);
Room room11(11, &npc_for_nothing, item_for_nothing, &room7, NULL, &room10, NULL, 0);
Room room12(12, &Raptor, item_for_nothing, NULL, NULL, &room11, NULL, 0);
Room room13(13, &Krugs, item_for_nothing, &room9, NULL, NULL, NULL, 0);
Room room14(14, &npc_for_nothing, Cloth_Armor, &room10, NULL, &room13, NULL, 0);
Room room15(15, &Wolve, item_for_nothing, &room11, NULL, &room14, NULL, 0);
Room room16(16, &Zoe, item_for_nothing, &room12, NULL, &room15, NULL, 0);



int main() {//����G�Ʃж��򪫥󳣥��ͥX��
	std::cout << "�C���ظm���A�еy��...";
	Sleep(1500);
	room1.down_room_setter(&room5);
	room3.down_room_setter(&room7);
	room3.right_room_setter(&room4);
	room5.down_room_setter(&room9);
	room5.right_room_setter(&room6);
	room6.down_room_setter(&room10);
	room6.right_room_setter(&room7);
	room7.down_room_setter(&room11);
	room9.down_room_setter(&room13);
	room9.right_room_setter(&room10);
	room10.down_room_setter(&room14);
	room10.right_room_setter(&room11);
	room11.down_room_setter(&room15);
	room11.right_room_setter(&room12);
	room12.down_room_setter(&room16);
	room13.right_room_setter(&room14);
	room14.right_room_setter(&room15);
	room15.right_room_setter(&room16);
	map = {
		{&room1,NULL,&room3,&room4},
		{&room5,&room6,&room7,NULL},
		{&room9,&room10,&room11,&room12},
		{&room13,&room14,&room15,&room16}
	};
	Player Lux("lux", 2000, 200, 100, 1500);
	vector<Item> lux_item;
	Lux.players_item_setter(&lux_item);
	save_and_load(Lux);
	while (Zoe.get_have_killed() != 1) {//�X��Q�����N���X��
		regular_manu(Lux);
	}
	//���D��
	system("cls");
	vector<Item>* v = Lux.item_getter();
	if ((*v)[0].get_name() == "Amplifying_Tome(�W�T���y)") {//�S���X�h
		//�]���A��v�O�@�ӫ��Vvector<Item>�����СA�ҥH�A�n��*v�復���ȡA*v�N�����Ovector<Item>�A�A�n�A��o��vector���a�@�Ӥ���[0]�A�]�N�O�@��item�������W�r
		std::cout << story7;
		system("pause");
		system("cls");
		if (Lux.get_health() <= 1000) {
			cout << "�A�b�ɰǴ����������U���`�A�C������\n";
			system("pause");
			save_and_load(Lux);
		}
		else {
			cout << "�A�����˨ä��P���A�_���e�X�a���g�c���a�ϤW�浹�Ť�|�@�A�̲���o�H�����{�i�����Ӯa�u�áC\n\n���߹C���q�����\\n";
		}
	}
	else {//���X�h�F
		cout << story6;
		system("pause");
		system("cls");
		cout << "�A���\�s���U�Өõe�X�a���g�c���a�ϤW�浹�Ť�|�@�A�̲���o�H�����{�i�����Ӯa�u�áC\n\n���߹C���q�����\\n";
	}
	system("pause");
	return 0;
}
//��`�ɿ��禡
void regular_manu(Player& lux) {//���a�b�e�����i�H��ܲ��ʡB�𮧡B��ܡB�d�ݸ˳ơB�d�ݦa�ϡB�s�ɨðh�X�C��
	system("CLS");
	int choice = 0;
	cout << "enter your action:\n1.rest \n2.move up \n3.move down \n4.move left \n5.move right \n6.check your property \n7.cheak your item \n8.check map \n9.show setting interface\n";
	cin >> choice;
	switch (choice) {
	case 1://rest
		if (count_rest_times == 1 || count_rest_times == 0) {
			if ((lux.get_health() + 500) <= lux.get_blood()) {//�[�Wa��p�󵥩�̰���q�~������
				lux.health_setter(500);
				cout << "you have got 500HP cure.\n";
			}
			else if ((lux.get_health() + 500) > lux.get_blood() && lux.get_health() < lux.get_blood()) {//��q��̰���q�֦��O�[�W�h�S�W�L�A�����]�w�����g
				cout << "you have got " << lux.get_blood() - lux.get_health() << "HP cure.\n";
				lux.health_setter(lux.get_blood() - lux.get_health());
			}
			else {//���g���A,ԣ������
				cout << "you already have full health\n";
			}
			count_rest_times++;
			cout << "you have rest " << count_rest_times << " times(at most 2times)\n";

		}
		else {
			cout << "you rest too much...keep moving!!\n";
		}
		break;
	case 2://move up
		if (lux.get_current_room()->get_up_room() != NULL) {//�{�b��m���W�����ж��A�~�ಾ��
			lux.move(lux.get_current_room(), lux.get_current_room()->get_up_room());
			if (lux.get_current_room()->get_own_item().get_name() != "nothing" && lux.get_current_room()->get_have_entered() == 0 && lux.get_current_room()->get_own_npc()->get_name() == "nothing") {
				//�Ĥ@����ӨåB�ж����u������ӨS��npc��
				system("cls");
				cout << "you found a item--" << lux.get_current_room()->get_own_item().get_name() << ", and you equip it.\n";
				print_info(&lux.get_current_room()->get_own_item());
				cout << "\n\n";
				lux.equip_item(lux.get_current_room()->get_own_item());
				lux.getitem(lux.get_current_room()->get_own_item());
				print_info(&lux);
			}

			else if (lux.get_current_room()->get_own_npc()->get_name() != "nothing" && lux.get_current_room()->get_own_npc()->get_have_killed() == 0 && lux.get_current_room()->get_own_npc()->get_name() != "Sylas(�ɰǴ�)") {
				//�Y�ж��s�bnpc�A�åBnpc�٬��ۡA�Υ��L���Ǫ��٨S���A�åB���O�J���ɰǴ��A�]���L���θ��ɰǴ���
				if (lux.get_current_room()->get_own_npc()->get_story() != "no story" && lux.get_current_room()->get_have_entered() == 0) {
					//�Ynpc�a���@���A�åB�@���٨S�X�{�L�A�]�N�O�Ĥ@���i��ж�
					system("CLS");
					cout << lux.get_current_room()->get_own_npc()->get_story();
					system("pause");
				}
				//�i���i�J�԰����A
				system("CLS");
				cout << "�i�J�԰�\n���: " << lux.get_current_room()->get_own_npc()->get_name() << "\n��⪬�A:\n�����O--"
					<< lux.get_current_room()->get_own_npc()->get_attack_coffi()
					<< "\n���m�O--" << lux.get_current_room()->get_own_npc()->get_defense_coffi() << "\n��q--"
					<< lux.get_current_room()->get_own_npc()->get_health() << "\nskill--" << lux.get_current_room()->get_own_npc()->get_skill_name()<<"\n";

				//�I�s�԰����
				system("pause");
				fighting_manu(lux, lux.get_current_room()->get_own_npc());

			}
			else if (lux.get_current_room()->get_own_npc()->get_name() == "Sylas(�ɰǴ�)" && lux.get_current_room()->get_have_entered() == 0) {
				//�Ĥ@���i���ɰǴ����ж�
				system("cls");
				cout << "you have entered the room9\n" << lux.get_current_room()->get_own_npc()->get_story();
				system("pause");
				int choice;
				cout << "choice 1--�N���W���W�T���y�ػP�L�A�P�L��n\nchoice 2--�ۤv�u�O���L�A���@�S�ݨ�N�n\n";
				cin >> choice;
				system("cls");
				if (choice == 1) {
					lux.delete_Amplifying_Tome(*(lux.item_getter()));
					//�]���ǤJdelete_Amplifying_Tome���޼ƬOvector<Item>
					//�ӧAlux.item_getter()�^�Ǫ��O���Vvector<Item>�����СA�ҥH�n()�_�ӦA�[�W*�����Ъ���
					lux.attack_coffi_setter(-100);
					cout << "you have gave Amplifying_Tome to him. your attack coffi -100\n";
					print_info(&lux);
				}
				else {
					cout << "you have chosen choice 2, nothing happen\n";
				}
			}
			else {//�S��npc�Ϊ�npc�w���A���N�S�Ʊ��o��
			   //�U���ɰǴ�
				system("cls");
				cout << "nothing happened. you have entered the room" << lux.get_current_room()->get_index() << "\n";
			}
		}
		else {
			system("cls");
			cout << "there is nothing if you go up, choice another direction.\n";
		}
		NPC_attack = 0;
		already_skill = 0;
		count_rest_times = 0;
		lux.get_current_room()->have_entered_setter(1);
		break;
	case 3://move down
		if (lux.get_current_room()->get_down_room() != NULL) {//�{�b��m���W�����ж��A�~�ಾ��
			lux.move(lux.get_current_room(), lux.get_current_room()->get_down_room());
			if (lux.get_current_room()->get_own_item().get_name() != "nothing" && lux.get_current_room()->get_have_entered() == 0 && lux.get_current_room()->get_own_npc()->get_name() == "nothing") {
				//�Ĥ@����ӨåB�ж����u������ӨS��npc��	
				system("cls");
				cout << "you found a item--" << lux.get_current_room()->get_own_item().get_name() << ", and you equip it.\n";
				print_info(&lux.get_current_room()->get_own_item());
				cout << "\n\n";
				lux.getitem(lux.get_current_room()->get_own_item());
				lux.equip_item(lux.get_current_room()->get_own_item());
				print_info(&lux);
			}
			else if (lux.get_current_room()->get_own_npc()->get_name() != "nothing" && lux.get_current_room()->get_own_npc()->get_have_killed() == 0 && lux.get_current_room()->get_own_npc()->get_name() != "Sylas(�ɰǴ�)") {
				//�Y�ж��s�bnpc�A�åBnpc�٬��ۡA�Υ��L���Ǫ��٨S��
				if (lux.get_current_room()->get_own_npc()->get_story() != "no story" && lux.get_current_room()->get_have_entered() == 0) {
					//�Ynpc�a���@���A�åB�@���٨S�X�{�L�A�]�N�O�Ĥ@���i��ж�
					system("CLS");
					cout << lux.get_current_room()->get_own_npc()->get_story();
					system("pause");

				}
				//�i���i�J�԰����A
				system("CLS");
				cout << "�i�J�԰�\n���-- " << lux.get_current_room()->get_own_npc()->get_name() << "\n��⪬�A:\n�����O--" << lux.get_current_room()->get_own_npc()->get_attack_coffi()
					<< "\n���m�O--" << lux.get_current_room()->get_own_npc()->get_defense_coffi() << "\n��q--"
					<< lux.get_current_room()->get_own_npc()->get_health() << "\nskill--" << lux.get_current_room()->get_own_npc()->get_skill_name() << "\n";
				//�I�s�԰����A�b��
				system("pause");
				fighting_manu(lux, lux.get_current_room()->get_own_npc());

			}
			else if (lux.get_current_room()->get_own_npc()->get_name() == "Sylas(�ɰǴ�)" && lux.get_current_room()->get_have_entered() == 0) {
				//�Ĥ@���i���ɰǴ����ж�
				system("cls");
				cout << "you have entered the room9\n" << lux.get_current_room()->get_own_npc()->get_story();
				system("pause");
				int choice;
				cout << "choice 1--�N���W���W�T���y�ػP�L�A�P�L��n\nchoice 2--�ۤv�u�O���L�A���@�S�ݨ�N�n\n";
				cin >> choice;
				system("cls");
				if (choice == 1) {
					lux.delete_Amplifying_Tome(*(lux.item_getter()));
					lux.attack_coffi_setter(-100);
					cout << "you have gave Amplifying_Tome to him. your attack coffi -100\n";
					print_info(&lux);
				}
				else {
					cout << "you have chosen choice 2, nothing happen\n";
				}
			}
			else {//�S��npc�Ϊ�npc�w���A���N�S�Ʊ��o��
				system("cls");
				cout << "nothing happened. you have entered the room" << lux.get_current_room()->get_index() << "\n";
			}
		}
		else {
			system("cls");
			cout << "there is nothing if you go down, choice another direction.\n";
		}
		NPC_attack = 0;
		already_skill = 0;
		count_rest_times = 0;
		lux.get_current_room()->have_entered_setter(1);
		break;
	case 4://move left
		if (lux.get_current_room()->get_left_room() != NULL) {//�{�b��m���W�����ж��A�~�ಾ��
			lux.move(lux.get_current_room(), lux.get_current_room()->get_left_room());
			if (lux.get_current_room()->get_own_item().get_name() != "nothing" && lux.get_current_room()->get_have_entered() == 0 && lux.get_current_room()->get_own_npc()->get_name() == "nothing") {
				//�Ĥ@����ӨåB�ж����u������ӨS��npc��
				system("cls");
				cout << "you found a item--" << lux.get_current_room()->get_own_item().get_name() << ", and you equip it.\n";
				print_info(&lux.get_current_room()->get_own_item());
				cout << "\n\n";
				lux.getitem(lux.get_current_room()->get_own_item());
				lux.equip_item(lux.get_current_room()->get_own_item());
				print_info(&lux);
			}
			else if (lux.get_current_room()->get_own_npc()->get_name() != "nothing" && lux.get_current_room()->get_own_npc()->get_health() > 0 && lux.get_current_room()->get_own_npc()->get_name() != "Sylas(�ɰǴ�)") {
				//�Y�ж��s�bnpc�A�åBnpc�٬��ۡA�Υ��L���Ǫ��٨S��
				if (lux.get_current_room()->get_own_npc()->get_story() != "no story" && lux.get_current_room()->get_have_entered() == 0) {//�Ynpc�a���@���A�åB�@���٨S�X�{�L�A�]�N�O�Ĥ@���i��ж�
					system("CLS");
					cout << lux.get_current_room()->get_own_npc()->get_story();
					system("pause");
				}
				//�i���i�J�԰����A
				system("CLS");
				cout << "�i�J�԰�\n���: " << lux.get_current_room()->get_own_npc()->get_name() << "\n��⪬�A:\n�����O--" << lux.get_current_room()->get_own_npc()->get_attack_coffi()
					<< "\n���m�O--" << lux.get_current_room()->get_own_npc()->get_defense_coffi() << "\n��q--"
					<< lux.get_current_room()->get_own_npc()->get_health() << "\nskill--" << lux.get_current_room()->get_own_npc()->get_skill_name() << "\n";
				//�I�s�԰����A�b��
				system("pause");
				fighting_manu(lux, lux.get_current_room()->get_own_npc());

			}
			else if (lux.get_current_room()->get_own_npc()->get_name() == "Sylas(�ɰǴ�)" && lux.get_current_room()->get_have_entered() == 0) {//�Ĥ@���i���ɰǴ����ж�
				system("cls");
				cout << "you have entered the room9\n" << lux.get_current_room()->get_own_npc()->get_story();				system("pause");
				int choice;
				cout << "choice 1--�N���W���W�T���y�ػP�L�A�P�L��n\nchoice 2--�ۤv�u�O���L�A���@�S�ݨ�N�n\n";
				cin >> choice;
				system("cls");
				if (choice == 1) {
					lux.delete_Amplifying_Tome(*(lux.item_getter()));
					lux.attack_coffi_setter(-100);
					cout << "you have gave Amplifying_Tome to him. your attack coffi -100\n";
					print_info(&lux);
				}
				else {
					cout << "you have chosen choice 2, nothing happen\n";
				}
			}
			else {//�S��npc�Ϊ�npc�w���A���N�S�Ʊ��o��
				system("cls");
				cout << "nothing happened. you have entered the room" << lux.get_current_room()->get_index() << "\n";
			}
		}
		else {
			system("cls");
			cout << "there is nothing if you go left, choice another direction.\n";
		}
		NPC_attack = 0;
		already_skill = 0;
		count_rest_times = 0;
		lux.get_current_room()->have_entered_setter(1);
		break;
	case 5://move right
		if (lux.get_current_room()->get_right_room() != NULL) {//�{�b��m���W�����ж��A�~�ಾ��
			lux.move(lux.get_current_room(), lux.get_current_room()->get_right_room());
			if (lux.get_current_room()->get_own_item().get_name() != "nothing" && lux.get_current_room()->get_have_entered() == 0 && lux.get_current_room()->get_own_npc()->get_name() == "nothing") {
				//�Ĥ@����ӨåB�ж����u������ӨS��npc��
				system("cls");
				cout << "you found a item--" << lux.get_current_room()->get_own_item().get_name() << ", and you equip it.\n";
				print_info(&lux.get_current_room()->get_own_item());
				cout << "\n\n";
				lux.getitem(lux.get_current_room()->get_own_item());
				lux.equip_item(lux.get_current_room()->get_own_item());
				print_info(&lux);
			}
			else if (lux.get_current_room()->get_own_npc()->get_name() != "nothing" && lux.get_current_room()->get_own_npc()->get_health() > 0 && lux.get_current_room()->get_own_npc()->get_name() != "Sylas(�ɰǴ�)") {
				//�Y�ж��s�bnpc�A�åBnpc�٬��ۡA�Υ��L���Ǫ��٨S��
				cout << lux.get_current_room()->get_have_entered();
				if (lux.get_current_room()->get_own_npc()->get_story() != "no story" && lux.get_current_room()->get_have_entered() == 0) {//�Ynpc�a���@���A�åB�@���٨S�X�{�L�A�]�N�O�Ĥ@���i��ж�
					system("CLS");
					cout << lux.get_current_room()->get_own_npc()->get_story();
					system("pause");
				}
				//�i���i�J�԰����A
				system("CLS");
				cout << "�i�J�԰��A���: " << lux.get_current_room()->get_own_npc()->get_name() << "\n��⪬�A:\n�����O--" << lux.get_current_room()->get_own_npc()->get_attack_coffi()
					<< "\n���m�O--" << lux.get_current_room()->get_own_npc()->get_defense_coffi() << "\n��q--"
					<< lux.get_current_room()->get_own_npc()->get_blood() << "\nskill--" << lux.get_current_room()->get_own_npc()->get_skill_name() << "\n";
				//�I�s�԰����A�b��
				system("pause");
				fighting_manu(lux, lux.get_current_room()->get_own_npc());

			}
			else if (lux.get_current_room()->get_own_npc()->get_name() == "Sylas(�ɰǴ�)" && lux.get_current_room()->get_have_entered() == 0) {//�Ĥ@���i���ɰǴ����ж�
				system("cls");
				cout << "you have entered the room9\n" << lux.get_current_room()->get_own_npc()->get_story();				system("pause");
				int choice;
				cout << "choice 1--�N���W���W�T���y�ػP�L�A�P�L��n\nchoice 2--�ۤv�u�O���L�A���@�S�ݨ�N�n\n";
				cin >> choice;
				system("cls");
				if (choice == 1) {
					lux.delete_Amplifying_Tome(*(lux.item_getter()));
					lux.attack_coffi_setter(-100);
					cout << "you have gave Amplifying_Tome to him. your attack coffi -100\n";
					print_info(&lux);
					//lux.check_property();
				}
				else {
					cout << "you have chosen choice 2, nothing happen\n";
				}
			}
			else {//�S��npc�Ϊ�npc�w���A���N�S�Ʊ��o��
				system("cls");
				cout << "nothing happened. you have entered the room" << lux.get_current_room()->get_index() << "\n";
			}
		}
		else {
			system("cls");
			cout << "there is nothing if you go right, choice another direction.\n";
		}
		NPC_attack = 0;
		already_skill = 0;
		count_rest_times = 0;
		lux.get_current_room()->have_entered_setter(1);
		break;
	case 6://check property
		system("CLS");
		print_info(&lux);
		break;
	case 7://check item
		system("CLS");
		for (const auto& v : *lux.item_getter()) {
			cout << v.get_name() << "\n";
		}
		break;
	case 8://check map�᭱�b�g
		lux.check_map(map);
		break;

	case 9://Setting interface
		save_and_load(lux);
		break;
	default:
		cout << "wrong command,try again";
		break;
	}
	system("pause");
}

//�԰��ɿ��禡:�ޯ�B����B�k�]�A
int  fighting_manu(Player& lux, NPC* target) {
	//�Ǫ�����q�n�^�ӡA�~���|���L�i�H�����k�]�𮧦^���~�򥴤w���媺�Ǫ�
	target->health_setter(target->get_blood() - target->get_health());
	//���Ĵ��������O�n�^��쥻���]�w�A�_�h�i�J�⦸�L�������O�ܦ�+70�⦸
	if (target->get_name() == "Aatrox(���Ĵ�)--�pBOSS") {
		target->attack_coffi_setter(-(target->get_attack_coffi() - 400));
	}


	int choice = 0;

	while (lux.get_health() > 0 && target->get_health() > 0) {//���a����->�L�X��̪��A->�Ǫ�����->�L�X��̪��A�A�j��
		std::system("CLS");
		print_info(&lux);
		print_info(target);
		//���a������
		std::cout << "\n\nenter your action:\n1.attack \n2.use skill \n3.runaway\n";
		cin >> choice;
		switch (choice) {
			case 1: {//����
				if (target->get_name() == "Zoe(�X��)--�jBOSS"&& NPC_attack == 3) {//�p�G�O�X��åB�g��L�ޯ�F
					srand(time(NULL));
					int damage = lux.attack(lux.get_light_imprint()) +300 - target->get_defense_coffi() + (rand() % 50) * 2 - 50;
					std::cout << "your attack supposed to  cause " << damage << " damage, but Zoe escaped it";
					Sleep(1500);

				}
				else {
					srand(time(NULL));
					int damage = lux.attack(lux.get_light_imprint()) +300 - target->get_defense_coffi() + (rand() % 50) * 2 - 50;
					std::cout << "you attacked and caused " << damage << " damage";
					Sleep(1500);
					target->health_setter(-damage);
				}
			}
					break;

			case 2: {//�ޯ�
				if (already_skill == 0) {
					srand(time(NULL));
					int damage = lux.skill()-target->get_defense_coffi() + (rand() % 50) * 2 - 50;
					std::cout << "you used skill--FINAL SPARK and caused " << damage << " damage. And you leave a light imprint(�����L�O) on the monster.";
					Sleep(1500);
					target->health_setter(-damage);
					already_skill++;

				}
				else {
					std::cout << "your skill is under cold down\n";
					Sleep(1500);
				}
			}
					break;

			case 3: {//�k�]
				std::cout << "you can't fight so you runaway, back to your previous room--room" << lux.get_previous_room()->get_index() << "\n";
				std::cout << "your health--" << lux.get_health()<<"\n";
				lux.get_current_room()->have_entered_setter(1);
				lux.runaway();
				return 0;
			}
			default:
				std::cout << "wrong command,try again\n";
				break;
		}
		if (target->get_health() <= 0) {
			target->set_have_killed(1);
			std::system("cls");
			if (target->get_name() != "Zoe(�X��)--�jBOSS") {
				std::cout << "you win! \nyou get a item--" << target->get_Droped_reward().get_name() << " as a reward\n\n";
				std::cout << "item property:\nblood increase: " << target->get_Droped_reward().get_blood() << "\ndefense increase: "
					<< target->get_Droped_reward().get_defense_coffi() << "\nattack increase: " << target->get_Droped_reward().get_attack_coffi();
				lux.getitem(target->get_Droped_reward());
				lux.equip_item(target->get_Droped_reward());
				std::cout << "\n\n";
				print_info(&lux);
			}
			else {
				std::cout << "you win!\n";
			}
			return 0;
		}
		//�Ǫ������
		if (NPC_attack == 2 && target->get_skill_name() != "nothing") {//NPC�ĤT�������|����ޯ�
			int damage = target->get_attack_coffi() - lux.get_defense_coffi() + 300 + (rand() % 50) * 2 - 50;
			srand(time(NULL));
			std::cout << "\n" << target->get_name() << " used skill--" << target->get_skill_name()<<" ";
			target->skill();
			cout<<"\nand "<< target->get_name() << " attacked you, caused " << damage << " damage\n";
			Sleep(1500);
			lux.health_setter(-damage);
			NPC_attack++;
		}
		else {
			srand(time(NULL));
			int damage = target->get_attack_coffi() - lux.get_defense_coffi() + 300 + (rand() % 50) * 2 - 50;
			std::cout << "\n" << target->get_name() << " attacked you and caused " << damage << " damage\n";
			Sleep(1500);
			lux.health_setter(-damage);
			NPC_attack++;
		}
		if (lux.get_health() <= 0) {
			std::system("cls");
			std::cout << "GAME OVER";
			std::system("pause");
			save_and_load(lux);
			return 0;
		}
	}

	return 0;
}

int save_and_load(Player& lux) {

	std::system("cls");
	std::cout << "Dungeon game\n";
	std::cout << "1.Ū��\n2.�s�C��\n3.�s��(�л\)\n";
	int num;
	cin >> num;
	std::system("cls");
	if (num == 1) {//Ū��
		try {
			//����Ҧ�lux�F���k��A�]���p�G�A����@�b�I�sŪ�ɡA����Ʒ|�����[�W�ӡA��p�A�|�ܦ������@�˪��˳� 
			lux.blood_setter(1500 - lux.get_blood());
			lux.attack_coffi_setter(200 - lux.get_attack_coffi());
			lux.defense_coffi_setter(100 - lux.get_defense_coffi());
			lux.health_setter(1500 - lux.get_health());
			(*lux.item_getter()).clear();//�R���Ҧ��˳ơA���n���S�����\
			//lux.item_getter()�^�Ǫ��Ovector<Item>*  �ҥH�n��*���Ȥ���A�o��vector<Item>�~�i�H��vector�������禡
			//�t�~�`�N*(lux.item_getter()).clear();�|�O����
			//�Ҧb�ж����Χ�A�U���|���A��A�i�h�L���ж��]���Χ�
			ifstream inStream;
			string s;
			stringstream ss;
			ss.str("");
			ss.clear();
			inStream.open("file.txt");
			if (inStream.fail()) {
				string s = "�٥��i��L�C���A�ж}�Ҥ@�ӷs�C��\n";//�ڥ��Ӫ�����o�q��r�g�bthrow�᭱�A���o�����ӬOc-style�r��Ӥ��Os�ҥHcatch������
				throw s;
			}
			std::cout << "���bŪ�ɽеy��...\n\n";
			system("pause");

			//�`�@�|��C�A�ж��B���a���A�B���a�֦��D��W�١BNPC���A�A�C�C�����p�����@�˧ڴN��}�g�o

			//�ж� --14�ӼƦr
			getline(inStream, s);
			ss << s;
			int num;
			ss >> num;
			if (num == 1) { room1.have_entered_setter(1); }
			else { room1.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room3.have_entered_setter(1); }
			else { room3.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room4.have_entered_setter(1); }
			else { room4.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room5.have_entered_setter(1); }
			else { room5.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room6.have_entered_setter(1); }
			else { room6.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room7.have_entered_setter(1); }
			else { room7.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room9.have_entered_setter(1); }
			else { room9.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room10.have_entered_setter(1); }
			else { room10.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room11.have_entered_setter(1); }
			else { room11.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room12.have_entered_setter(1); }
			else { room12.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room13.have_entered_setter(1); }
			else { room13.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room14.have_entered_setter(1); }
			else { room14.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room15.have_entered_setter(1); }
			else {	room15.have_entered_setter(0); }
			ss >> num;
			if (num == 1) { room16.have_entered_setter(1); }
			else { room16.have_entered_setter(0); }


			//���a���A--��q�B�����O�B���m�O�B���d�B���b�ж�index�B�W�өж�index
			ss.str("");
			ss.clear();
			getline(inStream, s);
			ss << s;

			ss >> num;  lux.blood_setter(num - 1500);//�]����blood_sette�̭��O�Υ[���ҥH�o��n�������쥻����q1500�A�U���P
			ss >> num;	lux.attack_coffi_setter(num - 200);
			ss >> num;	lux.defense_coffi_setter(num - 100);
			ss >> num;	lux.health_setter(num - 1500);
			ss >> num;	//���U�ж�
			switch (num) {
			case 1:
				lux.current_room_setter(&room1);
				break;
			case 3:
				lux.current_room_setter(&room3);
				break;
			case 4:
				lux.current_room_setter(&room4);
				break;
			case 5:
				lux.current_room_setter(&room5);
				break;
			case 6:
				lux.current_room_setter(&room6);
				break;
			case 7:
				lux.current_room_setter(&room7);
				break;
			case 9:
				lux.current_room_setter(&room9);
				break;
			case 10:
				lux.current_room_setter(&room10);
				break;
			case 11:
				lux.current_room_setter(&room11);
				break;
			case 12:
				lux.current_room_setter(&room12);
				break;
			case 13:
				lux.current_room_setter(&room13);
				break;
			case 14:
				lux.current_room_setter(&room14);
				break;
			case 15:
				lux.current_room_setter(&room15);
				break;
			case 16:
				lux.current_room_setter(&room16);
				break;
			}
			ss >> num;	//�e�@�өж�
			switch (num) {
			case 1:
				lux.previous_room_setter(&room1);
				break;
			case 3:
				lux.previous_room_setter(&room3);
				break;
			case 4:
				lux.previous_room_setter(&room4);
				break;
			case 5:
				lux.previous_room_setter(&room5);
				break;
			case 6:
				lux.previous_room_setter(&room6);
				break;
			case 7:
				lux.previous_room_setter(&room7);
				break;
			case 9:
				lux.previous_room_setter(&room9);
				break;
			case 10:
				lux.previous_room_setter(&room10);
				break;
			case 11:
				lux.previous_room_setter(&room11);
				break;
			case 12:
				lux.previous_room_setter(&room12);
				break;
			case 13:
				lux.previous_room_setter(&room13);
				break;
			case 14:
				lux.previous_room_setter(&room14);
				break;
			case 15:
				lux.previous_room_setter(&room15);
				break;
			case 16:
				lux.previous_room_setter(&room16);
				break;
			}

			//���a�D��
			ss.str("");
			ss.clear();
			getline(inStream, s);
			ss << s;
			string item_name;
			while (ss >> item_name) {
				if (item_name == "Amplifying_Tome(�W�T���y)") { lux.getitem(Amplifying_Tome); }
				else if (item_name == "Null-Magic-Mantle(���]���O)") { lux.getitem(Null_Magic_Mantle); }
				else if (item_name == "ruby_crystal(������)") { lux.getitem(Ruby_crystal); }
				else if (item_name == "Blasting_wand(�z���]��)") { lux.getitem(Blasting_wand); }
				else if (item_name == "Void_staff(��Ť���)") { lux.getitem(Void_staff); }
				else if (item_name == "Cloth_Armor(����)") { lux.getitem(Cloth_Armor); }
				else if (item_name == "giant��s_belt(���H�y�a)") { lux.getitem(Giant_belt); }
				else if (item_name == "needlessly_large rod(�L�Τ���)") { lux.getitem(Needlessly_large_rod); }
			}

			//NPC--�Ť�B�ɰǴ��Bnpc_for_nothing���Ӥ��ΡC�]�u�n�ݳQ���_�CAatrox�BZoe�BGromp�BKrugs�BWolve�B Raptor
			ss.str("");
			ss.clear();
			getline(inStream, s);

			ss << s;
			ss >> num;
			if (num == 1) { Aatrox.set_have_killed(1); }
			else { Aatrox.set_have_killed(0); }
			ss >> num;
			if (num == 1) { Zoe.set_have_killed(1); }
			else { Zoe.set_have_killed(0); }
			ss >> num;
			if (num == 1) { Gromp.set_have_killed(1); }
			else { Gromp.set_have_killed(0); }
			ss >> num;
			if (num == 1) { Krugs.set_have_killed(1); }
			else { Krugs.set_have_killed(0); }
			ss >> num;
			if (num == 1) { Wolve.set_have_killed(1); }
			else { Wolve.set_have_killed(0); }
			ss >> num;
			if (num == 1) { Raptor.set_have_killed(1); }
			else { Raptor.set_have_killed(0); }


			//��while(!inStream.eof()) { cout << next; inStream.get(next);	}��Ū��
			//������stringŪ���A�b�j���૬��int�n�F�A�٥i�H�򥦥W�[���A���N�i�H��while(inStream>>string){...}
			//stringstream�n���]�i�H?
			inStream.close();
		}
		catch (string s) {
			std::cout << s;
			system("pause");
			save_and_load(lux);
		}
		return 0;
	}
	else if (num == 2) {//�s�C��
		lux.blood_setter(1500 - lux.get_blood());
		lux.attack_coffi_setter(200 - lux.get_attack_coffi());
		lux.defense_coffi_setter(100 - lux.get_defense_coffi());
		lux.health_setter(1500 - lux.get_health());
		(*lux.item_getter()).clear();//�R���Ҧ��˳ơA���n���S�����\

		//�Q�����Ǫ��n���^�ӣt
		Aatrox.set_have_killed(0);
		Zoe.set_have_killed(0);
		Gromp.set_have_killed(0);
		Krugs.set_have_killed(0);
		Wolve.set_have_killed(0);
		Raptor.set_have_killed(0);

		//�i�S�i�L���ж��]�n��
		room1.have_entered_setter(0);
		room3.have_entered_setter(0);
		room4.have_entered_setter(0);
		room5.have_entered_setter(0);
		room6.have_entered_setter(0);
		room7.have_entered_setter(0);
		room9.have_entered_setter(0);
		room10.have_entered_setter(0);
		room11.have_entered_setter(0);
		room12.have_entered_setter(0);
		room13.have_entered_setter(0);
		room14.have_entered_setter(0);
		room15.have_entered_setter(0);
		room16.have_entered_setter(0);

		std::cout << story1;
		std::system("pause");
		std::system("cls");
		//�C�������}�l
		lux.previous_room_setter(&room1);
		lux.current_room_setter(&room1);
		room1.have_entered_setter(1);
		std::cout << lux.get_current_room()->get_own_npc()->get_story();
		std::system("pause");
		lux.getitem(Amplifying_Tome);
		lux.equip_item(Amplifying_Tome);

		return 0;
	}
	else {//�s��
		ofstream outStream;
		outStream.open("file.txt");
		if (outStream.fail()) {
			std::cout << "File write failed.\n";
			exit(1);
		}
		//�ж��A�u�n�O�o�O�_�w�g�i�L�ж��N�i�H�F�A�O�oroom2�Broom8���s�b
		outStream << room1.get_have_entered() << " " << room3.get_have_entered() << " " << room4.get_have_entered() << " " << room5.get_have_entered() << " "
			<< room6.get_have_entered() << " " << room7.get_have_entered() << " " << room9.get_have_entered() << " " << room10.get_have_entered() << " "
			<< room11.get_have_entered() << " " << room12.get_have_entered() << " " << room13.get_have_entered() << " " << room14.get_have_entered() << " "
			<< room15.get_have_entered() << " " << room16.get_have_entered() << "\n";
		//���a�A��q�B�����O�B���m�O�B���d�B���b�ж��B�W�өж��B���A����A�֦����~�C�����D���Ф���L�X�ӡA�Y�^�h���S����??
		outStream << lux.get_blood() << " " << lux.get_attack_coffi() << " " << lux.get_defense_coffi() << " " << lux.get_health() << " "
			<< lux.get_current_room()->get_index() << " " << lux.get_previous_room()->get_index() << "\n";
		for (const auto& i : *lux.item_getter()) {//�L�W�٦Ӥw
			outStream << i.get_name() << " ";
		}
		outStream << "\n";
		//NPC�A�n�`�N��q��O�_�H���ӥH�t�A�Ť�B�ɰǴ��Bnpc_for_nothing���Ӥ��ΡC���Q���_�A�A��q�CAatrox�BZoe�BGromp�BKrugs�BWolve�B Raptor
		outStream << Aatrox.get_have_killed() << " " << Zoe.get_have_killed() << " " << Gromp.get_have_killed() << " " << Krugs.get_have_killed() << " "
			<< Wolve.get_have_killed() << " " << Raptor.get_have_killed() << "\n";
		//item�A�n������? ����

		outStream.close();
		std::cout << "���b�s�ɽеy��...\n\n";
		return 0;
	}
	return 0;
}

void print_info(Object* obj) {
	if (Item* iptr = dynamic_cast<Item*>(obj)) { cout << iptr->get_info(); }
	else if (Player* pptr = dynamic_cast<Player*>(obj)) { cout << pptr->get_info(); }
	else if (NPC* nptr = dynamic_cast<NPC*>(obj)) { cout << nptr->get_info(); }
	else {
		cout << "wrong function input";
		exit(1);
	}
}