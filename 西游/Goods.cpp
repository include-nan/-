#include  <iostream>
#include <fstream>
#include "Goods.h"

using namespace std;

Goods::Goods(string name0) :name(name0),type("无"),effect(0),price(0)//构造函数
{
	if (name == "青锋剑")
	{
		type = "武器";
		effect = 200;
		price = 1500;
	}
	else if (name == "游龙剑")
	{
		type = "武器";
		effect = 350;
		price = 3500;
	}
	else if (name == "灵犀神剑")
	{
		type = "武器";
		effect = 600;
		price = 8000;
	}

	else if (name == "赤鳞甲")
	{
		type = "护甲";
		effect = 170;
		price = 1500;
	}
	else if (name == "白玉龙甲")
	{
		type = "护甲";
		effect = 220;
		price = 3500;
	}
	else if (name == "紫金磐龙甲")
	{
		type = "护甲";
		effect = 350;
		price = 8000;
	}

	else if (name == "血气丹")
	{
		type = "丹药";
		effect = 600;
		price = 100;
	}
	else if (name == "复灵紫丹")
	{
		type = "丹药";
		effect = 2000;
		price = 300;
	}
	else if (name == "九转还魂丹")
	{
		type = "丹药";
		effect = 3300;
		price = 500;
	}

	else
	{
		type = "无";
		effect = 0;
		price = 0;
	}
}

bool Goods::operator==(Goods& goods) const//重载==运算符
{
	if (name == goods.get_name())
		return true;
	else
		return false;
}

string Goods::get_name() const { return name; }//获得名字

string Goods::get_type() const { return type; }//获得类型

int Goods::get_effect() const { return effect; }//获得效果

int Goods::get_price() const { return price; }//获得价格

void Goods::show() const//显示信息
{
	if (name != "无")
	{
		cout << "物品：" << name << endl;
		cout << "类型："<< type <<endl;
		cout << "效果："<< effect <<endl;
		cout << "价格："<<price<<endl;
		cout << endl;
	}
}

istream& operator >>(istream& in, Goods& goods0)//重载>>运算符（友元函数）
{
	in >> goods0.name >> goods0.type >> goods0.effect >> goods0.price;
	return in;
}

ostream& operator <<(ostream& out, const Goods& goods0)//重载<<运算符（友元函数）
{
	out << goods0.name << " " << goods0.type << " " << goods0.effect << " " << goods0.price << " ";
	return out;
}
