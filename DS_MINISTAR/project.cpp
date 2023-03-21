// 3�� 13��, 20�� test. 
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void FirstPlace();
void Display();
void Produce(char type, int x, int y, char* name);
void Select(int x, int y);
void SelectAll(int x, int y, int x2, int y2);
void Destroy(int x, int y);
void FindTarget(int x, int y);
void SortByID();

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

int main()
{
	char command{};
	char type{};
	int x{};
	int y{};
	int x2{};
	int y2{};
	char* name = new char[10];

	FirstPlace();
	Display();

	while (true)
	{
		cout << endl;
		cout << "1: Display" << endl;
		cout << "2: Produce" << endl;
		cout << "3: Select" << endl;
		cout << "4: SelectAll" << endl;
		cout << "5: Destroy" << endl;
		cout << "6: FindTarget" << endl;
		cout << "7: SortByID" << endl;
		cout << "8: Quit" << endl;
		cout << "Ŀ�ǵ带 �Է����ּ��� : ";
		cin >> command;

		switch (command)
		{
		case '1':
			Display();
			break;
		case '2':
			cout << "-Produce-" << endl;
			cout << "������ Ÿ��, ��ǥ, ������ �̸��� �Է����ּ���. (ex. H 1 1 H01) : ";
			cin >> type >> x >> y >> name;
			Produce(type, x, y, name);
			break;
		case '3':
			cout << "-Select-" << endl;
			cout << "��ǥ ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			Select(x, y);
			break;
		case '4':
			cout << "-SelectAll-" << endl;
			cout << "��ǥ( x, y, x2, y2 )�� �Է����ּ���. (ex. 1 1 2 2) : ";
			cin >> x >> y >> x2 >> y2;
			SelectAll(x, y, x2, y2);
			break;
		case '5':
			cout << "-Destroy-" << endl;
			cout << "��ǥ ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			Destroy(x, y);
			break;
		case '6':
			cout << "-FindTarget-" << endl;
			cout << "��ǥ ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			FindTarget(x, y);
			break;
		case '7':
			cout << "-SortByID-" << endl;
			SortByID();
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

void Display()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 40; ++j)
		{
			cout << map[i][j].type;
		}
		cout << endl;
	}
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

void Select(int x, int y)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else
	{
		if (map[x][y].type == ' ')
			cout << "�ش� ��ġ���� ������ �������� �ʽ��ϴ�." << endl;
		else {
			cout << "������ ���� : " << map[x][y].tribe << endl;
			cout << "������ Ÿ�� : " << map[x][y].type << endl;
			cout << "������ HP : " << map[x][y].HP << endl;
			cout << "������ MP : " << map[x][y].MP << endl;
			cout << "������ �̵��Ÿ� : " << map[x][y].Distance << endl;
			cout << "������ ��Ÿ� : " << map[x][y].AttackDistance << endl;
			cout << "������ ���ݷ� : " << map[x][y].AttackDamage << endl;
			cout << "������ �Ҹ�MP : " << map[x][y].UsingMP << endl;
			cout << "������ ���ݹ��� : " << map[x][y].AttackRange << endl;
			cout << "������ ����� �Ҹ� �ൿ�� : " << map[x][y].Minerals << endl;
			cout << "������ ��ġ : ( " << map[x][y].PositionX << ", " << map[x][y].PositionY << " )" << endl;
			cout << "������ �̸� : " << map[x][y].name << endl;
			cout << endl;
		}
	}
}

void SelectAll(int x, int y, int x2, int y2)
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
				if (map[i][j].type != ' ')
					Select(i, j);
			}
		}
	}
}

void Destroy(int x, int y)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else
		map[x][y] = init;
}

void FindTarget(int x, int y)
{
	int nearest{ 100 };
	int distance{};
	int nearestX{};
	int nearestY{};

	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		if (map[x][y].type == ' ')
		{
			cout << "�ش� ��ġ�� ������ �������� �ʽ��ϴ�." << endl;
		}
		else {
			if (map[x][y].tribe == 'Z')
			{
				for (int i = 0; i < 20; ++i)
				{
					for (int j = 0; j < 40; ++j)
					{
						if (map[i][j].tribe == 'T')
						{
							if (abs(x - i) >= abs(y - j))
								distance = abs(x - i);
							else
								distance = abs(y - j);

							if (distance <= nearest)
							{
								nearest = distance;
								nearestX = i;
								nearestY = j;
							}
						}
					}
				}

				Select(nearestX, nearestY);
			}
			else if (map[x][y].tribe == 'T')
			{
				for (int i = 0; i < 20; ++i)
				{
					for (int j = 0; j < 40; ++j)
					{
						if (map[i][j].tribe == 'Z')
						{
							if (abs(x - i) >= abs(y - j))
								distance = abs(x - i);
							else
								distance = abs(y - j);

							if (distance <= nearest)
							{
								nearest = distance;
								nearestX = i;
								nearestY = j;
							}
						}
					}
				}

				Select(nearestX, nearestY);
			}
		}
	}
}

void SortByID()
{
	int len = 0;

	while (len < 10)
	{
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 40; ++j)
			{
				if (strlen(map[i][j].name) == len && map[i][j].type != ' ')
				{
					cout << map[i][j].name << endl;
				}
			}
		}

		len++;
	}
}

