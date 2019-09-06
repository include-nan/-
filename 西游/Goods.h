#ifndef GOODS_H
#define GOODS_H

#include <string>

using namespace std;

class Goods
{
private:
	string name;                                                    //����
	string type;                                                    //���ͣ���/����/����/��ҩ��
	int effect;                                                     //Ч��
	int price;                                                      //�۸�

public:
	Goods(string name0="��");                                       //���캯��
	bool operator ==(Goods& goods) const;                           //����==�����
	string get_name() const;                                        //�������
	string get_type() const;                                        //�������
	int get_effect() const;                                         //���Ч��
	int get_price() const;                                          //��ü۸�
	void show() const;                                              //��ʾ��Ϣ
	friend istream& operator >>(istream& in, Goods& goods0);        //��Ԫ����
	friend ostream& operator <<(ostream& out, const Goods& goods0); //��Ԫ����
	friend class Bag;                                               //����BagΪGoods����Ԫ��
};

istream& operator >>(istream& in, Goods& goods0);                   //����>>�����
ostream& operator <<(ostream& out, const Goods& goods0);            //����>>�����

#endif // !GOODS_H