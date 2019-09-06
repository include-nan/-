#include  <iostream>
#include "Monster.h"

using namespace std;

Monster::Monster(string name0):Role(name0), lose_gold(0), lose_experience(0)//���캯��
{
	start();
}

void Monster::start()//��ʼ
{
	if (name == "���ܾ�")
	{
		max_health_points = 2000;
		basic_attack_power = 400;
		basic_defensive_power = 200;
		lose_gold = 300;
		lose_experience = 1000;
		location = "�ڷ�ɽ�ڷ綴";
	}

	else if (name == "�Ʒ��")
	{
		max_health_points = 2400;
		basic_attack_power = 660;
		basic_defensive_power = 330;
		lose_gold = 500;
		lose_experience = 2000;
		location = "�Ʒ���Ʒ綴";
	}

	else if (name == "�׹Ƿ���")
	{
		max_health_points = 3700;
		basic_attack_power = 850;
		basic_defensive_power = 500;
		lose_gold = 1000;
		lose_experience = 5000;
		location = "����ɽ�׹Ƕ�";
	}

	else if (name == "ʥӤ����")
	{
		max_health_points = 4000;
		basic_attack_power = 900;
		basic_defensive_power = 550;
		lose_gold = 1100;
		lose_experience = 6000;
		location = "��ɽ���ɽ����ƶ�";
	}

	else if (name == "ЫŮ��")
	{
		max_health_points = 8000;
		basic_attack_power = 1400;
		basic_defensive_power = 1000;
		lose_gold = 2500;
		lose_experience = 9000;
		location = "����ɽ���ö�";
	}

	else if (name == "����⨺�")
	{
		max_health_points = 6600;
		basic_attack_power = 1000;
		basic_defensive_power = 650;
		lose_gold = 1500;
		lose_experience = 7000;
		location = "����ɽˮ����";
	}

	else if (name == "��ü����")
	{
		max_health_points = 5500;
		basic_attack_power = 1000;
		basic_defensive_power = 750;
		lose_gold = 2000;
		lose_experience = 8000;
		location = "С����С������";
	}

	else if (name == "��ӿ����")
	{
		max_health_points = 3200;
		basic_attack_power = 810;
		basic_defensive_power = 420;
		lose_gold = 900;
		lose_experience = 4000;
		location = "�ݿ�ɽ�޵׶�";
	}

	else
	{
		max_health_points = 2500;
		basic_attack_power = 720;
		basic_defensive_power = 360;
		lose_gold = 700;
		lose_experience = 3000;
		location = "ëӱɽ������Ѩ";
	}

	health_points = max_health_points;
	attack_power = basic_attack_power;
	defensive_power = basic_defensive_power;
}

int Monster::get_lose_gold() const { return lose_gold; }//��õ�����

int Monster::get_lose_experience() const { return lose_experience; }//��õ��侭��

void Monster::show() const//��ʾ��Ϣ
{
	Role::show();
	cout << "�����ң�" << lose_gold << endl;
	cout << "���侭�飺" << lose_experience << endl;
	cout << endl;
}

void Monster::attack(Hero& hero)//����
{
	int damage_value = attack_power - hero.get_defensive_power();

	int true_damage_value = damage_value > 0 ? damage_value : 0;

	hero.change_health_points(-true_damage_value);
	cout << "���ֶ��������" << true_damage_value << "�˺�" << endl;
	cout << endl;
}
