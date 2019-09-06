#ifndef BAG_H
#define BAG_H

#include "Goods.h"

using namespace std;

class Bag
{
private:
	Goods goods[30];                                            //��Ʒ
	int gold;                                                   //���

public:
	Bag();                                                      //���캯��
	Goods& get_goods(int serial_number);                        //�����Ʒ
	int get_gold() const ;                                      //��ý��
	bool put_in(Goods& goods0);                                 //������Ʒ
	bool take_out(Goods& goods0);                               //ȡ����Ʒ
	void change_gold(int gold0);                                //�ı���
	void show() const;                                          //��ʾ��Ϣ
	friend istream& operator >>(istream& in, Bag& bag0);        //��Ԫ����
	friend ostream& operator <<(ostream& out, const Bag& bag0); //��Ԫ����
};

istream& operator >>(istream& in, Bag& bag0);                   //����>>�����
ostream& operator <<(ostream& out, const Bag& bag0);            //����>>�����


#endif // !BAG_H