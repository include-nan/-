#ifndef STORE_H
#define STORE_H

#include "Goods.h"

class Store
{
private:
	Goods goods[10];                     //��Ʒ
public:
	Store();                             //���캯��
	Goods& get_goods(int serial_number); //�����Ʒ
	void show() const;                   //��ʾ��Ϣ
};

#endif // !STORE_H