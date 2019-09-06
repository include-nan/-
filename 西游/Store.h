#ifndef STORE_H
#define STORE_H

#include "Goods.h"

class Store
{
private:
	Goods goods[10];                     //商品
public:
	Store();                             //构造函数
	Goods& get_goods(int serial_number); //获得物品
	void show() const;                   //显示信息
};

#endif // !STORE_H