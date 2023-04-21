//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
//void Produce(char type, int x, int y, char* name);
//void MakeUL();
//
//void MakeUL_SL();
//void ShowUL_SL();
//void SelectUL_SL();
//void ProduceUL_SL();
//void DestroyUL_SL();
//void FindWeakEnemyUL_SL();
//void SortByIDUL_SL();
//void Display();
//
//struct Unit {
//	char type;				// 종류
//	char tribe;				// 종족
//	int HP;					// HP
//	int MP;					// MP
//	int Distance;			// 이동거리
//	int AttackDistance;		// 공격사거리
//	int AttackDamage;		// 공격력
//	int UsingMP;			// MP사용량
//	int AttackRange;		// 공격범위
//	int Minerals;			// 생산소모량
//	int PositionX;			// X좌표
//	int PositionY;			// Y좌표
//	char* name = " ";		// 이름
//};
//
//struct Unit_SL {
//	Unit unitdata;
//	Unit_SL* next = nullptr;
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
//Unit unitlist[100];
//int unitCnt{};
//
//Unit_SL* head = nullptr;
//
//
//int main()
//{
//	char command;
//	MakeUL();
//	MakeUL_SL();
//
//	while (true)
//	{
//		cout << endl;
//		cout << "_____커맨드창_____" << endl;
//		cout << "1: ShowUL_SL" << endl;
//		cout << "2: SelectUL_SL" << endl;
//		cout << "3: ProduceUL_SL" << endl;
//		cout << "4: DestroyUL_SL" << endl;
//		cout << "5: FindWeakEnemyUL_SL" << endl;
//		cout << "6: SortByIDUL_SL" << endl;
//		cout << "7: Display" << endl;
//		cout << "8: Quit" << endl;
//		cout << "커맨드를 입력해주세요 : ";
//		cin >> command;
//
//		switch (command)
//		{
//		case '1':
//			cout << "-ShowUL_SL-" << endl;
//			ShowUL_SL();
//			break;
//		case '2':
//			cout << "-SelectUL_SL-" << endl;
//			cout << "입력하시는 좌표의 유닛을 확인합니다. : ";
//			SelectUL_SL();
//			break;
//		case '3':
//			cout << "-ProdeuceUL_SL-" << endl;
//			cout << "type, tribe, HP, MP, Distance, AttackDistance, AttackDamage, UsingMP, AttackRange, Minerals, PositionX, PositionY, name를 입력해주세요" << endl;
//			ProduceUL_SL();
//			break;
//		case '4':
//			cout << "-DestroyUL_SL-" << endl;
//			cout << "좌표를 입력하세요 : ";
//			DestroyUL_SL();
//			break;
//		case '5':
//			cout << "-FindWeakEnemyUL_SL-" << endl;
//			cout << "좌표와 거리를 입력하세요 : ";
//			FindWeakEnemyUL_SL();
//			break;
//		case '6':
//			cout << "-SortByIDUL_SL-" << endl;
//			SortByIDUL_SL();
//			break;
//		case '7':
//			cout << "-Display-" << endl;
//			Display();
//			break;
//		case '8':
//			cout << "-미니스타를 종료합니다.-" << endl;
//			return 0;
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//
//void Produce(char type, int x, int y, char* name)
//{
//	char* tempName = new char[10];
//	strcpy(tempName, name);
//
//	if (x >= 20 || x < -2 || y < -2 || y >= 40)
//	{
//		cout << "존재하지 않는 위치입니다." << endl;
//	}
//	else {
//		if (unitlist[unitCnt].PositionX == -2 && unitlist[unitCnt].PositionY == -2)
//		{
//			for (int i = 0; i <= unitCnt; ++i)
//			{
//				if (unitlist[i].name == tempName) {
//					cout << "같은 이름을 가지고 있는 유닛이 존재합니다." << endl;
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
//				cout << "해당 유닛타입은 존재하지 않습니다." << endl;
//				break;
//			}
//			unitlist[unitCnt].PositionX = x;
//			unitlist[unitCnt].PositionY = y;
//			unitlist[unitCnt].name = tempName;
//			unitCnt++;
//		}
//		else
//		{
//			cout << "해당 위치에는 유닛이 이미 존재하거나 생성불가능한 위치입니다." << endl;
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
//void MakeUL_SL()
//{
//
//}
//
//void ShowUL_SL()
//{
//	
//}
//
//void SelectUL_SL()
//{
//	
//}
//
//void ProduceUL_SL()
//{
//
//}
//
//void DestroyUL_SL()
//{
//
//}
//
//void FindWeakEnemyUL_SL()
//{
//
//}
//
//void SortByIDUL_SL()
//{
//
//}
//
//void Display()
//{
//	for (int i = 0; i < 20; ++i) {
//		for (int j = 0; j < 40; ++j) {
//			for (Unit_SL* p = head; p->next != nullptr; p = p->next)
//			{
//				if (p->unitdata.PositionX == i && p->unitdata.PositionY == j)
//				{
//					cout << p->unitdata.type;
//					break;
//				}
//				else if (p->next == head)
//				{
//					cout << " ";
//					break;
//				}
//			}
//		}
//		cout << endl;
//	}
//}
//
//cout << "유닛의 종족 : " << p->unitdata.tribe << endl;
//cout << "유닛의 타입 : " << p->unitdata.type << endl;
//cout << "유닛의 HP : " << p->unitdata.HP << endl;
//cout << "유닛의 MP : " << p->unitdata.MP << endl;
//cout << "유닛의 이동거리 : " << p->unitdata.Distance << endl;
//cout << "유닛의 사거리 : " << p->unitdata.AttackDistance << endl;
//cout << "유닛의 공격력 : " << p->unitdata.AttackDamage << endl;
//cout << "유닛의 소모MP : " << p->unitdata.UsingMP << endl;
//cout << "유닛의 공격범위 : " << p->unitdata.AttackRange << endl;
//cout << "유닛의 생산시 소모 행동력 : " << p->unitdata.Minerals << endl;
//cout << "유닛의 위치 : ( " << p->unitdata.PositionX << ", " << p->unitdata.PositionY << " )" << endl;
//cout << "유닛의 이름 : " << p->unitdata.name << endl;
//cout << endl;