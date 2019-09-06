#ifndef GOODS_H
#define GOODS_H

#include <string>

using namespace std;

class Goods
{
private:
	string name;                                                    //名字
	string type;                                                    //类型（无/武器/护甲/丹药）
	int effect;                                                     //效果
	int price;                                                      //价格

public:
	Goods(string name0="无");                                       //构造函数
	bool operator ==(Goods& goods) const;                           //重载==运算符
	string get_name() const;                                        //获得名字
	string get_type() const;                                        //获得类型
	int get_effect() const;                                         //获得效果
	int get_price() const;                                          //获得价格
	void show() const;                                              //显示信息
	friend istream& operator >>(istream& in, Goods& goods0);        //友元函数
	friend ostream& operator <<(ostream& out, const Goods& goods0); //友元函数
	friend class Bag;                                               //声明Bag为Goods的友元类
};

istream& operator >>(istream& in, Goods& goods0);                   //重载>>运算符
ostream& operator <<(ostream& out, const Goods& goods0);            //重载>>运算符

#endif // !GOODS_H