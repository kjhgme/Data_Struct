// 3�� 13��, 20�� test. 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void FirstPlace();
void Produce(char type, int x, int y, char* name);

void ShowOrderList();
void Order(char* order);
void Display();
void DestroyAll(int x, int y, int x2, int y2);
void GetDistance(int x, int y, int x2, int y2);
void FindWeakEnemy(int x, int y, int distance);
void SortByDistance(int x, int y);


struct Unit {
	char type;
	char tribe;
	int HP;
	int MP;
	int Distance;
	int AttackDistance;
	int AttackDamage;
	int UsingMP;
	int AttackRange;
	int Minerals;
	int PositionX;
	int PositionY;
	char* name = " ";
};

Unit init = { ' ', ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " " };
Unit Hydra = { 'H', 'Z', 50, 0, 3, 5, 25, 0, 1, 1 };
Unit Queen = { 'Q', 'Z', 70, 150, 6, 15, 1000, 45, 1, 2 };
Unit Defiler = { 'D', 'Z', 60, 200, 2, 1, 1, 60, 5, 2 };
Unit Marin = { 'M', 'T', 30, 0, 3, 4, 20, 0, 1, 1 };
Unit Tank = { 'T', 'T', 120, 0, 4, 17, 40, 0, 1, 2 };
Unit Vessel = { 'V', 'T', 80, 140, 5, 12, 50, 35, 3, 2 };

Unit map[20][40];
Unit tempList[800];
int tempDistance[800];

char* OrderList[5]{ "p 1 1", "s 1 1", "m 1 1" };

int main()
{
	char command{};
	char* order = new char[10];
	int x{};
	int y{};
	int x2{};
	int y2{};
	int distance{};


	FirstPlace();
	Display();

	while (true)
	{
		cout << endl;
		cout << "1: ShowOrderList" << endl;
		cout << "2: Order" << endl;
		cout << "3: Display" << endl;
		cout << "4: DestroyAll" << endl;
		cout << "5: GetDistance" << endl;
		cout << "6: FindWeakEnemy" << endl;
		cout << "7: SortByDistance" << endl;
		cout << "8: Quit" << endl;
		cout << "Ŀ�ǵ带 �Է����ּ��� : ";
		cin >> command;

		switch (command)
		{
		case '1':
			ShowOrderList();
			break;
		case '2':
			cout << "�߰��Ͻ� ����� �Է����ּ���(p: ����, s/S: ����, a: ����, m: �̵�) : ";
			scanf(" %[^\n]s", order);
			Order(order);
			break;
		case '3':
			Display();
			break;
		case '4':
			cout << "���� ���� ������ ��� �ı��մϴ�.(ex. 1 1 4 4) : ";
			cin >> x >> y >> x2 >> y2;
			DestroyAll(x, y, x2, y2);
			break;
		case '5':
			cout << "�� ��ǥ���� �Ÿ��� ����մϴ�.(ex. 1 1 4 4) : ";
			cin >> x >> y >> x2 >> y2;
			GetDistance(x, y, x2, y2);
			break;
		case '6':
			cout << "�־��� ��ǥ�κ��� �־��� �Ÿ����� �ִ� ���ֵ� �� ���� HP�� ���� ������ ������ ����մϴ�. (ex.1 1 5) : ";
			cin >> x >> y >> distance;
			FindWeakEnemy(x, y, distance);
			break;
		case '7':
			cout << "�־��� ��ǥ�� ����� �ͺ��� ������� ����մϴ�. �Ÿ��� ������ ID������ ����մϴ�. (ex. 1 1) : ";
			cin >> x >> y;
			SortByDistance(x, y);
			break;
		case '8':
			cout << "�̴Ͻ�Ÿ�� �����մϴ�." << endl;
			return 0;
			break;
		default:
			break;
		}
	}
}

void FirstPlace()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 40; ++j)
		{
			map[i][j] = init;
		}
	}

	Produce('M', 0, 0, "M01");
	Produce('M', 1, 0, "M02");
	Produce('M', 2, 0, "M03");
	Produce('V', 2, 1, "V01");
	Produce('V', 2, 2, "V02");
	Produce('T', 3, 0, "T01");
	Produce('M', 3, 1, "M04");
	Produce('T', 4, 0, "T02");
	Produce('M', 4, 1, "M05");
	Produce('M', 5, 0, "M06");


	Produce('H', 19, 39, "H01");
	Produce('H', 18, 39, "H02");
	Produce('H', 17, 37, "H03");
	Produce('Q', 17, 38, "Q01");
	Produce('Q', 17, 39, "Q02");
	Produce('H', 16, 38, "H04");
	Produce('D', 16, 39, "D01");
	Produce('H', 15, 38, "H05");
	Produce('D', 15, 39, "D02");
	Produce('H', 14, 39, "H06");
}

void Produce(char type, int x, int y, char* name)
{
	char* tempName = new char[10];
	strcpy(tempName, name);

	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		if (map[x][y].type == ' ')
		{
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 40; ++j)
				{
					if (map[i][j].name == tempName) {
						cout << "���� �̸��� ������ �ִ� ������ �����մϴ�." << endl;
						goto cantProduce;
					}
				}
			}

			switch (type)
			{
			case 'H':
				map[x][y] = Hydra;
				break;
			case 'Q':
				map[x][y] = Queen;
				break;
			case 'D':
				map[x][y] = Defiler;
				break;
			case 'M':
				map[x][y] = Marin;
				break;
			case 'T':
				map[x][y] = Tank;
				break;
			case 'V':
				map[x][y] = Vessel;
				break;
			default:
				cout << "�ش� ����Ÿ���� �������� �ʽ��ϴ�." << endl;
				break;
			}
			map[x][y].PositionX = x;
			map[x][y].PositionY = y;
			map[x][y].name = tempName;

		}
		else
		{
			cout << "�ش� ��ġ���� ������ �̹� �����ϰų� �����Ұ����� ��ġ�Դϴ�." << endl;
		}
	}

cantProduce:
	{

	}
}

void ShowOrderList()
{
	for (int i = 0; i < sizeof(OrderList)/sizeof(char*); ++i)
	{
		if (OrderList[i] == NULL)
			break;
		cout << OrderList[i] << endl;
	}
}

void Order(char* order)
{
	char* tempOrder = new char[10];
	strcpy(tempOrder, order);

	for (int i = 0; i < sizeof(OrderList) / sizeof(char*); ++i)
	{
		if (OrderList[i] == NULL)
		{
			if (order[0] == 'p') {
				cout << "-Produce-" << endl;
				OrderList[i] = tempOrder;
			}
			else if (order[0] == 's') {
				cout << "-Select-" << endl;
				OrderList[i] = tempOrder;
			}
			else if (order[0] == 'S') {
				cout << "-SelectAll-" << endl;
				OrderList[i] = tempOrder;
			}
			else if (order[0] == 'a') {
				cout << "-Attack-" << endl;
				OrderList[i] = tempOrder;
			}
			else if (order[0] == 'm') {
				cout << "-Move-" << endl;
				OrderList[i] = tempOrder;
			}
			else {
				cout << "���� ��ɾ��Դϴ�." << endl;
			}
			break;
		}
		else if (i == sizeof(OrderList) / sizeof(char*)-1 && OrderList[i] != NULL)
		{
			cout << "�� �̻� ����� �߰��� �� �����ϴ�." << endl;
		}
	}

	
}

void Display()
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 40; ++j) {
			cout << map[i][j].type;
		}
		cout << endl;
	}
}

void DestroyAll(int x, int y, int x2, int y2)
{
	int BigX{};
	int BigY{};
	int SmallX{};
	int SmallY{};

	if (x >= 20 || x < 0 || y < 0 || y >= 40
		|| x2 >= 20 || x2 < 0 || y2 < 0 || y2 >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		if (x >= x2)
		{
			BigX = x;
			SmallX = x2;
		}
		else {
			BigX = x2;
			SmallX = x;
		}

		if (y >= y2)
		{
			BigY = y;
			SmallY = y2;
		}
		else {
			BigY = y2;
			SmallY = y;
		}

		for (int i = SmallX; i <= BigX; ++i)
		{
			for (int j = SmallY; j <= BigY; ++j)
			{
				map[i][j] = init;
			}
		}

		cout << "��! �ش� ������ ���ֵ��� �ı��߽��ϴ�." << endl;
	}
}

void GetDistance(int x, int y, int x2, int y2)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40
		|| x2 >= 20 || x2 < 0 || y2 < 0 || y2 >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		if (abs(x-x2) >= abs(y-y2))
			cout << "�� ��ǥ���� �Ÿ��� " << abs(x-x2) << "�Դϴ�." << endl;
		else
			cout << "�� ��ǥ���� �Ÿ��� " << abs(y-y2) << "�Դϴ�." << endl;
	}
}

void FindWeakEnemy(int x, int y, int distance)
{
	int tempHP = 999;
	bool IsFindedEnemy = false;

	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else if (map[x][y].tribe == ' ') {
		cout << "�ش� ��ǥ�� ������ �������� �ʽ��ϴ�." << endl;
	}
	else {
		for (int i = x - distance; i < x + distance; ++i)
		{
			for (int j = y - distance; j < y + distance; ++j)
			{
				if (i >= 0 && i < 20 && j >= 0 && j < 40)
				{
					if (map[x][y].tribe == 'Z')
					{
						if (map[i][j].tribe == 'T' && map[i][j].HP < tempHP)
							tempHP = map[i][j].HP;
					}
					else if (map[x][y].tribe == 'T')
					{
						if (map[i][j].tribe == 'Z' && map[i][j].HP < tempHP)
							tempHP = map[i][j].HP;
					}
				}
			}
		}

		for (int i = x - distance; i < x + distance; ++i)
		{
			for (int j = y - distance; j < y + distance; ++j)
			{
				if (i >= 0 && i < 20 && j >= 0 && j < 40)
				{
					if (map[i][j].type != ' ' && map[i][j].HP == tempHP)
					{
						cout << "������ ���� : " << map[i][j].tribe << endl;
						cout << "������ Ÿ�� : " << map[i][j].type << endl;
						cout << "������ HP : " << map[i][j].HP << endl;
						cout << "������ MP : " << map[i][j].MP << endl;
						cout << "������ �̵��Ÿ� : " << map[i][j].Distance << endl;
						cout << "������ ��Ÿ� : " << map[i][j].AttackDistance << endl;
						cout << "������ ���ݷ� : " << map[i][j].AttackDamage << endl;
						cout << "������ �Ҹ�MP : " << map[i][j].UsingMP << endl;
						cout << "������ ���ݹ��� : " << map[i][j].AttackRange << endl;
						cout << "������ ����� �Ҹ� �ൿ�� : " << map[i][j].Minerals << endl;
						cout << "������ ��ġ : ( " << map[i][j].PositionX << ", " << map[i][j].PositionY << " )" << endl;
						cout << "������ �̸� : " << map[i][j].name << endl;
						cout << endl;

						IsFindedEnemy = true;
					}
				}
			}
		}
	}

	if (IsFindedEnemy == false)
		cout << "�����ȿ� �� ������ �������� �ʽ��ϴ�." << endl;
}

void SortByDistance(int x, int y)
{
	int distance{};
	Unit temp{init};

	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		for (int i = 0; i < 800; ++i)
		{
			tempList[i] = init;
		}

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 40; ++j)
			{
				if (map[i][j].type != ' ')
				{
					if (x == i && y == j)
						break;

					if (abs(map[x][y].PositionX - map[i][j].PositionX) > abs(map[x][y].PositionY - map[i][j].PositionY))
					{
						distance = abs(map[x][y].PositionX - map[i][j].PositionX);
						temp = map[i][j];
					}
					else {
						distance = abs(map[x][y].PositionY - map[i][j].PositionY);
						temp = map[i][j];
					}

					for (int a = 0; a < sizeof(tempDistance) / sizeof(int); ++a)
					{
						if (tempDistance[a] == 0)
						{
							tempDistance[a] = distance;
							tempList[a] = temp;
							break;
						}
					}
				}
			}
		}
	}

	for (int a = 0; a < sizeof(tempDistance) / sizeof(int); ++a)
	{
		if (tempDistance[a] == 0)
		{
			break;
		}
		else {
			cout << tempDistance[a] << endl;
		}
	}
}