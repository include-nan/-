#ifndef MONSTER_H
#define MONSTER_H

#include "Role.h"
#include "Hero.h"

class Hero;

class Monster:public Role
{
private:
	int lose_gold;                   //������
	int lose_experience;             //���侭��

public:
	Monster (string name0="���ܾ�");  //���캯��
	void start();                    //��ʼ
	int get_lose_gold() const;       //��õ�����
	int get_lose_experience() const; //��õ��侭��
	void show() const;               //��ʾ��Ϣ
	void attack(Hero& hero);         //����
};

#endif // !MONSTER_H