#include  <iostream>
#include <iomanip>
#include "Store.h"

using namespace std;

Store::Store()//构造函数
{
	goods[0] = Goods("空");
	goods[1] = Goods("青锋剑");
	goods[2] = Goods("游龙剑");
	goods[3] = Goods("灵犀神剑");
	goods[4] = Goods("赤鳞甲");
	goods[5] = Goods("白玉龙甲");
	goods[6] = Goods("紫金磐龙甲");
	goods[7] = Goods("血气丹");
	goods[8] = Goods("复灵紫丹");
	goods[9] = Goods("九转还魂丹");
}

Goods& Store::get_goods(int serial_number) { return goods[serial_number]; }//获得物品

void Store::show() const//显示信息
{
	cout << setiosflags(ios_base::left) <<setw(15) << "物品" << setw(10)  << "类型" << setw(10) <<  "效果" << setw(10) << "价格" << endl;
	for (int i = 1; i <= 9; i++)
		cout << setiosflags(ios_base::left) << setw(15) << goods[i].get_name() << setw(10) << goods[i].get_type() << setw(10) << goods[i].get_effect() << setw(10) << goods[i].get_price() << endl;
	cout << endl;
}
