//void FirstPlace();
//void Produce(char type, int x, int y, char* name);
//
//void ShowOrderList();
//void Order();
//void Display();
//void DestroyAll();
//void GetDistance();
//void FindWeakEnemy();
//void SortByDistance();
//
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
//Unit init = { ' ', ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " " };
//Unit Hydra = { 'H', 'Z', 50, 0, 3, 5, 25, 0, 1, 1 };
//Unit Queen = { 'Q', 'Z', 70, 150, 6, 15, 1000, 45, 1, 2 };
//Unit Defiler = { 'D', 'Z', 60, 200, 2, 1, 1, 60, 5, 2 };
//Unit Marin = { 'M', 'T', 30, 0, 3, 4, 20, 0, 1, 1 };
//Unit Tank = { 'T', 'T', 120, 0, 4, 17, 40, 0, 1, 2 };
//Unit Vessel = { 'V', 'T', 80, 140, 5, 12, 50, 35, 3, 2 };
//
//Unit map[20][40];
//Unit tempList[800];
//int tempDistance[800];
//
//char* OrderList[30]{};
//
//while (true)
//{
//	cout << endl;
//	cout << "1: ShowOrderList" << endl;
//	cout << "2: Order" << endl;
//	cout << "3: Display" << endl;
//	cout << "4: DestroyAll" << endl;
//	cout << "5: GetDistance" << endl;
//	cout << "6: FindWeakEnemy" << endl;
//	cout << "7: SortByDistance" << endl;
//	cout << "8: Quit" << endl;
//	cout << "Ŀ�ǵ带 �Է����ּ��� : ";
//	cin >> command;
//
//	switch (command)
//	{
//	case '1':
//		ShowOrderList();
//		break;
//	case '2':
//		cin >> order;
//		Order();
//		break;
//	case '3':
//		Display();
//		break;
//	case '4':
//		DestroyAll();
//		break;
//	case '5':
//		GetDistance();
//		break;
//	case '6':
//		FindWeakEnemy();
//		break;
//	case '7':
//		SortByDistance();
//		break;
//	case '8':
//		cout << "�̴Ͻ�Ÿ�� �����մϴ�." << endl;
//		return 0;
//		break;
//	default:
//		break;
//	}
//}
//
//void FirstPlace()
//{
//	for (int i = 0; i < 20; ++i)
//	{
//		for (int j = 0; j < 40; ++j)
//		{
//			map[i][j] = init;
//		}
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
//}
//
//void Produce(char type, int x, int y, char* name)
//{
//	char* tempName = new char[10];
//	strcpy(tempName, name);
//
//	if (x >= 20 || x < 0 || y < 0 || y >= 40)
//	{
//		cout << "�������� �ʴ� ��ġ�Դϴ�." << endl;
//	}
//	else {
//		if (map[x][y].type == ' ')
//		{
//			for (int i = 0; i < 20; ++i)
//			{
//				for (int j = 0; j < 40; ++j)
//				{
//					if (map[i][j].name == tempName) {
//						cout << "���� �̸��� ������ �ִ� ������ �����մϴ�." << endl;
//						goto cantProduce;
//					}
//				}
//			}
//
//			switch (type)
//			{
//			case 'H':
//				map[x][y] = Hydra;
//				break;
//			case 'Q':
//				map[x][y] = Queen;
//				break;
//			case 'D':
//				map[x][y] = Defiler;
//				break;
//			case 'M':
//				map[x][y] = Marin;
//				break;
//			case 'T':
//				map[x][y] = Tank;
//				break;
//			case 'V':
//				map[x][y] = Vessel;
//				break;
//			default:
//				cout << "�ش� ����Ÿ���� �������� �ʽ��ϴ�." << endl;
//				break;
//			}
//			map[x][y].PositionX = x;
//			map[x][y].PositionY = y;
//			map[x][y].name = tempName;
//
//		}
//		else
//		{
//			cout << "�ش� ��ġ���� ������ �̹� �����ϰų� �����Ұ����� ��ġ�Դϴ�." << endl;
//		}
//	}
//
//cantProduce:
//	{
//
//	}
//}
//
//cout << "������ ���� : " << map[i][j].tribe << endl;
//cout << "������ Ÿ�� : " << map[i][j].type << endl;
//cout << "������ HP : " << map[i][j].HP << endl;
//cout << "������ MP : " << map[i][j].MP << endl;
//cout << "������ �̵��Ÿ� : " << map[i][j].Distance << endl;
//cout << "������ ��Ÿ� : " << map[i][j].AttackDistance << endl;
//cout << "������ ���ݷ� : " << map[i][j].AttackDamage << endl;
//cout << "������ �Ҹ�MP : " << map[i][j].UsingMP << endl;
//cout << "������ ���ݹ��� : " << map[i][j].AttackRange << endl;
//cout << "������ ����� �Ҹ� �ൿ�� : " << map[i][j].Minerals << endl;
//cout << "������ ��ġ : ( " << map[i][j].PositionX << ", " << map[i][j].PositionY << " )" << endl;
//cout << "������ �̸� : " << map[i][j].name << endl;
//cout << endl;