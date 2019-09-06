#include  <iostream>
#include "Role.h"

using namespace std;

Role::Role(string name0) :name(name0), max_health_points(1), basic_attack_power(1), basic_defensive_power(1),
health_points(1), attack_power(1), defensive_power(1), location("��������"){}//���캯��

void Role::start(){}//��ʼ

bool Role::operator==(Role& role) const//����==�����
{
	if (name == role.get_name())
		return true;
	else
		return false;
}

string Role::get_name() const { return name; }//�������

int Role::get_max_health_points() const { return max_health_points; }//����������ֵ

int Role::get_basic_attack_power() const { return basic_attack_power; }//��û���������

int Role::get_basic_defensive_power() const { return basic_defensive_power; }//��û���������

int Role::get_health_points() const { return health_points; }//��õ�ǰ����ֵ

int Role::get_attack_power() const { return attack_power; }//��õ�ǰ������

int Role::get_defensive_power() const { return defensive_power; }//��õ�ǰ������

string Role::get_location() const { return location; }//���λ��

void Role::change_health_points(int health_points0)//�ı�����ֵ
{
	int health_points1 = health_points + health_points0;

	if (health_points1 > 0 && health_points1 < max_health_points)
		health_points = health_points1;
	else if (health_points1 <= 0)
		health_points = 1;
	else
		health_points = max_health_points;
}

void Role::change_attack_power(int attack_power0)//�ı乥����
{
	int attack_power1 = attack_power + attack_power0;

	attack_power = attack_power1 > 0 ? attack_power1 : 1;
}

void Role::change_defensive_power(int defensive_power0)//�ı������
{
	int defensive_power1 = defensive_power + defensive_power0;

	defensive_power = defensive_power1 > 0 ? defensive_power1 : 1;
}

void Role::introduction() const//��ɫ���
{
	if (name == "������")
	{
		cout << "�������ն����㣬���¿�����þ͡�" << endl;
		cout << "�Թ�������Ǭ������ʷ׷������档" << endl;
		cout << "�������������ţ������ߴ�ǰ��" << endl;
		cout << "����������رߣ�����ϡ������塣" << endl;
		cout << "�˱�ױ����ť˿�����������޿ۡ�" << endl;
		cout << "�����С�иߵͣ������𱰷����ҡ�" << endl;
		cout << "���ʷ�ʦ����Ե����ǰ���￰���ܡ�" << endl;
		cout << "���缫�ֻ��޺���������������㡣" << endl;
		cout << "���ȶ������Ż�����¬ñӳ����" << endl;
		cout << "��Ϊ���Ӳ��鴫��ʤ��������թ����" << endl;
	}

	else if (name == "�����")
	{
		cout << "�Ʒ��𹿣��𾦻��ۣ�" << endl;
		cout << "������ֱ�֣���ϵ��Ƥȹ��" << endl;
		cout << "����һ��������������̤һ˫��Ƥѥ��" << endl;
		cout << "ë���׹��죬˷�������ǣ�" << endl;
		cout << "�����­���������������" << endl;
	}

	else if (name == "������")
	{
		cout << "������������㣬������������ơ�" << endl;
		cout << "һ˫Բ�۹���磬�����ȷ���������" << endl;
		cout << "�Ժ��׳�������������Ƥ��񮻹�ࡣ" << endl;
	}

	else if (name == "ɳ��")
	{
		cout << "һͷ���淢���ɣ���ֻԲ�����Ƶơ�" << endl;
		cout << "���ڲ��������������������������" << endl;
		cout << "����һ����멣���������¶���١�" << endl;
		cout << "�����������Ÿ����ֱֳ�������ɡ�" << endl;
	}

	else if (name == "���ܾ�")
	{
		cout << "������������⣬�ڽ��������Ի͡�" << endl;
		cout << "�������ַ綵�䣬����˿�����볤��" << endl;
		cout << "��ִ��ӧǹһ�ˣ���̤��Ƥѥһ˫��" << endl;
		cout << "�ۻϽ��糸�磬����ɽ�кڷ�����" << endl;
	}

	else if (name == "�Ʒ��")
	{
		cout << "������գ�������⡣" << endl;
		cout << "����ӧƮɽ��β�������ּ׵���ơ�" << endl;
		cout << "�ռ�������ҫ�ʣ����ľ����ۻԻ͡�" << endl;
		cout << "¹Ƥѥ������Ⱦɫ��" << endl;
		cout << "��Χȹ����Ҷ��ױ��" << endl;
		cout << "�ֳ����ɸֲ��������ǵ�����ʥ�ɡ�" << endl;
	}

	else if (name == "�׹Ƿ���")
	{
	cout << "ʥɮЪ����ɽ�ң�����ȹ��Ů��ǰ��" << endl;
	cout << "������ҡ��������ȹбק�Խ�����" << endl;
	cout << "�������滨��¶��������ü�����̡�" << endl;
	cout << "��ϸ�����ۿ�����������������ߡ�" << endl;
	}

	else if (name == "ʥӤ����")
	{
	cout << "���������ְף�����Ϳ��һ��š�" << endl;
	cout << "���������۵�Ⱦ��ü�������Ƶ��á�" << endl;
	cout << "սȹ����������α���߸����̬��" << endl;
	cout << "˫�ִ�ǹ����������⻤���������" << endl;
	cout << "�����������׺𣬱������糸��ԡ�" << endl;
	cout << "Ҫʶ��ħ�����ϣ�����ǧ�Ż��캢��" << endl;
	}

	else if (name == "ЫŮ��")
	{
	cout << "���彿�ݣ�������ò��" << endl;
	cout << "������ʩ�����ȣ�����ʮָ���ˣ�" << endl;
	cout << "�������㣬�����ޱߣ�������塣" << endl;
	}

	else if (name == "����⨺�")
	{
	cout << "���������ܲ���֪ǰ�����������" << endl;
	cout << "�����ͬ��ͬ����" << endl;
	}

	else if (name == "��ü����")
	{
	cout << "ԭ���Ƕ�������Ц���������ͯ�ӣ���ʹһ��������鳱�ɶ�����������" << endl;
	cout << "���÷��治�ڼ�ʱ��͵�˽��ࡢ�������ִ������������½�ɾ���" << endl;
	}

	else if (name == "��ӿ����")
	{
	cout << "���������ƶ�ѻ���������޻��ȼס�" << endl;
	cout << "һ�Խ����հ��ۣ�ʮָ��ͬ���񷢡�" << endl;
	cout << "���ŷ��������裬�촽һ��ӣ�һ���" << endl;
	cout << "�˶����������ˣ������϶�ϲǡ��" << endl;
	cout << "��ɮħ�������ޣ��������ʵ�ɿ䡣" << endl;
	cout << "������ü����Ҷ��ӯӯ�������һ���" << endl;
	cout << "��Ь΢¶˫������ٸ�������ѻ��" << endl;
	cout << "��Ц��ʦЯ�ִ�����Ʈ���������ġ�" << endl;
	}

	else
	{
		cout << "���þ�ԭ�ǹ㺮����ҩ�����ã��ڹ㺮��ʱ���ض����Ӵ���һȭ��������ޡ�" << endl;
		cout << "�ض��½�Ͷ�����ù����ң�����Ϊ��˽��Ҳ˽���½磬��ëӱɽ���������֣�" << endl;
		cout << "��ʹһ�����е�ҩ�ƵĶ̹������ڱ仯��" << endl;
	}

	cout << endl;
}

void Role::show() const//��ʾ��Ϣ
{
	cout << "��ɫ��" << name << endl;
	cout << endl;
	introduction();
	cout << "�������ֵ��" << max_health_points << endl;
	cout << "������������"<< basic_attack_power <<endl;
	cout << "������������"<< basic_defensive_power <<endl;
	cout << "��ǰ����ֵ��" << health_points << endl;
	cout << "��ǰ��������" << attack_power << endl;
	cout << "��ǰ��������" << defensive_power << endl;
	cout << "λ�ã�" << location << endl;
}

void Role::attack(Role& role0) {}//����