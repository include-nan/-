#include  <iostream>
#include <fstream>
#include "Goods.h"

using namespace std;

Goods::Goods(string name0) :name(name0),type("��"),effect(0),price(0)//���캯��
{
	if (name == "��潣")
	{
		type = "����";
		effect = 200;
		price = 1500;
	}
	else if (name == "������")
	{
		type = "����";
		effect = 350;
		price = 3500;
	}
	else if (name == "��Ϭ��")
	{
		type = "����";
		effect = 600;
		price = 8000;
	}

	else if (name == "���ۼ�")
	{
		type = "����";
		effect = 170;
		price = 1500;
	}
	else if (name == "��������")
	{
		type = "����";
		effect = 220;
		price = 3500;
	}
	else if (name == "�Ͻ�������")
	{
		type = "����";
		effect = 350;
		price = 8000;
	}

	else if (name == "Ѫ����")
	{
		type = "��ҩ";
		effect = 600;
		price = 100;
	}
	else if (name == "�����ϵ�")
	{
		type = "��ҩ";
		effect = 2000;
		price = 300;
	}
	else if (name == "��ת���굤")
	{
		type = "��ҩ";
		effect = 3300;
		price = 500;
	}

	else
	{
		type = "��";
		effect = 0;
		price = 0;
	}
}

bool Goods::operator==(Goods& goods) const//����==�����
{
	if (name == goods.get_name())
		return true;
	else
		return false;
}

string Goods::get_name() const { return name; }//�������

string Goods::get_type() const { return type; }//�������

int Goods::get_effect() const { return effect; }//���Ч��

int Goods::get_price() const { return price; }//��ü۸�

void Goods::show() const//��ʾ��Ϣ
{
	if (name != "��")
	{
		cout << "��Ʒ��" << name << endl;
		cout << "���ͣ�"<< type <<endl;
		cout << "Ч����"<< effect <<endl;
		cout << "�۸�"<<price<<endl;
		cout << endl;
	}
}

istream& operator >>(istream& in, Goods& goods0)//����>>���������Ԫ������
{
	in >> goods0.name >> goods0.type >> goods0.effect >> goods0.price;
	return in;
}

ostream& operator <<(ostream& out, const Goods& goods0)//����<<���������Ԫ������
{
	out << goods0.name << " " << goods0.type << " " << goods0.effect << " " << goods0.price << " ";
	return out;
}
