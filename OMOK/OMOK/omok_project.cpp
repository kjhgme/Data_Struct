#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

void FirstPlace();	// ���� �ʱ�ȭ
void Display();

void PlaceStone();
void CheckRow();
void CheckRowContinuous();
void CheckDiagonalContinuous();

char board[19][19];
int x{}, y{};
int cnt{};
int blackCnt{}, whiteCnt{};

int main()
{
	char command{};

	FirstPlace();

	while (true)
	{
		Display();

		cout << "1.PlaceStone" << endl;
		cout << "2.CheckRow" << endl;
		cout << "3.CheckRowContinuous" << endl;
		cout << "4.CheckDiagonalContinuous" << endl;
		cout << "command : ";
		cin >> command;

		switch (command)
		{
		case '1':
			cout << "-PlaceStone-" << endl;
			PlaceStone();
			break;
		case '2':
			cout << "-CheckRow-" << endl;
			CheckRow();
			break;
		case '3':
			cout << "-CheckRowContinuous-" << endl;
			CheckRowContinuous();
			break;
		case '4':
			cout << "-CheckDiagonalContinuous-" << endl;
			CheckDiagonalContinuous();
			break;
		default:
			break;
		}
		
	}
}

void FirstPlace()
{
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			board[i][j] = '+';
		}
	}
}

void Display()
{
	cout << endl << " ";
	for (int i = 0; i < 19; ++i)
	{
		cout.width(3);
		cout << right << i;
	}

	cout << endl;

	for (int i = 0; i < 19; ++i) {
		cout.width(3);
		cout << left << i;
		for (int j = 0; j < 19; ++j) {
			cout.width(3);
			cout << board[i][j];
		}
		cout << endl;
	}
}

void PlaceStone()
{
	cout << "��ǥ�� �Է����ּ���. : ";
	cin >> x >> y;

	if (board[x][y] == '+')
	{
		if (cnt % 2 == 0)
		{
			board[x][y] = 'O';
			cnt++;
			blackCnt++;
		}
		else
		{
			board[x][y] = 'X';
			cnt++;
			whiteCnt++;
		}
	}
	else {
		printf("�� ��ġ�� ���� �� �� �����ϴ�.\n");
	}

	printf("���� ���� ���� : %d, �� ���� ���� : %d\n", blackCnt, whiteCnt);
}

void CheckRow()
{
	int cnt{};

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'O')
				cnt++;
		}
		cout << "���� " << i << "�� ���� ���� ���� : " << cnt << endl;
		cnt = 0;
	}

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[j][i] == 'O')
				cnt++;
		}
		cout << "���� " << i << "�� ���� ���� ���� : " << cnt << endl;
		cnt = 0;
	}

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'X')
				cnt++;
		}
		cout << "���� " << i << "�� �� ���� ���� : " << cnt << endl;
		cnt = 0;
	}

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[j][i] == 'X')
				cnt++;
		}
		cout << "���� " << i << "�� �� ���� ���� : " << cnt << endl;
		cnt = 0;
	}
}

void CheckRowContinuous()
{
	char CStone{};
	int CSNum{};
	int bnum{};
	int wnum{};

	// ������ Ȯ��
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (board[i][j] != '+' && board[i][j] == 'O')
			{
				bnum++;
			}
			else if (board[i][j] == '+' || board[i][j] == 'X')
			{
				if (bnum > CSNum)
				{
					CStone = 'O';
					CSNum = bnum;
				}
				bnum = 0;
			}

			if (board[i][j] != '+' && board[i][j] == 'X')
			{
				wnum++;
			}
			else if (board[i][j] == '+' || board[i][j] == 'O')
			{
				if (wnum > CSNum)
				{
					CStone = 'X';
					CSNum = wnum;
				}
				wnum = 0;
			}
		}
		
		if (CStone == 'O')
		{
			cout << "���� " << i << "�� ���� ���� ���ӵ� ���� ���� ���̴�. ������ "
				<< CSNum << endl;
		}
		else if(CStone == 'X') {
			cout << "���� " << i << "�� ���� ���� ���ӵ� ���� �� ���̴�. ������ "
				<< CSNum << endl;
		}
		else if (CStone == '\0') {
			cout << "���� " << i << "���� ���� �����ϴ�." << endl;
		}

		CStone = '\0';
		CSNum = 0;
		bnum = 0;
		wnum = 0;
	}

	//������ Ȯ��
	for (int j = 0; j < 19; ++j) {
		for (int i = 0; i < 19; ++i) {

			if (board[i][j] != '+' && board[i][j] == 'O')
			{
				bnum++;
			}
			else if (board[i][j] == '+' || board[i][j] == 'X')
			{
				if (bnum > CSNum)
				{
					CStone = 'O';
					CSNum = bnum;
				}
				bnum = 0;
			}

			if (board[i][j] != '+' && board[i][j] == 'X')
			{
				wnum++;
			}
			else if (board[i][j] == '+' || board[i][j] == 'O')
			{
				if (wnum > CSNum)
				{
					CStone = 'X';
					CSNum = wnum;
				}
				wnum = 0;
			}
		}

		if (CStone == 'O')
		{
			cout << "���� " << j << "�� ���� ���� ���ӵ� ���� ���� ���̴�. ������ "
				<< CSNum << endl;
		}
		else if (CStone == 'X') {
			cout << "���� " << j << "�� ���� ���� ���ӵ� ���� �� ���̴�. ������ "
				<< CSNum << endl;
		}
		else if (CStone == '\0') {
			cout << "���� " << j << "���� ���� �����ϴ�." << endl;
		}

		CStone = '\0';
		CSNum = 0;
		bnum = 0;
		wnum = 0;
	}
}

void CheckDiagonalContinuous()
{
	char CStone{};
	int CSNum{};
	int bnum{};
	int wnum{};

	// ���� ������ ���� ������ �Ʒ��� üũ
	cout << "/ ������ �밢�� Ȯ��." << endl;
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (i - j < 0)
				break;
			
			if (board[i - j][j] != '+')
			{
				if (board[i - j][j] == 'O')
				{
					bnum++;
				}
			}
				cout << i - j << " " << j << endl;
		}
		
		CStone = '\0';
		CSNum = 0;
		bnum = 0;
		wnum = 0;
	}

	cout << "-------------------" << endl;

	//for (int i = 18; i > 0; --i) {
	//	for (int j = 18; j >= 0; --j) {
	//		if (j-i < 0)
	//			break;
	//		cout << i+(18-j) << " " << j << endl;
	//	}
	//	cout << endl;
	//}



	//// ������ ���������� ���� �Ʒ��� üũ

	//cout << "\\������ �밢�� Ȯ��." << endl;
	//for (int i = 0; i < 19; ++i)
	//{
	//	for (int j = 18; j >= 18-i; --j)
	//	{
	//		cout << i-(18-j) << " " << j << endl;
	//	}
	//	cout << endl;
	//}

	//cout << "------------------" << endl;
	//
	//for (int i = 18; i > 0; --i) {
	//	for (int j = 0; j < 19; ++j) {
	//		if (i + j > 18)
	//			break;
	//		cout << i+j << " " << j << endl;
	//	}
	//	cout << endl;
	//}
}

