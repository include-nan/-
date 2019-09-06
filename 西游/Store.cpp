#include  <iostream>
#include <iomanip>
#include "Store.h"

using namespace std;

Store::Store()//���캯��
{
	goods[0] = Goods("��");
	goods[1] = Goods("��潣");
	goods[2] = Goods("������");
	goods[3] = Goods("��Ϭ��");
	goods[4] = Goods("���ۼ�");
	goods[5] = Goods("��������");
	goods[6] = Goods("�Ͻ�������");
	goods[7] = Goods("Ѫ����");
	goods[8] = Goods("�����ϵ�");
	goods[9] = Goods("��ת���굤");
}

Goods& Store::get_goods(int serial_number) { return goods[serial_number]; }//�����Ʒ

void Store::show() const//��ʾ��Ϣ
{
	cout << setiosflags(ios_base::left) <<setw(15) << "��Ʒ" << setw(10)  << "����" << setw(10) <<  "Ч��" << setw(10) << "�۸�" << endl;
	for (int i = 1; i <= 9; i++)
		cout << setiosflags(ios_base::left) << setw(15) << goods[i].get_name() << setw(10) << goods[i].get_type() << setw(10) << goods[i].get_effect() << setw(10) << goods[i].get_price() << endl;
	cout << endl;
}
