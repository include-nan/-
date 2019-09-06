#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Bag.h"

using namespace std;

Bag::Bag():gold(0){}//���캯��

Goods& Bag::get_goods(int serial_number) { return goods[serial_number]; }//�����Ʒ

int Bag::get_gold() const { return gold; }//��ý��

bool Bag::put_in(Goods& goods0)//������Ʒ
{
	for (int i = 0; i < 30; i++)
	{
		if (goods[i].get_name() == "��")
		{
			goods[i] = goods0;
			return true;
		}
	}

	return false;
}

bool Bag::take_out(Goods& goods0)//ȡ����Ʒ
{
	for (int i = 0; i < 30; i++)
	{
		if (goods[i] == goods0)
		{
			goods[i] = Goods("��");
			return true;
		}
	}

	return false;
}

void Bag::change_gold(int gold0)//�ı���
{
	gold=gold+gold0;
}

void Bag::show() const//��ʾ��Ϣ
{
	int w1_number = 0;
	int w2_number = 0;
	int w3_number = 0;

	int a1_number = 0;
	int a2_number = 0;
	int a3_number = 0;

	int e1_number = 0;
	int e2_number = 0;
	int e3_number = 0;

	for (int i = 0; i < 30; i++)
	{
		if (goods[i].get_name() == "��潣")
			w1_number++;
		else if (goods[i].get_name() == "������")
			w2_number++;
		else if (goods[i].get_name() == "��Ϭ��")
			w3_number++;

		else if (goods[i].get_name() == "���ۼ�")
			a1_number++;
		else if (goods[i].get_name() == "��������")
			a2_number++;
		else if (goods[i].get_name() == "�Ͻ�������")
			a3_number++;

		else if (goods[i].get_name() == "Ѫ����")
			e1_number++;
		else if (goods[i].get_name() == "�����ϵ�")
			e2_number++;
		else if (goods[i].get_name() == "��ת���굤")
			e3_number++;

	}

	Goods goods0("��");
	int number = 0;

	cout << "���ı�����" << endl;
	cout << setiosflags(ios_base::left) << setw(15) << "��Ʒ" << setw(10) << "����" << setw(10) << "����" << setw(10) << "�ܼ�ֵ" << endl;
	for (int i = 1; i <= 9; i++)
	{
		if (i == 1)
		{
			goods0 = Goods("��潣");
			number = w1_number;
		}
		else if (i == 2)
		{
			goods0 = Goods("������");
			number = w2_number;
		}
		else if (i == 3)
		{
			goods0 = Goods("��Ϭ��");
			number = w3_number;
		}

		else if (i == 4)
		{
			goods0 = Goods("���ۼ�");
			number = a1_number;

		}
		else if (i == 5)
		{
			goods0 = Goods("��������");
			number = a2_number;
		}
		else if (i == 6)
		{
			goods0 = Goods("�Ͻ�������");
			number = a3_number;
		}

		else if (i == 7)
		{
			goods0 = Goods("Ѫ����");
			number = e1_number;
		}
		else if (i == 8)
		{
			goods0 = Goods("�����ϵ�");
			number = e2_number;
		}
		else
		{
			goods0 = Goods("��ת���굤");
			number = e3_number;
		}

		cout <<setiosflags(ios_base::left) << setw(15) << goods0.get_name() <<setw(10)<< goods0.get_type() << setw(10) << number << setw(10) << goods0.get_price()*number <<endl;
	}
	cout << setiosflags(ios_base::left) << setw(15) << "���" << setw(10) << "����" << setw(10) << gold << setw(10) << gold << endl;
	cout << endl;
}

istream& operator >>(istream& in, Bag& bag0)//����>>���������Ԫ������
{
	for (int i = 0; i < 30; i++)
		in >> bag0.goods[i];
	in >> bag0.gold;
	return in;
}

ostream& operator <<(ostream& out, const Bag& bag0)//����<<���������Ԫ������
{
	for (int i = 0; i < 30; i++)
		out << bag0.goods[i] <<" ";
	out << bag0.gold <<" ";
	return out;
}