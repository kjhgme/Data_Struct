#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void Produce(char type, int x, int y, char* name);

void MakeUL();
void ShowUL();
void ShowUL_R(int i);
void Select_UL(int x, int y);
void Select_UL_R(int x, int y, int i);
void Destroy_UL(int x, int y);
void Destroy_UL_R(int x, int y, int i);
void DisplayMap_UL();

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

Unit init = { ' ', ' ', 0, 0, 0, 0, 0, 0, 0, 0, -2, -2, " " };
Unit Hydra = { 'H', 'Z', 50, 0, 3, 5, 25, 0, 1, 1 };
Unit Queen = { 'Q', 'Z', 70, 150, 6, 15, 1000, 45, 1, 2 };
Unit Defiler = { 'D', 'Z', 60, 200, 2, 1, 1, 60, 5, 2 };
Unit Marin = { 'M', 'T', 30, 0, 3, 4, 20, 0, 1, 1 };
Unit Tank = { 'T', 'T', 120, 0, 4, 17, 40, 0, 1, 2 };
Unit Vessel = { 'V', 'T', 80, 140, 5, 12, 50, 35, 3, 2 };

Unit unitlist[1000];
int unitCnt{};

int main()
{
	char command{};
	int x{}, y{};

	MakeUL();

	while (true)
	{
		cout << endl;
		cout << "_____Ŀ�ǵ�â_____" << endl;
		cout << "1: ShowUL" << endl;
		cout << "2: ShowUL_R" << endl;
		cout << "3: Select_UL" << endl;
		cout << "4: Select_UL_R" << endl;
		cout << "5: Destroy_UL" << endl;
		cout << "6: Destroy_UL_R" << endl;
		cout << "7: DisplayMap_UL" << endl;
		cout << "8: Quit" << endl;
		cout << "Ŀ�ǵ带 �Է����ּ��� : ";
		cin >> command;

		switch (command)
		{
		case '1':
			cout << "-ShowUL-" << endl;
			ShowUL();
			break;
		case '2':
			cout << "-ShowUL_R-" << endl;
			ShowUL_R(0);
			break;
		case '3':
			cout << "-Select_UL-" << endl;
			cout << "��ǥ ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			Select_UL(x, y);
			break;
		case '4':
			cout << "-Select_UL_R-" << endl;
			cout << "��ǥ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			Select_UL_R(x, y, 0);
			break;
		case '5':
			cout << "-Destroy_UL-" << endl;
			cout << "��ǥ ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			Destroy_UL(x, y);
			break;
		case '6':
			cout << "-Destroy_UL_R-" << endl;
			cout << "��ǥ ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
			cin >> x >> y;
			Destroy_UL_R(x, y, 0);
			break;
		case '7':
			cout << "-DisplayMap_UL-" << endl;
			DisplayMap_UL();
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

void Produce(char type, int x, int y, char* name)
{
	char* tempName = new char[10];
	strcpy(tempName, name);

	if (x >= 20 || x < -2 || y < -2 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		if (unitlist[unitCnt].PositionX == -2 && unitlist[unitCnt].PositionY == -2)
		{
			for (int i = 0; i <= unitCnt; ++i)
			{
				if (unitlist[i].name == tempName) {
					cout << "���� �̸��� ������ �ִ� ������ �����մϴ�." << endl;
					break;
				}
			}
			switch (type)
			{
			case 'H':
				unitlist[unitCnt] = Hydra;
				break;
			case 'Q':
				unitlist[unitCnt] = Queen;
				break;
			case 'D':
				unitlist[unitCnt] = Defiler;
				break;
			case 'M':
				unitlist[unitCnt] = Marin;
				break;
			case 'T':
				unitlist[unitCnt] = Tank;
				break;
			case 'V':
				unitlist[unitCnt] = Vessel;
				break;
			default:
				cout << "�ش� ����Ÿ���� �������� �ʽ��ϴ�." << endl;
				break;
			}
			unitlist[unitCnt].PositionX = x;
			unitlist[unitCnt].PositionY = y;
			unitlist[unitCnt].name = tempName;
			unitCnt++;
		}
		else
		{
			cout << "�ش� ��ġ���� ������ �̹� �����ϰų� �����Ұ����� ��ġ�Դϴ�." << endl;
		}
	}
}

void MakeUL()
{
	for (int i = 0; i < sizeof(unitlist) / sizeof(Unit); ++i)
	{
		unitlist[i] = init;
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


	unitlist[0].HP = 25;
	unitlist[1].HP = 20;
	unitlist[2].HP = 30;
	unitlist[3].HP = 80;
	unitlist[4].HP = 75;
	unitlist[5].HP = 120;
	unitlist[6].HP = 15;
	unitlist[7].HP = 50;
	unitlist[8].HP = 30;
	unitlist[9].HP = 27;

	unitlist[10].HP = 50;
	unitlist[11].HP = 47;
	unitlist[12].HP = 30;
	unitlist[13].HP = 70;
	unitlist[14].HP = 35;
	unitlist[15].HP = 20;
	unitlist[16].HP = 15;
	unitlist[17].HP = 45;
	unitlist[18].HP = 40;
	unitlist[19].HP = 50;
}

void ShowUL()
{
	for (int i = 0; i < sizeof(unitlist) / sizeof(Unit); ++i)
	{
		if (unitlist[i].type == ' ')
		{ }
		else
			cout << i + 1 << " : " << unitlist[i].name << endl;
	}
}

void ShowUL_R(int i)
{
	if (i == sizeof(unitlist) / sizeof(Unit))
		return;
	if (unitlist[i].type == ' ')
	{ }
	else
		cout << i+1 << " : " << unitlist[i].name << endl;
	i++;
	ShowUL_R(i);
}

void Select_UL(int x, int y)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		for (int i = 0; i < sizeof(unitlist) / sizeof(Unit); ++i)
		{
			if (unitlist[i].PositionX == x && unitlist[i].PositionY == y)
			{
				cout << "������ ���� : " << unitlist[i].tribe << endl;
				cout << "������ Ÿ�� : " << unitlist[i].type << endl;
				cout << "������ HP : " << unitlist[i].HP << endl;
				cout << "������ MP : " << unitlist[i].MP << endl;
				cout << "������ �̵��Ÿ� : " << unitlist[i].Distance << endl;
				cout << "������ ��Ÿ� : " << unitlist[i].AttackDistance << endl;
				cout << "������ ���ݷ� : " << unitlist[i].AttackDamage << endl;
				cout << "������ �Ҹ�MP : " << unitlist[i].UsingMP << endl;
				cout << "������ ���ݹ��� : " << unitlist[i].AttackRange << endl;
				cout << "������ ����� �Ҹ� �ൿ�� : " << unitlist[i].Minerals << endl;
				cout << "������ ��ġ : ( " << unitlist[i].PositionX << ", " << unitlist[i].PositionY << " )" << endl;
				cout << "������ �̸� : " << unitlist[i].name << endl;
				cout << endl;
				break;
			}
			else if (i == sizeof(unitlist) / sizeof(Unit) - 1)
			{
				cout << "�ش� ��ġ�� ������ �������� �ʽ��ϴ�." << endl;
			}
		}
	}
}

void Select_UL_R(int x, int y, int i)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
		return;
	}
	else {
		if (unitlist[i].PositionX == x && unitlist[i].PositionY == y)
		{
			cout << "������ ���� : " << unitlist[i].tribe << endl;
			cout << "������ Ÿ�� : " << unitlist[i].type << endl;
			cout << "������ HP : " << unitlist[i].HP << endl;
			cout << "������ MP : " << unitlist[i].MP << endl;
			cout << "������ �̵��Ÿ� : " << unitlist[i].Distance << endl;
			cout << "������ ��Ÿ� : " << unitlist[i].AttackDistance << endl;
			cout << "������ ���ݷ� : " << unitlist[i].AttackDamage << endl;
			cout << "������ �Ҹ�MP : " << unitlist[i].UsingMP << endl;
			cout << "������ ���ݹ��� : " << unitlist[i].AttackRange << endl;
			cout << "������ ����� �Ҹ� �ൿ�� : " << unitlist[i].Minerals << endl;
			cout << "������ ��ġ : ( " << unitlist[i].PositionX << ", " << unitlist[i].PositionY << " )" << endl;
			cout << "������ �̸� : " << unitlist[i].name << endl;
			cout << endl;
			return;
		}
		else if (i == sizeof(unitlist) / sizeof(Unit) - 1)
		{
			cout << "�ش� ��ġ�� ������ �������� �ʽ��ϴ�." << endl;
			return;
		}

		i++;
		Select_UL_R(x, y, i);
	}
}

void Destroy_UL(int x, int y)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
	}
	else {
		for (int i = 0; i < sizeof(unitlist) / sizeof(Unit); ++i)
		{
			if (unitlist[i].PositionX == x && unitlist[i].PositionY == y)
			{
				unitlist[i] = init;
				cout << "�ش� ��ġ�� ������ �׾����ϴ�." << endl;
				break;
			}
			else if (i == sizeof(unitlist) / sizeof(Unit) - 1)
			{
				cout << "�ش� ��ġ�� ������ �������� �ʽ��ϴ�." << endl;
			}
		}
	}
}

void Destroy_UL_R(int x, int y, int i)
{
	if (x >= 20 || x < 0 || y < 0 || y >= 40)
	{
		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
		return;
	}
	else {
		
		if (unitlist[i].PositionX == x && unitlist[i].PositionY == y)
		{
			unitlist[i] = init;
			cout << "�ش� ��ġ�� ������ �׾����ϴ�." << endl;
			return;
		}
		else if (i == sizeof(unitlist) / sizeof(Unit) - 1)
		{
			cout << "�ش� ��ġ�� ������ �������� �ʽ��ϴ�." << endl;
			return;
		}
		
	}

	i++;
	Destroy_UL_R(x, y, i);
}

void DisplayMap_UL()
{
	int num = 0;
	bool check = false;

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 40; ++j) {
			while (num < unitCnt)
			{
				if (unitlist[num].PositionX == i && unitlist[num].PositionY == j)
				{
					cout << unitlist[num].type;
					check = true;
					break;
				}
				else
					num++;
			}
			if(check == false)
				cout << ' ';

			num = 0;
			check = false;
		}
		cout << endl;
	}
}