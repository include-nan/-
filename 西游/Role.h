#ifndef ROLE_H
#define ROLE_H

#include <string>

using namespace std;

class Role
{
protected:
	string name;
	int max_health_points;                             //�������ֵ
	int basic_attack_power;                            //����������
	int basic_defensive_power;                         //����������
	int health_points;                                 //��ǰ����ֵ
	int attack_power;                                  //��ǰ������
	int defensive_power;                               //��ǰ������
	string location;                                   //λ��

public:
	Role(string name0);                                //���캯��
	void start();                                      //��ʼ
	bool operator ==(Role& role) const;                //����==�����
	string get_name() const;                           //�������
	int get_max_health_points() const;                 //����������ֵ
	int get_basic_attack_power() const;                //��û���������
	int get_basic_defensive_power() const;             //��û���������
	int get_health_points() const;                     //��õ�ǰ����ֵ
	int get_attack_power() const;                      //��õ�ǰ������
	int get_defensive_power() const;                   //��õ�ǰ������
	string get_location() const;                       //���λ��
	void change_health_points(int health_points0);     //�ı�����ֵ
	void change_attack_power(int attack_power0);       //�ı乥����
	void change_defensive_power(int defensive_power0); //�ı������
	void introduction() const;                         //��ɫ���
	void show() const;                                 //��ʾ��Ϣ
	virtual void attack(Role& role0);                  //����
};

#endif // !ROLE_H