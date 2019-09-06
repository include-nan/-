#ifndef MONSTER_H
#define MONSTER_H

#include "Role.h"
#include "Hero.h"

class Hero;

class Monster:public Role
{
private:
	int lose_gold;                   //掉落金币
	int lose_experience;             //掉落经验

public:
	Monster (string name0="黑熊精");  //构造函数
	void start();                    //初始
	int get_lose_gold() const;       //获得掉落金币
	int get_lose_experience() const; //获得掉落经验
	void show() const;               //显示信息
	void attack(Hero& hero);         //攻击
};

#endif // !MONSTER_H