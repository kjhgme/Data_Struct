//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//void Produce(char type, int x, int y, char* name);
//void MakeUL();
//
//void ShowUL_R(int i);
//void Produce_UL_R(char type, char tribe, int HP, int MP, int Distance, int AttackDistance, int AttackDamage, int UsingMP, int AttackRange, int Minerals, int PositionX, int PositionY, char* name, int i);
//void SelectAll_UL_R(int x, int y, int x2, int y2, int i);
//void Destroy_UL_R(int x, int y, int i);
//void FindWeakEnemy_R(int x, int y, int Distance, int i);
//void DisplayMap_UL();
//
//struct Unit {
//	char type;
//	char tribe;
//	int HP;
//	int MP;
//	int Distance;
//	int AttackDistance;
//	int AttackDamage;
//	int UsingMP;
//	int AttackRange;
//	int Minerals;
//	int PositionX;
//	int PositionY;
//	char* name = " ";
//};
//
//Unit init = { ' ', ' ', 0, 0, 0, 0, 0, 0, 0, 0, -2, -2, " " };
//Unit Hydra = { 'H', 'Z', 50, 0, 3, 5, 25, 0, 1, 1 };
//Unit Queen = { 'Q', 'Z', 70, 150, 6, 15, 1000, 45, 1, 2 };
//Unit Defiler = { 'D', 'Z', 60, 200, 2, 1, 1, 60, 5, 2 };
//Unit Marin = { 'M', 'T', 30, 0, 3, 4, 20, 0, 1, 1 };
//Unit Tank = { 'T', 'T', 120, 0, 4, 17, 40, 0, 1, 2 };
//Unit Vessel = { 'V', 'T', 80, 140, 5, 12, 50, 35, 3, 2 };
//
//Unit unitlist[1000];
//int unitCnt{};
//int lowHP{ 10000 };
//char SerchingTribe{};
//
//int main()
//{
//	char command{};
//	int x{}, y{}, x2{}, y2{};
//
//	char type{};
//	char tribe{};
//	int HP{};
//	int MP{};
//	int Distance{};
//	int AttackDistance{};
//	int AttackDamage{};
//	int UsingMP{};
//	int AttackRange{};
//	int Minerals{};
//	int PositionX{};
//	int PositionY{};
//	char* name = new char[10];
//
//	MakeUL();
//
//	while (true)
//	{
//		cout << endl;
//		cout << "_____Ŀ�ǵ�â_____" << endl;
//		cout << "1: ShowUL_R" << endl;
//		cout << "2: Produce_UL_R" << endl;
//		cout << "3: SelectAll_UL_R" << endl;
//		cout << "4: Destroy_UL_R" << endl;
//		cout << "5: FindWeakEnemy_R" << endl;
//		cout << "6: DisplayMap_UL" << endl;
//		cout << "7: Quit" << endl;
//		cout << "Ŀ�ǵ带 �Է����ּ��� : ";
//		cin >> command;
//
//		switch (command)
//		{
//		case '1':
//			cout << "-ShowUL_R-" << endl;
//			ShowUL_R(0);
//			break;
//		case '2':
//			cout << "-Produce_UL_R-" << endl;
//			cout << "������ ������ �Է����ּ���. (type, tribe, HP, MP, Distance, AttackDistance, AttackDamage, UsingMP, AttackRange, Minerals, PositionX, PositionY, name) : " << endl;
//			cin >> type >> tribe >> HP >> MP >> Distance >> AttackDistance >> AttackDamage >> UsingMP >> AttackRange >> Minerals >> PositionX >> PositionY >> name;
//			Produce_UL_R(type, tribe, HP, MP, Distance, AttackDistance, AttackDamage, UsingMP, AttackRange, Minerals, PositionX, PositionY, name, 0);
//			break;
//		case '3':
//			cout << "-SelectAll_UL_R-" << endl;
//			cout << "��ǥ ( x, y, x2, y2 )�� �Է����ּ���. (ex. 1 1 19 39) : ";
//			cin >> x >> y >> x2 >> y2;
//			SelectAll_UL_R(x, y, x2, y2, 0);
//			break;
//		case '4':
//			cout << "-Destroy_UL_R-" << endl;
//			cout << "��ǥ( x, y )�� �Է����ּ���. (ex. 1 1) : ";
//			cin >> x >> y;
//			Destroy_UL_R(x, y, 0);
//			break;
//		case '5':
//			cout << "-FindWeakEnemy_R-" << endl;
//			cout << "��ǥ ( x, y )�� �Ÿ��� �Է����ּ���. (ex. 1 1 5) : ";
//			cin >> x >> y >> Distance;
//			FindWeakEnemy_R(x, y, Distance, 0);
//			break;
//		case '6':
//			cout << "-DisplayMap_UL-" << endl;
//			DisplayMap_UL();
//			break;
//		case '7':
//			cout << "-�̴Ͻ�Ÿ�� �����մϴ�.-" << endl;
//			return 0;
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void Produce(char type, int x, int y, char* name)
//{
//	char* tempName = new char[10];
//	strcpy(tempName, name);
//
//	if (x >= 20 || x < -2 || y < -2 || y >= 40)
//	{
//		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
//	}
//	else {
//		if (unitlist[unitCnt].PositionX == -2 && unitlist[unitCnt].PositionY == -2)
//		{
//			for (int i = 0; i <= unitCnt; ++i)
//			{
//				if (unitlist[i].name == tempName) {
//					cout << "���� �̸��� ������ �ִ� ������ �����մϴ�." << endl;
//					break;
//				}
//			}
//			switch (type)
//			{
//			case 'H':
//				unitlist[unitCnt] = Hydra;
//				break;
//			case 'Q':
//				unitlist[unitCnt] = Queen;
//				break;
//			case 'D':
//				unitlist[unitCnt] = Defiler;
//				break;
//			case 'M':
//				unitlist[unitCnt] = Marin;
//				break;
//			case 'T':
//				unitlist[unitCnt] = Tank;
//				break;
//			case 'V':
//				unitlist[unitCnt] = Vessel;
//				break;
//			default:
//				cout << "�ش� ����Ÿ���� �������� �ʽ��ϴ�." << endl;
//				break;
//			}
//			unitlist[unitCnt].PositionX = x;
//			unitlist[unitCnt].PositionY = y;
//			unitlist[unitCnt].name = tempName;
//			unitCnt++;
//		}
//		else
//		{
//			cout << "�ش� ��ġ���� ������ �̹� �����ϰų� �����Ұ����� ��ġ�Դϴ�." << endl;
//		}
//	}
//}
//
//void MakeUL()
//{
//	for (int i = 0; i < sizeof(unitlist) / sizeof(Unit); ++i)
//	{
//		unitlist[i] = init;
//	}
//
//	Produce('M', 0, 0, "M01");
//	Produce('M', 1, 0, "M02");
//	Produce('M', 2, 0, "M03");
//	Produce('V', 2, 1, "V01");
//	Produce('V', 2, 2, "V02");
//	Produce('T', 3, 0, "T01");
//	Produce('M', 3, 1, "M04");
//	Produce('T', 4, 0, "T02");
//	Produce('M', 4, 1, "M05");
//	Produce('M', 5, 0, "M06");
//
//	Produce('H', 19, 39, "H01");
//	Produce('H', 18, 39, "H02");
//	Produce('H', 17, 37, "H03");
//	Produce('Q', 17, 38, "Q01");
//	Produce('Q', 17, 39, "Q02");
//	Produce('H', 16, 38, "H04");
//	Produce('D', 16, 39, "D01");
//	Produce('H', 15, 38, "H05");
//	Produce('D', 15, 39, "D02");
//	Produce('H', 14, 39, "H06");
//
//
//	unitlist[0].HP = 25;
//	unitlist[1].HP = 20;
//	unitlist[2].HP = 30;
//	unitlist[3].HP = 80;
//	unitlist[4].HP = 75;
//	unitlist[5].HP = 120;
//	unitlist[6].HP = 15;
//	unitlist[7].HP = 50;
//	unitlist[8].HP = 30;
//	unitlist[9].HP = 27;
//
//	unitlist[10].HP = 50;
//	unitlist[11].HP = 47;
//	unitlist[12].HP = 30;
//	unitlist[13].HP = 70;
//	unitlist[14].HP = 35;
//	unitlist[15].HP = 20;
//	unitlist[16].HP = 15;
//	unitlist[17].HP = 45;
//	unitlist[18].HP = 40;
//	unitlist[19].HP = 50;
//}
//
//void ShowUL_R(int i)
//{
//	if (i >= unitCnt)
//		return;
//	else
//		cout << i << " ��°�� ������ �̸� : " << unitlist[i].name << endl;
//
//	i++;
//	ShowUL_R(i);
//}
//
//void Produce_UL_R(char type, char tribe, int HP, int MP, int Distance, int AttackDistance, int AttackDamage, int UsingMP, int AttackRange, int Minerals, int PositionX, int PositionY, char* name, int i)
//{
//	char* tempName = new char[10];
//	strcpy(tempName, name);
//
//	if (PositionX >= 20 || PositionX < 0 || PositionY < 0 || PositionY >= 40)
//	{
//		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
//		return;
//	}
//	else if (tribe == 'Z' || tribe == 'T')
//	{
//		if (type == 'H' || type == 'Q' || type == 'D' ||
//			type == 'M' || type == 'T' || type == 'V')
//		{
//			if ((tribe == 'Z' && (type == 'H' || type == 'Q' || type == 'D')) || (tribe == 'T' && (type == 'M' || type == 'T' || type == 'V')))
//			{
//				for (int a = 0; a <= sizeof(unitlist) / sizeof(Unit); a++)
//				{
//					if (unitlist[a].PositionX == PositionX && unitlist[a].PositionY == PositionY)
//					{
//						cout << "�ش� ��ġ���� �̹� ������ �����մϴ�." << endl;
//						return;
//					}
//					else if (unitlist[a].name == tempName) {
//						cout << "���� �̸��� ������ �ִ� ������ �����մϴ�." << endl;
//						break;
//					}
//				}
//				if (unitlist[i].type == ' ')
//				{
//					unitlist[i].type = type;
//					unitlist[i].tribe = tribe;
//					unitlist[i].HP = HP;
//					unitlist[i].MP = MP;
//					unitlist[i].Distance = Distance;
//					unitlist[i].AttackDistance = AttackDistance;
//					unitlist[i].AttackDamage = AttackDamage;
//					unitlist[i].UsingMP = UsingMP;
//					unitlist[i].AttackRange = AttackRange;
//					unitlist[i].Minerals = Minerals;
//					unitlist[i].PositionX = PositionX;
//					unitlist[i].PositionY = PositionY;
//					unitlist[i].name = tempName;
//					unitCnt++;
//					cout << "���� ���� �Ϸ�!" << endl;
//					return;
//				}
//			}
//			else {
//				cout << "������ ��ü�� �߸� �ԷµǾ����ϴ�. ������ ������ ��� ��������, �׶��� ��� �׶������� �Է����ּ���." << endl;
//				return;
//			}
//		}
//		else {
//			cout << "�ش� Ÿ���� ������ �������� �ʽ��ϴ�. H, Q, D, M, T, V �� �ϳ��� �Է����ּ���." << endl;
//			return;
//		}
//	}
//	else
//	{
//		cout << "�ش� ������ �������� �ʽ��ϴ�. Z �Ǵ� T�� �Է����ּ���." << endl;
//		return;
//
//	}
//	i++;
//	Produce_UL_R(type, tribe, HP, MP, Distance, AttackDistance, AttackDamage, UsingMP, AttackRange, Minerals, PositionX, PositionY, name, i);
//}
//
//void SelectAll_UL_R(int x, int y, int x2, int y2, int i)
//{
//	int BigX{}, BigY{}, SmallX{}, SmallY{};
//
//	if (x >= 20 || x < -2 || y < -2 || y >= 40 ||
//		x2 >= 20 || x2 < -2 || y2 < -2 || y2 >= 40)
//	{
//		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
//		return;
//	}
//	else if (i > unitCnt) {
//		return;
//	}
//	else {
//		if (x >= x2)
//		{
//			BigX = x;
//			SmallX = x2;
//		}
//		else {
//			BigX = x2;
//			SmallX = x;
//		}
//
//		if (y >= y2)
//		{
//			BigY = y;
//			SmallY = y2;
//		}
//		else {
//			BigY = y2;
//			SmallY = y;
//		}
//
//		if (unitlist[i].PositionX >= SmallX && unitlist[i].PositionX <= BigX &&
//			unitlist[i].PositionY >= SmallY && unitlist[i].PositionY <= BigY)
//		{
//			cout << "������ ���� : " << unitlist[i].tribe << endl;
//			cout << "������ Ÿ�� : " << unitlist[i].type << endl;
//			cout << "������ HP : " << unitlist[i].HP << endl;
//			cout << "������ MP : " << unitlist[i].MP << endl;
//			cout << "������ �̵��Ÿ� : " << unitlist[i].Distance << endl;
//			cout << "������ ��Ÿ� : " << unitlist[i].AttackDistance << endl;
//			cout << "������ ���ݷ� : " << unitlist[i].AttackDamage << endl;
//			cout << "������ �Ҹ�MP : " << unitlist[i].UsingMP << endl;
//			cout << "������ ���ݹ��� : " << unitlist[i].AttackRange << endl;
//			cout << "������ ����� �Ҹ� �ൿ�� : " << unitlist[i].Minerals << endl;
//			cout << "������ ��ġ : ( " << unitlist[i].PositionX << ", " << unitlist[i].PositionY << " )" << endl;
//			cout << "������ �̸� : " << unitlist[i].name << endl;
//			cout << endl;
//		}
//	}
//
//	i++;
//	SelectAll_UL_R(x, y, x2, y2, i);
//}
//
//void Destroy_UL_R(int x, int y, int i)
//{
//	if (x < 0 || y < 0 || x >= 20 || y >= 40)
//	{
//		cout << "�ش� ��ġ�� �������� �ʽ��ϴ�." << endl;
//	}
//	else if (unitlist[i].PositionX == x && unitlist[i].PositionY == y)
//	{
//		unitlist[i] = init;
//		cout << "��! �ش� ��ġ�� ������ �ı��߽��ϴ�." << endl;
//		return;
//	}
//	else if (i >= unitCnt)
//	{
//		cout << "�ش� ��ġ�� ������ �������� �ʽ��ϴ�." << endl;
//		return;
//	}
//
//	i++;
//	Destroy_UL_R(x, y, i);
//}
//
//void FindWeakEnemy_R(int x, int y, int Distance, int i)
//{
//	if (x < 0 || y < 0 || x >= 20 || y >= 40)
//	{
//		cout << "�ش� ��ġ�� �������� �ʽ��ϴ�." << endl;
//	}
//	else if (i > unitCnt)
//	{
//		for (int x = 0; x <= unitCnt; x++)
//		{
//			if (unitlist[x].HP == lowHP)
//			{
//				if ((SerchingTribe == 'Z' && unitlist[x].tribe == 'T') ||
//					(SerchingTribe == 'T' && unitlist[x].tribe == 'Z'))
//				{
//					cout << "������ ���� : " << unitlist[x].tribe << endl;
//					cout << "������ Ÿ�� : " << unitlist[x].type << endl;
//					cout << "������ HP : " << unitlist[x].HP << endl;
//					cout << "������ MP : " << unitlist[x].MP << endl;
//					cout << "������ �̵��Ÿ� : " << unitlist[x].Distance << endl;
//					cout << "������ ��Ÿ� : " << unitlist[x].AttackDistance << endl;
//					cout << "������ ���ݷ� : " << unitlist[x].AttackDamage << endl;
//					cout << "������ �Ҹ�MP : " << unitlist[x].UsingMP << endl;
//					cout << "������ ���ݹ��� : " << unitlist[x].AttackRange << endl;
//					cout << "������ ����� �Ҹ� �ൿ�� : " << unitlist[x].Minerals << endl;
//					cout << "������ ��ġ : ( " << unitlist[x].PositionX << ", " << unitlist[x].PositionY << " )" << endl;
//					cout << "������ �̸� : " << unitlist[x].name << endl;
//					cout << endl;
//				}
//			}
//		}
//		if (lowHP == 10000)
//			cout << "���� ���� �� ������ �������� �ʽ��ϴ�." << endl;
//
//		lowHP = 10000;
//		return;
//	}
//	else {
//		for (int a = 0; a <= unitCnt; a++)
//		{
//			if (unitlist[a].PositionX == x && unitlist[a].PositionY == y)
//			{
//				SerchingTribe = unitlist[a].tribe;
//				break;
//			}
//		}
//		if (SerchingTribe == 'Z')
//		{
//			if (unitlist[i].type != ' ' && unitlist[i].tribe == 'T')
//			{
//				if (abs(unitlist[i].PositionX - x) >= abs(unitlist[i].PositionY - y))
//				{
//					if (Distance >= abs(unitlist[i].PositionX - x))
//					{
//						if (lowHP >= unitlist[i].HP)
//							lowHP = unitlist[i].HP;
//					}
//				}
//				else if (abs(unitlist[i].PositionX - x) <= abs(unitlist[i].PositionY - y))
//				{
//					if (Distance >= abs(unitlist[i].PositionY - y))
//					{
//						if (lowHP >= unitlist[i].HP)
//							lowHP = unitlist[i].HP;
//					}
//				}
//			}
//		}
//		else if (SerchingTribe == 'T')
//		{
//			if (unitlist[i].type != ' ' && unitlist[i].tribe == 'Z')
//			{
//				if (abs(unitlist[i].PositionX - x) >= abs(unitlist[i].PositionY - y))
//				{
//					if (Distance >= abs(unitlist[i].PositionX - x))
//					{
//						if (lowHP >= unitlist[i].HP)
//							lowHP = unitlist[i].HP;
//					}
//				}
//				else if (abs(unitlist[i].PositionX - x) <= abs(unitlist[i].PositionY - y))
//				{
//					if (Distance >= abs(unitlist[i].PositionY - y))
//					{
//						if (lowHP >= unitlist[i].HP)
//							lowHP = unitlist[i].HP;
//					}
//				}
//			}
//		}
//	}
//
//
//
//	i++;
//	FindWeakEnemy_R(x, y, Distance, i);
//}
//
//void DisplayMap_UL()
//{
//	for (int i = 0; i < 20; ++i) {
//		for (int j = 0; j < 40; ++j) {
//			for (int x = 0; x <= unitCnt; ++x)
//			{
//				if (unitlist[x].PositionX == i && unitlist[x].PositionY == j)
//				{
//					cout << unitlist[x].type;
//					break;
//				}
//				else if (x == unitCnt)
//					cout << " ";
//			}
//		}
//		cout << endl;
//	}
//}