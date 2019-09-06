#ifndef ROLE_H
#define ROLE_H

#include <string>

using namespace std;

class Role
{
protected:
	string name;
	int max_health_points;                             //最大生命值
	int basic_attack_power;                            //基础攻击力
	int basic_defensive_power;                         //基础防御力
	int health_points;                                 //当前生命值
	int attack_power;                                  //当前攻击力
	int defensive_power;                               //当前防御力
	string location;                                   //位置

public:
	Role(string name0);                                //构造函数
	void start();                                      //初始
	bool operator ==(Role& role) const;                //重载==运算符
	string get_name() const;                           //获得名字
	int get_max_health_points() const;                 //获得最大生命值
	int get_basic_attack_power() const;                //获得基础攻击力
	int get_basic_defensive_power() const;             //获得基础防御力
	int get_health_points() const;                     //获得当前生命值
	int get_attack_power() const;                      //获得当前攻击力
	int get_defensive_power() const;                   //获得当前防御力
	string get_location() const;                       //获得位置
	void change_health_points(int health_points0);     //改变生命值
	void change_attack_power(int attack_power0);       //改变攻击力
	void change_defensive_power(int defensive_power0); //改变防御力
	void introduction() const;                         //角色简介
	void show() const;                                 //显示信息
	virtual void attack(Role& role0);                  //攻击
};

#endif // !ROLE_H