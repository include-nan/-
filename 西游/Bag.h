#ifndef BAG_H
#define BAG_H

#include "Goods.h"

using namespace std;

class Bag
{
private:
	Goods goods[30];                                            //物品
	int gold;                                                   //金币

public:
	Bag();                                                      //构造函数
	Goods& get_goods(int serial_number);                        //获得物品
	int get_gold() const ;                                      //获得金币
	bool put_in(Goods& goods0);                                 //放入物品
	bool take_out(Goods& goods0);                               //取出物品
	void change_gold(int gold0);                                //改变金币
	void show() const;                                          //显示信息
	friend istream& operator >>(istream& in, Bag& bag0);        //友元函数
	friend ostream& operator <<(ostream& out, const Bag& bag0); //友元函数
};

istream& operator >>(istream& in, Bag& bag0);                   //重载>>运算符
ostream& operator <<(ostream& out, const Bag& bag0);            //重载>>运算符


#endif // !BAG_H