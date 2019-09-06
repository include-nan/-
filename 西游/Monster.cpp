#include  <iostream>
#include "Monster.h"

using namespace std;

Monster::Monster(string name0):Role(name0), lose_gold(0), lose_experience(0)//构造函数
{
	start();
}

void Monster::start()//初始
{
	if (name == "黑熊精")
	{
		max_health_points = 2000;
		basic_attack_power = 400;
		basic_defensive_power = 200;
		lose_gold = 300;
		lose_experience = 1000;
		location = "黑风山黑风洞";
	}

	else if (name == "黄风怪")
	{
		max_health_points = 2400;
		basic_attack_power = 660;
		basic_defensive_power = 330;
		lose_gold = 500;
		lose_experience = 2000;
		location = "黄风岭黄风洞";
	}

	else if (name == "白骨夫人")
	{
		max_health_points = 3700;
		basic_attack_power = 850;
		basic_defensive_power = 500;
		lose_gold = 1000;
		lose_experience = 5000;
		location = "骷髅山白骨洞";
	}

	else if (name == "圣婴大王")
	{
		max_health_points = 4000;
		basic_attack_power = 900;
		basic_defensive_power = 550;
		lose_gold = 1100;
		lose_experience = 6000;
		location = "号山枯松涧火云洞";
	}

	else if (name == "蝎女妖")
	{
		max_health_points = 8000;
		basic_attack_power = 1400;
		basic_defensive_power = 1000;
		lose_gold = 2500;
		lose_experience = 9000;
		location = "毒敌山琵琶洞";
	}

	else if (name == "六耳猕猴")
	{
		max_health_points = 6600;
		basic_attack_power = 1000;
		basic_defensive_power = 650;
		lose_gold = 1500;
		lose_experience = 7000;
		location = "花果山水帘洞";
	}

	else if (name == "黄眉老祖")
	{
		max_health_points = 5500;
		basic_attack_power = 1000;
		basic_defensive_power = 750;
		lose_gold = 2000;
		lose_experience = 8000;
		location = "小西天小雷音寺";
	}

	else if (name == "地涌夫人")
	{
		max_health_points = 3200;
		basic_attack_power = 810;
		basic_defensive_power = 420;
		lose_gold = 900;
		lose_experience = 4000;
		location = "陷空山无底洞";
	}

	else
	{
		max_health_points = 2500;
		basic_attack_power = 720;
		basic_defensive_power = 360;
		lose_gold = 700;
		lose_experience = 3000;
		location = "毛颖山狡兔三穴";
	}

	health_points = max_health_points;
	attack_power = basic_attack_power;
	defensive_power = basic_defensive_power;
}

int Monster::get_lose_gold() const { return lose_gold; }//获得掉落金币

int Monster::get_lose_experience() const { return lose_experience; }//获得掉落经验

void Monster::show() const//显示信息
{
	Role::show();
	cout << "掉落金币：" << lose_gold << endl;
	cout << "掉落经验：" << lose_experience << endl;
	cout << endl;
}

void Monster::attack(Hero& hero)//攻击
{
	int damage_value = attack_power - hero.get_defensive_power();

	int true_damage_value = damage_value > 0 ? damage_value : 0;

	hero.change_health_points(-true_damage_value);
	cout << "妖怪对您造成了" << true_damage_value << "伤害" << endl;
	cout << endl;
}
