#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Bag.h"

using namespace std;

Bag::Bag():gold(0){}//构造函数

Goods& Bag::get_goods(int serial_number) { return goods[serial_number]; }//获得物品

int Bag::get_gold() const { return gold; }//获得金币

bool Bag::put_in(Goods& goods0)//放入物品
{
	for (int i = 0; i < 30; i++)
	{
		if (goods[i].get_name() == "无")
		{
			goods[i] = goods0;
			return true;
		}
	}

	return false;
}

bool Bag::take_out(Goods& goods0)//取出物品
{
	for (int i = 0; i < 30; i++)
	{
		if (goods[i] == goods0)
		{
			goods[i] = Goods("无");
			return true;
		}
	}

	return false;
}

void Bag::change_gold(int gold0)//改变金币
{
	gold=gold+gold0;
}

void Bag::show() const//显示信息
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
		if (goods[i].get_name() == "青锋剑")
			w1_number++;
		else if (goods[i].get_name() == "游龙剑")
			w2_number++;
		else if (goods[i].get_name() == "灵犀神剑")
			w3_number++;

		else if (goods[i].get_name() == "赤鳞甲")
			a1_number++;
		else if (goods[i].get_name() == "白玉龙甲")
			a2_number++;
		else if (goods[i].get_name() == "紫金磐龙甲")
			a3_number++;

		else if (goods[i].get_name() == "血气丹")
			e1_number++;
		else if (goods[i].get_name() == "复灵紫丹")
			e2_number++;
		else if (goods[i].get_name() == "九转还魂丹")
			e3_number++;

	}

	Goods goods0("无");
	int number = 0;

	cout << "您的背包：" << endl;
	cout << setiosflags(ios_base::left) << setw(15) << "物品" << setw(10) << "类型" << setw(10) << "数量" << setw(10) << "总价值" << endl;
	for (int i = 1; i <= 9; i++)
	{
		if (i == 1)
		{
			goods0 = Goods("青锋剑");
			number = w1_number;
		}
		else if (i == 2)
		{
			goods0 = Goods("游龙剑");
			number = w2_number;
		}
		else if (i == 3)
		{
			goods0 = Goods("灵犀神剑");
			number = w3_number;
		}

		else if (i == 4)
		{
			goods0 = Goods("赤鳞甲");
			number = a1_number;

		}
		else if (i == 5)
		{
			goods0 = Goods("白玉龙甲");
			number = a2_number;
		}
		else if (i == 6)
		{
			goods0 = Goods("紫金磐龙甲");
			number = a3_number;
		}

		else if (i == 7)
		{
			goods0 = Goods("血气丹");
			number = e1_number;
		}
		else if (i == 8)
		{
			goods0 = Goods("复灵紫丹");
			number = e2_number;
		}
		else
		{
			goods0 = Goods("九转还魂丹");
			number = e3_number;
		}

		cout <<setiosflags(ios_base::left) << setw(15) << goods0.get_name() <<setw(10)<< goods0.get_type() << setw(10) << number << setw(10) << goods0.get_price()*number <<endl;
	}
	cout << setiosflags(ios_base::left) << setw(15) << "金币" << setw(10) << "货币" << setw(10) << gold << setw(10) << gold << endl;
	cout << endl;
}

istream& operator >>(istream& in, Bag& bag0)//重载>>运算符（友元函数）
{
	for (int i = 0; i < 30; i++)
		in >> bag0.goods[i];
	in >> bag0.gold;
	return in;
}

ostream& operator <<(ostream& out, const Bag& bag0)//重载<<运算符（友元函数）
{
	for (int i = 0; i < 30; i++)
		out << bag0.goods[i] <<" ";
	out << bag0.gold <<" ";
	return out;
}