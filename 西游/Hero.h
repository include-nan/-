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
	int experience;                                      //经验值
	int level;                                           //等级
	Goods what_weapon;                                   //武器
	Goods what_armor;                                    //护甲
	Bag bag;                                             //背包
	bool barrier[10];                                    //是否通过关卡
	bool if_file;                                        //是否读文件

public:
	Hero(string name0="唐三藏",bool if_file0=true);       //构造函数（读档）
	void start();                                        //初始
	int get_experience() const;                          //获得经验值
	int get_level() const;                               //获得等级
	Goods& get_what_weapon();                            //获得武器
	Goods& get_what_armor();                             //获得护甲
	Bag& get_bag();                                      //获得背包
	void show_barrier() const;                           //显示已通过和未通过关卡
	void show() const;                                   //显示信息
	bool if_weapon() const;                              //判断有没有装备武器
	bool if_armor() const;                               //判断有没有装备护甲
	bool if_success() const;                             //判断是否通关成功
	void reward(int min1, int max1, int min2, int max2); //宝箱/陷阱（min1-max1 为奖励区间，min2-max2为惩罚区间）
	void travel();                                       //赶路
	void add_experience(int experience0);                //提升经验值
	void add_gold(int gold0);                            //增加金币
	void buy(Store& store);                              //购买物品
	void sell(Store& store);                             //出售物品
	void put_on();                                       //装备物品
	void take_off();                                     //卸下物品
	void take();                                         //服用丹药
	void change_barrier(Monster& monster);               //改变已通过和未通过关卡
	void attack(Monster& monster0);                      //攻击
	bool pay();                                          //付费复活
	void fight();                                        //战斗
	void read_file();                                    //读文件
	void write_file();                                   //写文件
	~Hero();                                             //析构函数（存档）
};

#endif // !HERO_H