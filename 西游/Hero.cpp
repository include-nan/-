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

void input_int(int& choice0, int min0, int max0);//����int�����ݣ����ߺ�����

Hero::Hero(string name0, bool if_file0) :Role(name0), experience(0), level(1), what_weapon(Goods("��")), what_armor(Goods("��")), bag(Bag()), if_file(if_file0),
barrier{false,false,false,false,false,false,false,false,false,false}//���캯����������
{
	if (if_file == true)
		read_file();
	else
		start();
}

void Hero::start()//��ʼ
{
	if (name == "������")
	{
		max_health_points = 4500;
		basic_attack_power = 650;
		basic_defensive_power = 150;
	}

	else if (name == "�����")
	{
		max_health_points = 5100;
		basic_attack_power = 600;
		basic_defensive_power = 200;
	}

	else if (name == "������")
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
	location = "��������";
}

int Hero::get_experience() const { return experience; }//��þ���ֵ

int Hero::get_level() const { return level; }//��õȼ�

Goods& Hero::get_what_weapon() { return what_weapon; }//�������

Goods& Hero::get_what_armor() { return what_armor; }//��û���

Bag& Hero::get_bag() { return bag; }//��ñ���

void Hero::show_barrier() const//��ʾ��ͨ����δͨ���ؿ�
{
	bool pass = false;
	
	cout << "��ͨ���ؿ���" << endl;
	pass = false;
	for (int i = 1; i <= 9; i++)
		if (barrier[i] == true)
			pass = true;
	if (pass == true)
	{
		if (barrier[1] == true)
			cout << "�ڷ�ɽ�ڷ綴" << endl;
		if (barrier[2] == true)
			cout << "�Ʒ���Ʒ綴" << endl;
		if (barrier[3] == true)
			cout << "����ɽ�׹Ƕ�" << endl;
		if (barrier[4] == true)
			cout << "��ɽ���ɽ����ƶ�" << endl;
		if (barrier[5] == true)
			cout << "����ɽ���ö�" << endl;
		if (barrier[6] == true)
			cout << "����ɽˮ����" << endl;
		if (barrier[7] == true)
			cout << "С����С������" << endl;
		if (barrier[8] == true)
			cout << "�ݿ�ɽ�޵׶�" << endl;
		if (barrier[9] == true)
			cout << "ëӱɽ������Ѩ" << endl;
	}
	else
		cout << "��" << endl;
	cout << endl;
	
	cout << "δͨ���ؿ���" << endl;
	pass = true;
	for (int i = 1; i <= 9; i++)
		if (barrier[i] == false)
			pass = false;
	if (pass == false)
	{
		if (barrier[1] == false)
			cout << "�ڷ�ɽ�ڷ綴" << endl;
		if (barrier[2] == false)
			cout << "�Ʒ���Ʒ綴" << endl;
		if (barrier[3] == false)
			cout << "����ɽ�׹Ƕ�" << endl;
		if (barrier[4] == false)
			cout << "��ɽ���ɽ����ƶ�" << endl;
		if (barrier[5] == false)
			cout << "����ɽ���ö�" << endl;
		if (barrier[6] == false)
			cout << "����ɽˮ����" << endl;
		if (barrier[7] == false)
			cout << "С����С������" << endl;
		if (barrier[8] == false)
			cout << "�ݿ�ɽ�޵׶�" << endl;
		if (barrier[9] == false)
			cout << "ëӱɽ������Ѩ" << endl;
	}
	else
		cout << "��" << endl;
	cout << endl;
}

void Hero::show() const//��ʾ��Ϣ
{
	system("cls");
	Role::show();
	cout << "��  ��  ֵ��"<<experience<<endl;
	cout << "��      ����"<<level<<endl;
	cout << endl;
	cout << "װ��������"<<what_weapon.get_name()<<endl;
	cout << "װ�����ף�"<<what_armor.get_name()<<endl;
	cout << endl;
	bag.show();
	show_barrier();
	cout << endl;
}

bool Hero::if_weapon() const//�ж���û��װ������
{
	if (what_weapon.get_name() != "��")
		return true;
	else
		return false;
}

bool Hero::if_armor() const//�ж���û��װ������
{
	if (what_armor.get_name() != "��")
		return true;
	else
		return false;
}

bool Hero::if_success() const//�ж��Ƿ�ͨ�سɹ�
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


void Hero::reward(int min1, int max1, int min2, int max2)//����/���壨min1-max1 Ϊ�������䣬min2-max2Ϊ�ͷ����䣩
{
	srand((unsigned)time(NULL));

	int ward = 0;

	if (rand() % 11 >= 6)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);

		ward = (rand() % (max1 - min1 + 1)) + min1;
		bag.change_gold(ward);
		cout << "��ϲ�������ֱ��䣬���� " << ward << " ��ҡ�" << endl << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);

		ward = (rand() % (max2 - min2 + 1)) + min2;
		if (bag.get_gold() >= ward)
		{
			bag.change_gold(-ward);
			cout << "�����ҵ��������У����� " << ward << " ��ҡ�" << endl << endl;
		}
		else
		{
			int now_gold = bag.get_gold();
			bag.change_gold(-now_gold);
			cout << "�����ҵ��������У�����ȫ���� " << now_gold << " ��ҡ�" << endl << endl;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Hero::travel()//��·
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);

	ifstream ifs("map.dat");
	for (string str; getline(ifs, str);)
		cout << str << endl;
	ifs.close();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << "��ѡ��Ŀ�ĵأ�" << endl;
	cout << endl;
	cout << "0.�˳�" << endl;
	cout << "1.�ڷ�ɽ�ڷ綴" << endl;
	cout << "2.�Ʒ���Ʒ綴" << endl;
	cout << "3.����ɽ�׹Ƕ�" << endl;
	cout << "4.��ɽ���ɽ����ƶ�" << endl;
	cout << "5.����ɽ���ö�" << endl;
	cout << "6.����ɽˮ����" << endl;
	cout << "7.С����С������" << endl;
	cout << "8.�ݿ�ɽ�޵׶�" << endl;
	cout << "9.ëӱɽ������Ѩ" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 0, 9);

	system("cls");

	if (choice != 0)
	{
		string destination = "�ڷ�ɽ�ڷ綴";

		if (choice == 1)
			destination = "�ڷ�ɽ�ڷ綴";
		else if (choice == 2)
			destination = "�Ʒ���Ʒ綴";
		else if (choice == 3)
			destination = "����ɽ�׹Ƕ�";
		else if (choice == 4)
			destination = "��ɽ���ɽ����ƶ�";
		else if (choice == 5)
			destination = "����ɽ���ö�";
		else if (choice == 6)
			destination = "����ɽˮ����";
		else if (choice == 7)
			destination = "С����С������";
		else if (choice == 8)
			destination = "�ݿ�ɽ�޵׶�";
		else
			destination = "ëӱɽ������Ѩ";

		location = destination;
		cout << "���ѵ���" << destination << endl;
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

void Hero::add_experience(int experience0)//��������ֵ
{
	if (experience < 100000)
	{
		int experience1 = experience + experience0;

		if (experience1 < 100000)
		{
			experience = experience1;
			cout << "���ľ���ֵ������" << experience0 << endl;
			for (int i = 2; i <= 9; i++)
				if (experience >= i * 10000 && experience<(i+1)*10000)
				{
					level=i;
					max_health_points = int(max_health_points*1.1);
					basic_attack_power = int(basic_attack_power*1.1);
					basic_defensive_power = int(basic_defensive_power*1.1);
					attack_power = basic_attack_power + what_weapon.get_effect();
					defensive_power = basic_defensive_power + what_armor.get_effect();
					cout << "��������" << i << "��" << endl;
				}
		}
		else
		{
			experience = 100000;
			level = 10;
			cout << "���ľ���ֵ������" << endl;
			max_health_points = int(max_health_points * 1.1);
			basic_attack_power = int(basic_attack_power * 1.1);
			basic_defensive_power = int(basic_defensive_power * 1.1);
			attack_power = basic_attack_power + what_weapon.get_effect();
			defensive_power = basic_defensive_power + what_armor.get_effect();
			cout << "��������10������������" << endl;
		}
		cout << endl;
	}
}

void Hero::add_gold(int gold0)//���ӽ��
{
	bag.change_gold(gold0);
}

void Hero::buy(Store& store)//������Ʒ
{
	system("cls");
	store.show();
	bag.show();
	cout << endl;
	cout << "��ѡ��Ҫ�������Ʒ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.��潣" << endl;
	cout << "2.������" << endl;
	cout << "3.��Ϭ��" << endl;
	cout << "4.���ۼ�" << endl;
	cout << "5.��������" << endl;
	cout << "6.�Ͻ�������" << endl;
	cout << "7.Ѫ����" << endl;
	cout << "8.�����ϵ�" << endl;
	cout << "9.��ת���굤" << endl;
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
				cout << "����ɹ����ѷ������ı���" << endl;
			}
			else
				cout << "����ʧ�ܣ����ı����ռ䲻�㣬����װ��������һЩ��Ʒ��" << endl;
		}
		else
			cout << "����ʧ�ܣ����Ľ�Ҳ��㣡" << endl;
		cout << endl;
	}
}

void Hero::sell(Store& store)//������Ʒ
{
	system("cls");
	store.show();
	bag.show();
	cout << "��ѡ��Ҫ���۵���Ʒ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.��潣" << endl;
	cout << "2.������" << endl;
	cout << "3.��Ϭ��" << endl;
	cout << "4.���ۼ�" << endl;
	cout << "5.��������" << endl;
	cout << "6.�Ͻ�������" << endl;
	cout << "7.Ѫ����" << endl;
	cout << "8.�����ϵ�" << endl;
	cout << "9.��ת���굤" << endl;
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
			cout << "���۳ɹ�" << endl;
		}
		else
			cout << "����ʧ�ܣ����ı�����û�д���Ʒ��" << endl;
		cout << endl;
	}
}

void Hero::put_on()//װ����Ʒ
{
	system("cls");
	bag.show();
	cout << "��ѡ��Ҫװ������Ʒ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.��������潣" << endl;
	cout << "2.������������" << endl;
	cout << "3.��������Ϭ��" << endl;
	cout << "4.���ף����ۼ�" << endl;
	cout << "5.���ף���������" << endl;
	cout << "6.���ף��Ͻ�������" << endl;
	cout << endl;
	
	int choice = 0;
	input_int(choice, 0, 6);

	system("cls");

	if (choice!=0)
	{
		Goods goods0("��");

		if (choice == 1)
			goods0 = Goods("��潣");
		else if (choice == 2)
			goods0 = Goods("������");
		else if (choice == 3)
			goods0 = Goods("��Ϭ��");
		else if (choice == 4)
			goods0 = Goods("���ۼ�");
		else if (choice == 5)
			goods0 = Goods("��������");
		else
			goods0 = Goods("�Ͻ�������");

		if (goods0.get_type()=="����")
		{
			if (if_weapon())
				cout << "����װ������������ж��������" << endl;
			else
			{
				if (bag.take_out(goods0))
				{
					change_attack_power(goods0.get_effect());
					cout << "װ���ɹ�" << endl;
				}
				else
					cout << "װ��ʧ�ܣ����ı�����û�д���Ʒ��" << endl;
			}
		}

		else
		{
			if (if_armor())
				cout << "����װ�����ף�����ж�»��ף�" << endl;
			else
			{
				if (bag.take_out(goods0))
				{
					change_defensive_power(goods0.get_effect());
					cout << "װ���ɹ�" << endl;
				}
				else
					cout << "װ��ʧ�ܣ����ı�����û�д���Ʒ��" << endl;
			}
		}

		cout << endl;
	}
}

void Hero::take_off()//ж����Ʒ
{
	system("cls");
	cout << "��ѡ��Ҫж�µ���Ʒ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
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
					cout << "ж�³ɹ�" << endl;
				}
				else
					cout << "ж��ʧ�ܣ����ı����ռ䲻�㣬����װ��������һЩ��Ʒ��" << endl;
			}
			else
				cout << "��û��װ��������" << endl;
		}

		else
		{
			if (if_armor())
			{
				Goods goods0 = get_what_armor();
				if (bag.put_in(goods0))
				{
					change_defensive_power(-goods0.get_effect());
					cout << "ж�³ɹ�" << endl;
				}
				else
					cout << "ж��ʧ�ܣ����ı����ռ䲻�㣬����װ��������һЩ��Ʒ��" << endl;
			}
			else
				cout << "��û��װ�����ף�" << endl;
		}

		cout << endl;
	}
}

void Hero::take()//���õ�ҩ
{
	bag.show();
	cout << "��ѡ��Ҫ���õĵ�ҩ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.Ѫ����" << endl;
	cout << "2.�����ϵ�" << endl;
	cout << "3.��ת���굤" << endl;
	cout << endl;

	int choice = 0;
	input_int(choice, 0, 3);

	system("cls");

	if (choice!=0)
	{
		Goods goods0("��");

		if (choice == 1)
			goods0 = Goods("Ѫ����");
		else if (choice == 2)
			goods0 = Goods("�����ϵ�");
		else
			goods0 = Goods("��ת���굤");

		if (health_points == max_health_points)
			cout << "����Ѫ��������������õ�ҩ��" << endl;
		else
		{
			if (bag.take_out(goods0))
			{
				change_health_points(goods0.get_effect());
				cout << "���óɹ�" << endl;
			}
			else
				cout << "����ʧ�ܣ����ı�����û�д���Ʒ��" << endl;
		}

		cout << endl;
	}
}

void Hero::change_barrier(Monster& monster)//�ı���ͨ����δͨ���ؿ�
{
	if (monster.get_name() == "���ܾ�")
		barrier[1] = true;
	else if (monster.get_name() == "�Ʒ��")
		barrier[2] = true;
	else if (monster.get_name() == "�׹Ƿ���")
		barrier[3] = true;
	else if (monster.get_name() == "ʥӤ����")
		barrier[4] = true;
	else if (monster.get_name() == "ЫŮ��")
		barrier[5] = true;
	else if (monster.get_name() == "����⨺�")
		barrier[6] = true;
	else if (monster.get_name() == "��ü����")
		barrier[7] = true;
	else if (monster.get_name() == "��ӿ����")
		barrier[8] = true;
	else
		barrier[9] = true;
}

void Hero::attack(Monster& monster)//����
{
	cout << "��ѡ�������" << endl;
	cout << "1.����������" << endl;
	cout << "2.ǿ��������������ʱǿ������������ս������ʧЧ��" << endl;
	cout << "3.����������������ʱ�������ֹ�������ս������ʧЧ��" << endl;
	cout << "4.���ƣ����������õ�ҩ��" << endl;
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
		cout << "�������������" << true_damage_value << "�˺�" << endl;
		cout << endl;
	}

	else if (choice == 2)
	{
		numerical_value = int(attack_power * 0.2);
		change_attack_power(numerical_value);
		cout << "���Ĺ�����������" << numerical_value << endl;
		cout << endl;
	}

	else if (choice == 3)
	{
		numerical_value = int(monster.get_attack_power() * 0.07);
		monster.change_attack_power(-numerical_value);
		cout << "���ֵĹ�����������" << numerical_value << endl;
		cout << endl;
	}

	else
		take();
}

bool Hero::pay()//���Ѹ���
{
	cout << "����֧����ɨ���ά�븶�����ɹ�������Ƶ���ά���ϣ�Ȼ��Enter��" << endl;
	cout << endl;

	IplImage* img = cvLoadImage("֧����������.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cvNamedWindow("֧����������", CV_WINDOW_AUTOSIZE);//��������
	cvShowImage("֧����������", img);                 //��ʾͼ��
	cvWaitKey(0);                                    //�ȴ�����
	cvDestroyWindow("֧����������");                  //���ٴ���
	cvReleaseImage(&img);                            //�ͷ�ͼ��

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
	
	cout << "��������֤�루����0�������" << endl;

	int password = 0;
	cin >> password;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "����������������֣�" << endl;
		cin >> password;
	}
	while (password != 0)
	{
		if (password == true_password)
			return true;
		else
		{
			cout << "��֤��������������루����0�������" << endl;
			cin >> password;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "����������������֣�" << endl;
				cin >> password;
			}
		}
	}

	return false;
}

void Hero::fight()//ս��
{
	system("cls");

	if (location == "��������")
	{
		cout << "�˴�������" << endl;
		cout << endl;
	}
	else
	{
		if (health_points == 1)
		{
			cout << "��Ŀǰ��������״̬���Ƿ�Ҫ����ս����" << endl;
			cout << "0.��" << endl;
			cout << "1.��" << endl;
			
			int choice = 0;
			input_int(choice, 0, 1);

			if (choice == 1)
			{
				Monster monster("���ܾ�");

				if (location == "�ڷ�ɽ�ڷ綴")
					monster = Monster("���ܾ�");

				else if (location == "�Ʒ���Ʒ綴")
					monster = Monster("�Ʒ��");

				else if (location == "����ɽ�׹Ƕ�")
					monster = Monster("�׹Ƿ���");

				else if (location == "��ɽ���ɽ����ƶ�")
					monster = Monster("ʥӤ����");

				else if (location == "����ɽ���ö�")
					monster = Monster("ЫŮ��");

				else if (location == "����ɽˮ����")
					monster = Monster("����⨺�");

				else if (location == "С����С������")
					monster = Monster("��ü����");

				else if (location == "�ݿ�ɽ�޵׶�")
					monster = Monster("��ӿ����");

				else
					monster = Monster("���þ�");

				monster.show();

				int attack_power0 = attack_power;

				while (1)
				{
					cout << "ս���Աȣ�" << endl;
					cout << setiosflags(ios_base::left) << setw(10) << "��ɫ" << setw(10) << "����ֵ" << setw(10) << "������" << setw(10) << "������" << endl;
					cout << setiosflags(ios_base::left) << setw(10) << name << setw(10) << health_points << setw(10) << attack_power << setw(10) << defensive_power << endl;
					cout << setiosflags(ios_base::left) << setw(10) << monster.get_name() << setw(10) << monster.get_health_points() << setw(10) << monster.get_attack_power() << setw(10) << monster.get_defensive_power() << endl;
					cout << endl;

					cout << "��ѡ�������" << endl;
					cout << "0.����" << endl;
					cout << "1.����ս��" << endl;
					cout << endl;

					int choice = 0;
					input_int(choice, 0, 1);

					system("cls");

					if (choice == 0)
					{
						system("cls");
						cout << "���ѳɹ�" << endl;
						cout << endl;
						break;
					}	
					else
					{
						attack(monster);
						if (monster.get_health_points() == 1)
						{
							change_barrier(monster);
							cout << "���ѳɹ�����" << monster.get_name() << "��" << endl;
							cout << "��ý�ң�" << monster.get_lose_gold() << endl;
							add_gold(monster.get_lose_gold());
							add_experience(monster.get_lose_experience());
							if (if_success())
							{
								location == "��������";
								cout << "���ѳɹ�ͨ�����йؿ���Ѱ��ȫ���澭�����ض������ƣ�" << endl;
							}
							cout << endl;
							break;
						}

						monster.attack(*this);
						if (get_health_points() == 1)
						{
							cout << "���ѱ����ܣ�" << endl;
							cout << "�Ƿ񸴻�?" << endl;
							cout << "0.��" << endl;
							cout << "1.��" << endl;
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
									cout << "���Ѹ���������Ϸ" << endl;
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
			Monster monster("���ܾ�");

			if (location == "�ڷ�ɽ�ڷ綴")
				monster = Monster("���ܾ�");

			else if (location == "�Ʒ���Ʒ綴")
				monster = Monster("�Ʒ��");

			else if (location == "����ɽ�׹Ƕ�")
				monster = Monster("�׹Ƿ���");

			else if (location == "��ɽ���ɽ����ƶ�")
				monster = Monster("ʥӤ����");

			else if (location == "����ɽ���ö�")
				monster = Monster("ЫŮ��");

			else if (location == "����ɽˮ����")
				monster = Monster("����⨺�");

			else if (location == "С����С������")
				monster = Monster("��ü����");

			else if (location == "�ݿ�ɽ�޵׶�")
				monster = Monster("��ӿ����");

			else
				monster = Monster("���þ�");

			monster.show();

			int attack_power0 = attack_power;

			while (1)
			{
				cout << "ս���Աȣ�" << endl;
				cout << setiosflags(ios_base::left) << setw(10) << "��ɫ" << setw(10) << "����ֵ" << setw(10) << "������" << setw(10) << "������" << endl;
				cout << setiosflags(ios_base::left) << setw(10) << name << setw(10) << health_points << setw(10) << attack_power << setw(10) << defensive_power << endl;
				cout << setiosflags(ios_base::left) << setw(10) << monster.get_name() << setw(10) << monster.get_health_points() << setw(10) << monster.get_attack_power() << setw(10) << monster.get_defensive_power() << endl;
				cout << endl;
				
				cout << "��ѡ�������" << endl;
				cout << "0.����" << endl;
				cout << "1.����ս��" << endl;
				cout << endl;

				int choice = 0;
				input_int(choice, 0, 1);

				system("cls");

				if (choice == 0)
				{
					system("cls");
					cout << "���ѳɹ�" << endl;
					cout << endl;
					break;
				}
				else
				{
					attack(monster);
					if (monster.get_health_points() == 1)
					{
						change_barrier(monster);
						cout << "���ѳɹ�����" << monster.get_name() << "��" << endl;
						cout << "��ý�ң�" << monster.get_lose_gold() << endl;
						add_gold(monster.get_lose_gold());
						add_experience(monster.get_lose_experience());
						if (if_success())
						{
							location == "��������";
							cout << "���ѳɹ�ͨ�����йؿ���Ѱ��ȫ���澭�����ض������ƣ�" << endl;
							cout << endl;
						}
						cout << endl;
						break;
					}

					monster.attack(*this);
					if (get_health_points() == 1)
					{
						cout << "���ѱ����ܣ�" << endl;
						cout << "�Ƿ񸴻�?" << endl;
						cout << "0.��" << endl;
						cout << "1.��" << endl;
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
								cout << "���Ѹ���������Ϸ" << endl;
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

void Hero::read_file()//���ļ�
{
	ifstream ifs;

	if (name == "������")
		ifs.open("������.dat", ios_base::in | ios_base::binary);
	else if (name == "�����")
		ifs.open("�����.dat", ios_base::in | ios_base::binary);
	else if (name == "������")
		ifs.open("������.dat", ios_base::in | ios_base::binary);
	else
		ifs.open("ɳ��.dat", ios_base::in | ios_base::binary);

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

void Hero::write_file()//д�ļ�
{
	ofstream ofs;

	if (name == "������")
		ofs.open("������.dat", ios_base::out | ios_base::binary);
	else if (name == "�����")
		ofs.open("�����.dat", ios_base::out | ios_base::binary);
	else if (name == "������")
		ofs.open("������.dat", ios_base::out | ios_base::binary);
	else
		ofs.open("ɳ��.dat", ios_base::out | ios_base::binary);

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

Hero::~Hero()//�����������浵��
{
	write_file();
}
