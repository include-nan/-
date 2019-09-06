#include  <iostream>
#include "Role.h"

using namespace std;

Role::Role(string name0) :name(name0), max_health_points(1), basic_attack_power(1), basic_defensive_power(1),
health_points(1), attack_power(1), defensive_power(1), location("东土大唐"){}//构造函数

void Role::start(){}//初始

bool Role::operator==(Role& role) const//重载==运算符
{
	if (name == role.get_name())
		return true;
	else
		return false;
}

string Role::get_name() const { return name; }//获得名字

int Role::get_max_health_points() const { return max_health_points; }//获得最大生命值

int Role::get_basic_attack_power() const { return basic_attack_power; }//获得基础攻击力

int Role::get_basic_defensive_power() const { return basic_defensive_power; }//获得基础防御力

int Role::get_health_points() const { return health_points; }//获得当前生命值

int Role::get_attack_power() const { return attack_power; }//获得当前攻击力

int Role::get_defensive_power() const { return defensive_power; }//获得当前防御力

string Role::get_location() const { return location; }//获得位置

void Role::change_health_points(int health_points0)//改变生命值
{
	int health_points1 = health_points + health_points0;

	if (health_points1 > 0 && health_points1 < max_health_points)
		health_points = health_points1;
	else if (health_points1 <= 0)
		health_points = 1;
	else
		health_points = max_health_points;
}

void Role::change_attack_power(int attack_power0)//改变攻击力
{
	int attack_power1 = attack_power + attack_power0;

	attack_power = attack_power1 > 0 ? attack_power1 : 1;
}

void Role::change_defensive_power(int defensive_power0)//改变防御力
{
	int defensive_power1 = defensive_power + defensive_power0;

	defensive_power = defensive_power1 > 0 ? defensive_power1 : 1;
}

void Role::introduction() const//角色简介
{
	if (name == "唐三藏")
	{
		cout << "凛凛威颜多雅秀，佛衣可体如裁就。" << endl;
		cout << "辉光艳艳满乾坤，结彩纷纷凝宇宙。" << endl;
		cout << "朗朗明珠上下排，层层金线穿前后。" << endl;
		cout << "兜罗四面锦沿边，万样稀奇铺绮绣。" << endl;
		cout << "八宝妆花缚钮丝，金环束领攀绒扣。" << endl;
		cout << "佛天大小列高低，星象尊卑分左右。" << endl;
		cout << "玄奘法师大有缘，现前此物堪承受。" << endl;
		cout << "浑如极乐活罗汉，赛过西方真觉秀。" << endl;
		cout << "锡杖叮当斗九环，毗卢帽映多丰厚。" << endl;
		cout << "诚为佛子不虚传，胜似菩提无诈谬。" << endl;
	}

	else if (name == "孙悟空")
	{
		cout << "黄发金箍，金睛火眼；" << endl;
		cout << "身穿锦布直裰，腰系虎皮裙；" << endl;
		cout << "手拿一条儿金箍铁棒，足踏一双麂皮靴；" << endl;
		cout << "毛脸雷公嘴，朔腮别土星，" << endl;
		cout << "查耳额颅阔，獠牙向外生。" << endl;
	}

	else if (name == "猪悟能")
	{
		cout << "碓嘴初长三尺零，獠牙觜出赛银灯。" << endl;
		cout << "一双圆眼光如电，两耳扇风唿唿声。" << endl;
		cout << "脑后鬃长排铁箭，浑身皮糙癞还青。" << endl;
	}

	else if (name == "沙悟净")
	{
		cout << "一头红焰发蓬松，两只圆睛亮似灯。" << endl;
		cout << "不黑不青蓝靛脸，如雷如鼓老龙声。" << endl;
		cout << "身披一领鹅黄氅，腰束对攒露白藤。" << endl;
		cout << "顶下骷髅悬九个，手持宝杖甚峥嵘。" << endl;
	}

	else if (name == "黑熊精")
	{
		cout << "碗子铁盔火漆光，乌金铠甲亮辉煌。" << endl;
		cout << "皂罗袍罩风兜袖，黑绿丝绦麃穗长。" << endl;
		cout << "手执黑缨枪一杆，足踏乌皮靴一双。" << endl;
		cout << "眼幌金睛如掣电，正是山中黑风王。" << endl;
	}

	else if (name == "黄风怪")
	{
		cout << "金盔晃日，金甲凝光。" << endl;
		cout << "盔上缨飘山雉尾，罗袍罩甲淡鹅黄。" << endl;
		cout << "勒甲绦盘龙耀彩，护心镜绕眼辉煌。" << endl;
		cout << "鹿皮靴，槐花染色；" << endl;
		cout << "锦围裙，柳叶绒妆。" << endl;
		cout << "手持三股钢叉利，不亚当年显圣郎。" << endl;
	}

	else if (name == "白骨夫人")
	{
	cout << "圣僧歇马在山岩，忽见裙钗女近前。" << endl;
	cout << "翠袖轻摇笼玉笋，湘裙斜拽显金莲。" << endl;
	cout << "汗流粉面花含露，尘拂峨眉柳带烟。" << endl;
	cout << "仔细定睛观看处，看看行至到身边。" << endl;
	}

	else if (name == "圣婴大王")
	{
	cout << "面如敷粉三分白，唇若涂朱一表才。" << endl;
	cout << "鬓挽青云欺靛染，眉分新月似刀裁。" << endl;
	cout << "战裙巧绣盘龙凤，形比哪吒更富态。" << endl;
	cout << "双手绰枪威凛冽，祥光护体出门来。" << endl;
	cout << "哏声响若春雷吼，暴眼明如掣电乖。" << endl;
	cout << "要识此魔真姓氏，名扬千古唤红孩。" << endl;
	}

	else if (name == "蝎女妖")
	{
	cout << "锦绣娇容，金珠美貌，" << endl;
	cout << "美若西施还袅娜，春葱十指纤纤，" << endl;
	cout << "软玉温香，春意无边，肌香肤腻。" << endl;
	}

	else if (name == "六耳猕猴")
	{
	cout << "善聆音，能察理，知前后，万物皆明。" << endl;
	cout << "与悟空同象同音。" << endl;
	}

	else if (name == "黄眉老祖")
	{
	cout << "原本是东来佛祖笑和尚敲磬的童子，手使一根由敲磬槌变成短软狼牙棒。" << endl;
	cout << "他趁佛祖不在家时，偷了金钹、后天人种袋两件宝贝，下界成精。" << endl;
	}

	else if (name == "地涌夫人")
	{
	cout << "发盘云髻似堆鸦，身着绿绒花比甲。" << endl;
	cout << "一对金莲刚半折，十指如同春笋发。" << endl;
	cout << "团团粉面若银盆，朱唇一似樱桃滑。" << endl;
	cout << "端端正正美人姿，月里嫦娥还喜恰。" << endl;
	cout << "真僧魔苦遇娇娃，妖怪娉婷实可夸。" << endl;
	cout << "淡淡翠眉分柳叶，盈盈丹脸衬桃花。" << endl;
	cout << "绣鞋微露双钩凤，云髻高盘两鬓鸦。" << endl;
	cout << "含笑与师携手处，香飘兰麝满袈裟。" << endl;
	}

	else
	{
		cout << "玉兔精原是广寒宫捣药的玉兔，在广寒宫时被素娥仙子打了一拳，因而怀恨。" << endl;
		cout << "素娥下界投生天竺国皇室，玉兔为报私仇也私自下界，在毛颖山中兴妖作怪，" << endl;
		cout << "手使一条名叫捣药杵的短棍，善于变化。" << endl;
	}

	cout << endl;
}

void Role::show() const//显示信息
{
	cout << "角色：" << name << endl;
	cout << endl;
	introduction();
	cout << "最大生命值：" << max_health_points << endl;
	cout << "基础攻击力："<< basic_attack_power <<endl;
	cout << "基础防御力："<< basic_defensive_power <<endl;
	cout << "当前生命值：" << health_points << endl;
	cout << "当前攻击力：" << attack_power << endl;
	cout << "当前防御力：" << defensive_power << endl;
	cout << "位置：" << location << endl;
}

void Role::attack(Role& role0) {}//攻击