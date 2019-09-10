#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>
#include "Hero.h"
#include "cv.h"
#include "highgui.h"

using namespace std;

void input_int(int& choice0, int min0, int max0);//输入int型数据（工具函数）

Hero::Hero(string name0, bool if_file0) :Role(name0), experience(0), level(1), what_weapon(Goods("无")), what_armor(Goods("无")), bag(Bag()), if_file(if_file0),
barrier{false,false,false,false,false,false,false,false,false,false}//构造函数（读档）
{
	if (if_file == true)
		read_file();
	else
		start();
}

void Hero::start()//初始
{
	if (name == "唐三藏")
	{
		max_health_points = 4500;
		basic_attack_power = 650;
		basic_defensive_power = 150;
	}

	else if (name == "孙悟空")
	{
		max_health_points = 5100;
		basic_attack_power = 600;
		basic_defensive_power = 200;
	}

	else if (name == "猪悟能")
	{
		max_health_points = 6300;
		basic_attack_power = 400;
		basic_defensive_power = 350;
	}

	else
	{
		max_health_points = 5500;
		basic_attack_power = 550;
		basic_defensive_power = 250;
	}

	health_points = max_health_points;
	attack_power = basic_attack_power;
	defensive_power = basic_defensive_power;
	location = "东土大唐";
}

int Hero::get_experience() const { return experience; }//获得经验值

int Hero::get_level() const { return level; }//获得等级

Goods& Hero::get_what_weapon() { return what_weapon; }//获得武器

Goods& Hero::get_what_armor() { return what_armor; }//获得护甲

Bag& Hero::get_bag() { return bag; }//获得背包

void Hero::show_barrier() const//显示已通过和未通过关卡
{
	bool pass = false;
	
	cout << "已通过关卡：" << endl;
	pass = false;
	for (int i = 1; i <= 9; i++)
		if (barrier[i] == true)
			pass = true;
	if (pass == true)
	{
		if (barrier[1] == true)
			cout << "黑风山黑风洞" << endl;
		if (barrier[2] == true)
			cout << "黄风岭黄风洞" << endl;
		if (barrier[3] == true)
			cout << "骷髅山白骨洞" << endl;
		if (barrier[4] == true)
			cout << "号山枯松涧火云洞" << endl;
		if (barrier[5] == true)
			cout << "毒敌山琵琶洞" << endl;
		if (barrier[6] == true)
			cout << "花果山水帘洞" << endl;
		if (barrier[7] == true)
			cout << "小西天小雷音寺" << endl;
		if (barrier[8] == true)
			cout << "陷空山无底洞" << endl;
		if (barrier[9] == true)
			cout << "毛颖山狡兔三穴" << endl;
	}
	else
		cout << "无" << endl;
	cout << endl;
	
	cout << "未通过关卡：" << endl;
	pass = true;
	for (int i = 1; i <= 9; i++)
		if (barrier[i] == false)
			pass = false;
	if (pass == false)
	{
		if (barrier[1] == false)
			cout << "黑风山黑风洞" << endl;
		if (barrier[2] == false)
			cout << "黄风岭黄风洞" << endl;
		if (barrier[3] == false)
			cout << "骷髅山白骨洞" << endl;
		if (barrier[4] == false)
			cout << "号山枯松涧火云洞" << endl;
		if (barrier[5] == false)
			cout << "毒敌山琵琶洞" << endl;
		if (barrier[6] == false)
			cout << "花果山水帘洞" << endl;
		if (barrier[7] == false)
			cout << "小西天小雷音寺" << endl;
		if (barrier[8] == false)
			cout << "陷空山无底洞" << endl;
		if (barrier[9] == false)
			cout << "毛颖山狡兔三穴" << endl;
	}
	else
		cout << "无" << endl;
	cout << endl;
}

void Hero::show() const//显示信息
{
	system("cls");
	Role::show();
	cout << "经  验  值："<<experience<<endl;
	cout << "等      级："<<level<<endl;
	cout << endl;
	cout << "装备武器："<<what_weapon.get_name()<<endl;
	cout << "装备护甲："<<what_armor.get_name()<<endl;
	cout << endl;
	bag.show();
	show_barrier();
	cout << endl;
}

bool Hero::if_weapon() const//判断有没有装备武器
{
	if (what_weapon.get_name() != "无")
		return true;
	else
		return false;
}

bool Hero::if_armor() const//判断有没有装备护甲
{
	if (what_armor.get_name() != "无")
		return true;
	else
		return false;
}

bool Hero::if_success() const//判断是否通关成功
{
	bool success=true;

	for (int i = 1; i <= 9; i++)
		if (barrier[i] == false)
		{
			success = false;
			break;
		}

	return success;
}


void Hero::reward(int min1, int max1, int min2, int max2)//宝箱/陷阱（min1-max1 为奖励区间，min2-max2为惩罚区间）
{
	srand((unsigned)time(NULL));

	int ward = 0;

	if (rand() % 11 >= 6)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);

		ward = (rand() % (max1 - min1 + 1)) + min1;
		bag.change_gold(ward);
		cout << "恭喜您！发现宝箱，奖励 " << ward << " 金币。" << endl << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);

		ward = (rand() % (max2 - min2 + 1)) + min2;
		if (bag.get_gold() >= ward)
		{
			bag.change_gold(-ward);
			cout << "您不幸掉入陷阱中，掉落 " << ward << " 金币。" << endl << endl;
		}
		else
		{
			int now_gold = bag.get_gold();
			bag.change_gold(-now_gold);
			cout << "您不幸掉入陷阱中，掉落全部共 " << now_gold << " 金币。" << endl << endl;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Hero::travel()//赶路
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);

	ifstream ifs("map.dat");
	for (string str; getline(ifs, str);)
		cout << str << endl;
	ifs.close();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << "请选择目的地：" << endl;
	cout << endl;
	cout << "0.退出" << endl;
	cout << "1.黑风山黑风洞" << endl;
	cout << "2.黄风岭黄风洞" << endl;
	cout << "3.骷髅山白骨洞" << endl;
	cout << "4.号山枯松涧火云洞" << endl;
	cout << "5.毒敌山琵琶洞" << endl;
	cout << "6.花果山水帘洞" << endl;
	cout << "7.小西天小雷音寺" << endl;
	cout << "8.陷空山无底洞" << endl;
	cout << "9.毛颖山狡兔三穴" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 0, 9);

	system("cls");

	if (choice != 0)
	{
		string destination = "黑风山黑风洞";

		if (choice == 1)
			destination = "黑风山黑风洞";
		else if (choice == 2)
			destination = "黄风岭黄风洞";
		else if (choice == 3)
			destination = "骷髅山白骨洞";
		else if (choice == 4)
			destination = "号山枯松涧火云洞";
		else if (choice == 5)
			destination = "毒敌山琵琶洞";
		else if (choice == 6)
			destination = "花果山水帘洞";
		else if (choice == 7)
			destination = "小西天小雷音寺";
		else if (choice == 8)
			destination = "陷空山无底洞";
		else
			destination = "毛颖山狡兔三穴";

		location = destination;
		cout << "您已到达" << destination << endl;
		cout << endl;
		if (choice == 1)
			reward(5, 10, 2, 4);
		else if (choice == 2)
			reward(7, 12, 5, 9);
		else if (choice == 3)
			reward(10, 15, 4, 8);
		else if (choice == 4)
			reward(9, 16, 4, 10);
		else if (choice == 5)
			reward(12, 17, 6, 11);
		else if (choice == 6)
			reward(12, 20, 6, 13);
		else if (choice == 7)
			reward(13, 20, 6, 13);
		else if (choice == 8)
			reward(8, 15, 5, 9);
		else
			reward(7, 12, 4, 10);
	}
}

void Hero::add_experience(int experience0)//提升经验值
{
	if (experience < 100000)
	{
		int experience1 = experience + experience0;

		if (experience1 < 100000)
		{
			experience = experience1;
			cout << "您的经验值增加了" << experience0 << endl;
			for (int i = 2; i <= 9; i++)
				if (experience >= i * 10000 && experience<(i+1)*10000)
				{
					level=i;
					max_health_points = int(max_health_points*1.1);
					basic_attack_power = int(basic_attack_power*1.1);
					basic_defensive_power = int(basic_defensive_power*1.1);
					attack_power = basic_attack_power + what_weapon.get_effect();
					defensive_power = basic_defensive_power + what_armor.get_effect();
					cout << "您已升至" << i << "级" << endl;
				}
		}
		else
		{
			experience = 100000;
			level = 10;
			cout << "您的经验值已满！" << endl;
			max_health_points = int(max_health_points * 1.1);
			basic_attack_power = int(basic_attack_power * 1.1);
			basic_defensive_power = int(basic_defensive_power * 1.1);
			attack_power = basic_attack_power + what_weapon.get_effect();
			defensive_power = basic_defensive_power + what_armor.get_effect();
			cout << "您已升至10级（满级）！" << endl;
		}
		cout << endl;
	}
}

void Hero::add_gold(int gold0)//增加金币
{
	bag.change_gold(gold0);
}

void Hero::buy(Store& store)//购买物品
{
	system("cls");
	store.show();
	bag.show();
	cout << endl;
	cout << "请选择要购买的物品：" << endl;
	cout << "0.退出" << endl;
	cout << "1.青锋剑" << endl;
	cout << "2.游龙剑" << endl;
	cout << "3.灵犀神剑" << endl;
	cout << "4.赤鳞甲" << endl;
	cout << "5.白玉龙甲" << endl;
	cout << "6.紫金磐龙甲" << endl;
	cout << "7.血气丹" << endl;
	cout << "8.复灵紫丹" << endl;
	cout << "9.九转还魂丹" << endl;
	cout << endl;
	
	int choice=0;
	input_int(choice, 0, 9);

	system("cls");

	if (choice!=0)
	{
		Goods goods0=store.get_goods(choice);

		if (bag.get_gold() >= goods0.get_price())
		{
			if (bag.put_in(goods0))
			{
				bag.change_gold(-goods0.get_price());
				cout << "购买成功，已放入您的背包" << endl;
			}
			else
				cout << "购买失败，您的背包空间不足，请先装备或卖掉一些物品！" << endl;
		}
		else
			cout << "购买失败，您的金币不足！" << endl;
		cout << endl;
	}
}

void Hero::sell(Store& store)//出售物品
{
	system("cls");
	store.show();
	bag.show();
	cout << "请选择要出售的物品：" << endl;
	cout << "0.退出" << endl;
	cout << "1.青锋剑" << endl;
	cout << "2.游龙剑" << endl;
	cout << "3.灵犀神剑" << endl;
	cout << "4.赤鳞甲" << endl;
	cout << "5.白玉龙甲" << endl;
	cout << "6.紫金磐龙甲" << endl;
	cout << "7.血气丹" << endl;
	cout << "8.复灵紫丹" << endl;
	cout << "9.九转还魂丹" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 0, 9);

	system("cls");

	if (choice!=0)
	{
		Goods goods0 = store.get_goods(choice);

		if (bag.take_out(goods0))
		{
			bag.change_gold(goods0.get_price());
			cout << "出售成功" << endl;
		}
		else
			cout << "出售失败，您的背包中没有此物品！" << endl;
		cout << endl;
	}
}

void Hero::put_on()//装备物品
{
	system("cls");
	bag.show();
	cout << "请选择要装备的物品：" << endl;
	cout << "0.退出" << endl;
	cout << "1.武器：青锋剑" << endl;
	cout << "2.武器：游龙剑" << endl;
	cout << "3.武器：灵犀神剑" << endl;
	cout << "4.护甲：赤鳞甲" << endl;
	cout << "5.护甲：白玉龙甲" << endl;
	cout << "6.护甲：紫金磐龙甲" << endl;
	cout << endl;
	
	int choice = 0;
	input_int(choice, 0, 6);

	system("cls");

	if (choice!=0)
	{
		Goods goods0("无");

		if (choice == 1)
			goods0 = Goods("青锋剑");
		else if (choice == 2)
			goods0 = Goods("游龙剑");
		else if (choice == 3)
			goods0 = Goods("灵犀神剑");
		else if (choice == 4)
			goods0 = Goods("赤鳞甲");
		else if (choice == 5)
			goods0 = Goods("白玉龙甲");
		else
			goods0 = Goods("紫金磐龙甲");

		if (goods0.get_type()=="武器")
		{
			if (if_weapon())
				cout << "您已装备武器，请先卸下武器！" << endl;
			else
			{
				if (bag.take_out(goods0))
				{
					change_attack_power(goods0.get_effect());
					cout << "装备成功" << endl;
				}
				else
					cout << "装备失败，您的背包中没有此物品！" << endl;
			}
		}

		else
		{
			if (if_armor())
				cout << "您已装备护甲，请先卸下护甲！" << endl;
			else
			{
				if (bag.take_out(goods0))
				{
					change_defensive_power(goods0.get_effect());
					cout << "装备成功" << endl;
				}
				else
					cout << "装备失败，您的背包中没有此物品！" << endl;
			}
		}

		cout << endl;
	}
}

void Hero::take_off()//卸下物品
{
	system("cls");
	cout << "请选择要卸下的物品：" << endl;
	cout << "0.退出" << endl;
	cout << "1.武器" << endl;
	cout << "2.护甲" << endl;
	cout << endl;
	
	int choice = 0;
	input_int(choice, 0, 2);

	system("cls");

	if (choice!=0)
	{
		if (choice == 1)
		{
			if (if_weapon())
			{
				Goods goods0 = get_what_weapon();
				if (bag.put_in(goods0))
				{
					change_attack_power(-goods0.get_effect());
					cout << "卸下成功" << endl;
				}
				else
					cout << "卸下失败，您的背包空间不足，请先装备或卖掉一些物品！" << endl;
			}
			else
				cout << "您没有装备武器！" << endl;
		}

		else
		{
			if (if_armor())
			{
				Goods goods0 = get_what_armor();
				if (bag.put_in(goods0))
				{
					change_defensive_power(-goods0.get_effect());
					cout << "卸下成功" << endl;
				}
				else
					cout << "卸下失败，您的背包空间不足，请先装备或卖掉一些物品！" << endl;
			}
			else
				cout << "您没有装备护甲！" << endl;
		}

		cout << endl;
	}
}

void Hero::take()//服用丹药
{
	bag.show();
	cout << "请选择要服用的丹药：" << endl;
	cout << "0.退出" << endl;
	cout << "1.血气丹" << endl;
	cout << "2.复灵紫丹" << endl;
	cout << "3.九转还魂丹" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 0, 3);

	system("cls");

	if (choice!=0)
	{
		Goods goods0("无");

		if (choice == 1)
			goods0 = Goods("血气丹");
		else if (choice == 2)
			goods0 = Goods("复灵紫丹");
		else
			goods0 = Goods("九转还魂丹");

		if (health_points == max_health_points)
			cout << "您的血量健康，无需服用丹药！" << endl;
		else
		{
			if (bag.take_out(goods0))
			{
				change_health_points(goods0.get_effect());
				cout << "服用成功" << endl;
			}
			else
				cout << "服用失败，您的背包中没有此物品！" << endl;
		}

		cout << endl;
	}
}

void Hero::change_barrier(Monster& monster)//改变已通过和未通过关卡
{
	if (monster.get_name() == "黑熊精")
		barrier[1] = true;
	else if (monster.get_name() == "黄风怪")
		barrier[2] = true;
	else if (monster.get_name() == "白骨夫人")
		barrier[3] = true;
	else if (monster.get_name() == "圣婴大王")
		barrier[4] = true;
	else if (monster.get_name() == "蝎女妖")
		barrier[5] = true;
	else if (monster.get_name() == "六耳猕猴")
		barrier[6] = true;
	else if (monster.get_name() == "黄眉老祖")
		barrier[7] = true;
	else if (monster.get_name() == "地涌夫人")
		barrier[8] = true;
	else
		barrier[9] = true;
}

void Hero::attack(Monster& monster)//攻击
{
	cout << "请选择操作：" << endl;
	cout << "1.攻击（物理）" << endl;
	cout << "2.强化（法术）（暂时强化自身攻击，对战结束后失效）" << endl;
	cout << "3.弱化（法术）（暂时弱化妖怪攻击，对战结束后失效）" << endl;
	cout << "4.治疗（物理）（服用丹药）" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 1, 4);

	system("cls");

	int numerical_value = 0;

	if (choice == 1)
	{
		int damage_value = attack_power - monster.get_defensive_power();

		int true_damage_value = damage_value > 0 ? damage_value : 0;

		monster.change_health_points(-true_damage_value);
		cout << "您对妖怪造成了" << true_damage_value << "伤害" << endl;
		cout << endl;
	}

	else if (choice == 2)
	{
		numerical_value = int(attack_power * 0.2);
		change_attack_power(numerical_value);
		cout << "您的攻击力提升了" << numerical_value << endl;
		cout << endl;
	}

	else if (choice == 3)
	{
		numerical_value = int(monster.get_attack_power() * 0.07);
		monster.change_attack_power(-numerical_value);
		cout << "妖怪的攻击力降低了" << numerical_value << endl;
		cout << endl;
	}

	else
		take();
}

bool Hero::pay()//付费复活
{
	cout << "请用支付宝扫描二维码付款，付款成功后将鼠标移到二维码上，然后按Enter键" << endl;
	cout << endl;

	IplImage* img = cvLoadImage("支付宝付款码.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cvNamedWindow("支付宝付款码", CV_WINDOW_AUTOSIZE);//创建窗口
	cvShowImage("支付宝付款码", img);                 //显示图像
	cvWaitKey(0);                                    //等待按键
	cvDestroyWindow("支付宝付款码");                  //销毁窗口
	cvReleaseImage(&img);                            //释放图像

	tm local;
	time_t t;
	time(&t);
	localtime_s(&local, &t);

	int true_password=0;

	if (local.tm_min >=0 && local.tm_min < 10)
		true_password = local.tm_year+1900-2000;

	else if(local.tm_min>=10 && local.tm_min<20)
		true_password = local.tm_mon+1;

	else if (local.tm_min >= 20 && local.tm_min < 30)
		true_password = local.tm_wday;

	else if (local.tm_min >= 30 && local.tm_min < 40)
		true_password = local.tm_mday;

	else if (local.tm_min >= 40 && local.tm_min < 50)
		true_password = local.tm_hour;

	else
		true_password = local.tm_hour+1;
	
	cout << "请输入验证码（输入0放弃付款）" << endl;

	int password = 0;
	cin >> password;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "输入错误，请输入数字！" << endl;
		cin >> password;
	}
	while (password != 0)
	{
		if (password == true_password)
			return true;
		else
		{
			cout << "验证码错误！请重新输入（输入0放弃付款）" << endl;
			cin >> password;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "输入错误，请输入数字！" << endl;
				cin >> password;
			}
		}
	}

	return false;
}

void Hero::fight()//战斗
{
	system("cls");

	if (location == "东土大唐")
	{
		cout << "此处无妖！" << endl;
		cout << endl;
	}
	else
	{
		if (health_points == 1)
		{
			cout << "您目前处于重伤状态，是否还要参与战斗？" << endl;
			cout << "0.否" << endl;
			cout << "1.是" << endl;
			
			int choice = 0;
			input_int(choice, 0, 1);

			if (choice == 1)
			{
				Monster monster("黑熊精");

				if (location == "黑风山黑风洞")
					monster = Monster("黑熊精");

				else if (location == "黄风岭黄风洞")
					monster = Monster("黄风怪");

				else if (location == "骷髅山白骨洞")
					monster = Monster("白骨夫人");

				else if (location == "号山枯松涧火云洞")
					monster = Monster("圣婴大王");

				else if (location == "毒敌山琵琶洞")
					monster = Monster("蝎女妖");

				else if (location == "花果山水帘洞")
					monster = Monster("六耳猕猴");

				else if (location == "小西天小雷音寺")
					monster = Monster("黄眉老祖");

				else if (location == "陷空山无底洞")
					monster = Monster("地涌夫人");

				else
					monster = Monster("玉兔精");

				monster.show();

				int attack_power0 = attack_power;

				while (1)
				{
					cout << "战力对比：" << endl;
					cout << setiosflags(ios_base::left) << setw(10) << "角色" << setw(10) << "生命值" << setw(10) << "攻击力" << setw(10) << "防御力" << endl;
					cout << setiosflags(ios_base::left) << setw(10) << name << setw(10) << health_points << setw(10) << attack_power << setw(10) << defensive_power << endl;
					cout << setiosflags(ios_base::left) << setw(10) << monster.get_name() << setw(10) << monster.get_health_points() << setw(10) << monster.get_attack_power() << setw(10) << monster.get_defensive_power() << endl;
					cout << endl;

					cout << "请选择操作：" << endl;
					cout << "0.逃跑" << endl;
					cout << "1.继续战斗" << endl;
					cout << endl;

					int choice = 0;
					input_int(choice, 0, 1);

					system("cls");

					if (choice == 0)
					{
						system("cls");
						cout << "逃脱成功" << endl;
						cout << endl;
						break;
					}	
					else
					{
						attack(monster);
						if (monster.get_health_points() == 1)
						{
							change_barrier(monster);
							cout << "您已成功击败" << monster.get_name() << "！" << endl;
							cout << "获得金币：" << monster.get_lose_gold() << endl;
							add_gold(monster.get_lose_gold());
							add_experience(monster.get_lose_experience());
							if (if_success())
							{
								location == "东土大唐";
								cout << "您已成功通过所有关卡，寻得全部真经，返回东土大唐！" << endl;
							}
							cout << endl;
							break;
						}

						monster.attack(*this);
						if (get_health_points() == 1)
						{
							cout << "您已被击败！" << endl;
							cout << "是否复活?" << endl;
							cout << "0.否" << endl;
							cout << "1.是" << endl;
							cout << endl;

							choice = 0;
							input_int(choice, 0, 1);

							system("cls");

							if (choice == 0)
								break;
							else
							{
								if (pay())
								{
									health_points = max_health_points;
									attack_power = attack_power0;
									system("cls");
									cout << "您已复活！请继续游戏" << endl;
									cout << endl;
								}
								else
									break;
							}
						}
					}
				}
				attack_power = attack_power0;
			}
		}
		else
		{
			Monster monster("黑熊精");

			if (location == "黑风山黑风洞")
				monster = Monster("黑熊精");

			else if (location == "黄风岭黄风洞")
				monster = Monster("黄风怪");

			else if (location == "骷髅山白骨洞")
				monster = Monster("白骨夫人");

			else if (location == "号山枯松涧火云洞")
				monster = Monster("圣婴大王");

			else if (location == "毒敌山琵琶洞")
				monster = Monster("蝎女妖");

			else if (location == "花果山水帘洞")
				monster = Monster("六耳猕猴");

			else if (location == "小西天小雷音寺")
				monster = Monster("黄眉老祖");

			else if (location == "陷空山无底洞")
				monster = Monster("地涌夫人");

			else
				monster = Monster("玉兔精");

			monster.show();

			int attack_power0 = attack_power;

			while (1)
			{
				cout << "战力对比：" << endl;
				cout << setiosflags(ios_base::left) << setw(10) << "角色" << setw(10) << "生命值" << setw(10) << "攻击力" << setw(10) << "防御力" << endl;
				cout << setiosflags(ios_base::left) << setw(10) << name << setw(10) << health_points << setw(10) << attack_power << setw(10) << defensive_power << endl;
				cout << setiosflags(ios_base::left) << setw(10) << monster.get_name() << setw(10) << monster.get_health_points() << setw(10) << monster.get_attack_power() << setw(10) << monster.get_defensive_power() << endl;
				cout << endl;
				
				cout << "请选择操作：" << endl;
				cout << "0.逃跑" << endl;
				cout << "1.继续战斗" << endl;
				cout << endl;

				int choice = 0;
				input_int(choice, 0, 1);

				system("cls");

				if (choice == 0)
				{
					system("cls");
					cout << "逃脱成功" << endl;
					cout << endl;
					break;
				}
				else
				{
					attack(monster);
					if (monster.get_health_points() == 1)
					{
						change_barrier(monster);
						cout << "您已成功击败" << monster.get_name() << "！" << endl;
						cout << "获得金币：" << monster.get_lose_gold() << endl;
						add_gold(monster.get_lose_gold());
						add_experience(monster.get_lose_experience());
						if (if_success())
						{
							location == "东土大唐";
							cout << "您已成功通过所有关卡，寻得全部真经，返回东土大唐！" << endl;
							cout << endl;
						}
						cout << endl;
						break;
					}

					monster.attack(*this);
					if (get_health_points() == 1)
					{
						cout << "您已被击败！" << endl;
						cout << "是否复活?" << endl;
						cout << "0.否" << endl;
						cout << "1.是" << endl;
						cout << endl;

						choice = 0;
						input_int(choice, 0, 1);

						system("cls");

						if (choice == 0)
							break;
						else
						{
							if (pay())
							{
								health_points = max_health_points;
								attack_power = attack_power0;
								system("cls");
								cout << "您已复活！请继续游戏" << endl;
								cout << endl;
							}
							else
								break;
						}
					}
				}
			}
			attack_power = attack_power0;
		}
	}
}

void Hero::read_file()//读文件
{
	ifstream ifs;

	if (name == "唐三藏")
		ifs.open("唐三藏.dat", ios_base::in | ios_base::binary);
	else if (name == "孙悟空")
		ifs.open("孙悟空.dat", ios_base::in | ios_base::binary);
	else if (name == "猪悟能")
		ifs.open("猪悟能.dat", ios_base::in | ios_base::binary);
	else
		ifs.open("沙悟净.dat", ios_base::in | ios_base::binary);

	if (ifs)
	{
		ifs >> name >> max_health_points >> basic_attack_power >> basic_defensive_power
			>> health_points >> attack_power >> defensive_power >> location
			>> experience >> level >> what_weapon >> what_armor >> bag;
		for (int i = 0; i < 10; i++)
			ifs >> barrier[i];
	}
		
	else
		start();

	ifs.close();
}

void Hero::write_file()//写文件
{
	ofstream ofs;

	if (name == "唐三藏")
		ofs.open("唐三藏.dat", ios_base::out | ios_base::binary);
	else if (name == "孙悟空")
		ofs.open("孙悟空.dat", ios_base::out | ios_base::binary);
	else if (name == "猪悟能")
		ofs.open("猪悟能.dat", ios_base::out | ios_base::binary);
	else
		ofs.open("沙悟净.dat", ios_base::out | ios_base::binary);

	if (ofs)
	{
		ofs << name <<" "<< max_health_points << " "<< basic_attack_power << " " << basic_defensive_power<<" "
			<< health_points << " " << attack_power << " " << defensive_power << " " << location<<" "
			<< experience << " " << level << " " << what_weapon << " " << what_armor << " " << bag<<" ";
		for (int i = 0; i < 10; i++)
			ofs << barrier[i]<<" ";
	}

	ofs.close();
}

Hero::~Hero()//析构函数（存档）
{
	write_file();
}
