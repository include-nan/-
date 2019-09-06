#ifndef HERO_H
#define HERO_H

#include "Goods.h"
#include "Bag.h"
#include "Store.h"
#include "Role.h"
#include "Monster.h"

class Monster;

class Hero:public Role
{
private:
	int experience;                                      //����ֵ
	int level;                                           //�ȼ�
	Goods what_weapon;                                   //����
	Goods what_armor;                                    //����
	Bag bag;                                             //����
	bool barrier[10];                                    //�Ƿ�ͨ���ؿ�
	bool if_file;                                        //�Ƿ���ļ�

public:
	Hero(string name0="������",bool if_file0=true);       //���캯����������
	void start();                                        //��ʼ
	int get_experience() const;                          //��þ���ֵ
	int get_level() const;                               //��õȼ�
	Goods& get_what_weapon();                            //�������
	Goods& get_what_armor();                             //��û���
	Bag& get_bag();                                      //��ñ���
	void show_barrier() const;                           //��ʾ��ͨ����δͨ���ؿ�
	void show() const;                                   //��ʾ��Ϣ
	bool if_weapon() const;                              //�ж���û��װ������
	bool if_armor() const;                               //�ж���û��װ������
	bool if_success() const;                             //�ж��Ƿ�ͨ�سɹ�
	void reward(int min1, int max1, int min2, int max2); //����/���壨min1-max1 Ϊ�������䣬min2-max2Ϊ�ͷ����䣩
	void travel();                                       //��·
	void add_experience(int experience0);                //��������ֵ
	void add_gold(int gold0);                            //���ӽ��
	void buy(Store& store);                              //������Ʒ
	void sell(Store& store);                             //������Ʒ
	void put_on();                                       //װ����Ʒ
	void take_off();                                     //ж����Ʒ
	void take();                                         //���õ�ҩ
	void change_barrier(Monster& monster);               //�ı���ͨ����δͨ���ؿ�
	void attack(Monster& monster0);                      //����
	bool pay();                                          //���Ѹ���
	void fight();                                        //ս��
	void read_file();                                    //���ļ�
	void write_file();                                   //д�ļ�
	~Hero();                                             //�����������浵��
};

#endif // !HERO_H