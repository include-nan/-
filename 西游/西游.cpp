#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "Goods.h"
#include "Bag.h"
#include "Role.h"
#include "Hero.h"
#include "Monster.h"

using namespace std;

void input_int(int& choice0, int min0, int max0)//输入int型数据（工具函数）
{
	cin >> choice0;

	while (1)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "输入错误！请输入大于等于" << min0 << "且小于等于" << max0 << "的整数：" << endl;
			cin >> choice0;
		}

		while (choice0 < min0 || choice0 > max0)
		{
			cout << "输入错误！请输入大于等于" << min0 << "且小于等于" << max0 << "的整数：" << endl;
			cin >> choice0;
		}

		if (!cin.fail() && choice0 >= min0 && choice0 <= max0)
			break;
	}
}

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//改变字体颜色

	ifstream ifs("logo.dat");
	for (string str; getline(ifs, str);)
		cout << str << endl;
	ifs.close();

	system("pause");

	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	CONSOLE_FONT_INFOEX cfi;//改变字体大小
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 28;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	cout << "大唐得真经，然失九卷，散于九地，为妖所得，作修炼之用。" << endl;//游戏背景
	cout<<"天子遂命唐三藏师徒寻之。寻得九卷真经，返唐，遂功成。" << endl;
	cout << endl;

	cout <<"0. 退出游戏" << endl;//选模式
	cout <<"1. 新的开始" << endl;
	cout <<"2. 继续游戏" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 0, 2);

	system("cls");

	if (choice != 0)
	{
		cout << "请选择角色：" << endl;//选角色
		cout << "0.退出游戏" << endl;
		cout << "1.唐三藏" << endl;
		cout << "2.孙悟空" << endl;
		cout << "3.猪悟能" << endl;
		cout << "4.沙悟净" << endl;
		cout << endl;

		int choice0 = 0;
		input_int(choice0, 0, 4);

		system("cls");

		if (choice0 != 0)
		{
			Hero hero("唐三藏",false);

			if (choice == 1)
			{
				if (choice0 == 1)
					hero = Hero("唐三藏", false);
				else if (choice0 == 2)
					hero = Hero("孙悟空", false);
				else if (choice0 == 3)
					hero = Hero("猪悟能", false);
				else
					hero = Hero("沙悟净", false);
			}
			else
			{
				if (choice0 == 1)
					hero = Hero("唐三藏",true);
				else if (choice0 == 2)
					hero = Hero("孙悟空",true);
				else if (choice0 == 3)
					hero = Hero("猪悟能",true);
				else
					hero = Hero("沙悟净",true);
			}

			hero.show();//显示信息

			cout << "请选择操作：" << endl;//选操作
			cout << "0.退出游戏（游戏自动存档）" << endl;
			cout << "1.显示信息" << endl;
			cout << "2.赶路" << endl;
			cout << "3.购买物品" << endl;
			cout << "4.出售物品" << endl;
			cout << "5.装备物品" << endl;
			cout << "6.卸下物品" << endl;
			cout << "7.服用丹药" << endl;
			cout << "8.战斗" << endl;
			cout << "9.小提示" << endl;
			cout << endl;

			choice = 0;
			input_int(choice, 0, 9);

			system("cls");

			Store store;

			while (choice)
			{
				if (choice == 1)
					hero.show();
				else if (choice == 2)
					hero.travel();
				else if (choice == 3)
					hero.buy(store);
				else if (choice == 4)
					hero.sell(store);
				else if (choice == 5)
					hero.put_on();
				else if (choice == 6)
					hero.take_off();
				else if (choice == 7)
				{
					system("cls");
					hero.take();
				}
				else if (choice == 8)
					hero.fight();
				else
				{
					ifstream ifs("tips.dat");
					for (string str; getline(ifs, str);)
						cout << str << endl;
					ifs.close();
				}

				cout << "请选择操作：" << endl;
				cout << "0.退出游戏（游戏自动存档）" << endl;
				cout << "1.显示信息" << endl;
				cout << "2.赶路" << endl;
				cout << "3.购买物品" << endl;
				cout << "4.出售物品" << endl;
				cout << "5.装备物品" << endl;
				cout << "6.卸下物品" << endl;
				cout << "7.服用丹药" << endl;
				cout << "8.战斗" << endl;
				cout << "9.小提示" << endl;
				cout << endl;

				choice = 0;
				input_int(choice, 0, 9);

				system("cls");

				if (choice == 0)
					break;
			}
		}	
	}
	
	return 0;
}



