#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

void FirstBoard();
void ShowBoard();
void PlaceStone(int x, int y);
void CheckRow();
void Check대각();
void CheckRowPosition();

char board[19][19];
int cnt{};
int blackCnt{}, whiteCnt{};

int main()
{
	char command{};
	int x{}, y{};

	FirstBoard();

	while (true)
	{
		cout << "0. ShowBoard" << endl;
		cout << "1. PlaceBoard" << endl;
		cout << "2. CheckRow" << endl;
		cout << "3. Check대각" << endl;
		cout << "4. CheckRowPosition" << endl;
		cout << "명령 입력 : ";
		cin >> command;

		switch (command)
		{
		case '0':
			ShowBoard();
			break;
		case '1':
			printf("좌표를 입력해주세요. : ");
			cin >> x >> y;
			PlaceStone(x, y);
			break;
		case '2':
			cout << "-CheckRow-" << endl;
			CheckRow();
			break;
		case '3':
			cout << "-Check대각-" << endl;
			Check대각();
			break;
		case '4':
			cout << "-CheckRowPosition-" << endl;
			CheckRowPosition();
			break;
		}
	}
}

void FirstBoard()
{
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			board[i][j] = '+';
		}
	}
}

void ShowBoard()
{
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			cout.width(2);
			cout << board[i][j];
		}
		cout << endl;
	}
}

void PlaceStone(int x, int y)
{
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

		cout << "해당 위치에 돌을 착수했습니다." << endl;
	}
	else {
		printf("해당 위치에 돌을 둘 수 없습니다.\n");
	}

	printf("검은 돌의 개수 : %d, 흰 돌의 개수 : %d\n", blackCnt, whiteCnt);
}

void CheckRow()
{
	int MostCnt{};
	int bCnt{};
	int wCnt{};
	char* Color = new char[5] {" "};

	// 가로줄 확인
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] != '+')
			{
				if (board[i][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
					}
				}
				else if (board[i][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
					}
				}
			}
			else if (board[i][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i << "번째 가로줄의 경우 : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}

	// 세로줄 확인
	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] != '+')
			{
				if (board[i][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
					}
				}
				else if (board[i][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
					}
				}
			}
		}

		cout << j << "번째 세로줄의 경우 : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}
}

void Check대각()
{
	int MostCnt{};
	int bCnt{};
	int wCnt{};
	char* Color = new char[5] { " " };

	// /모양 위쪽
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (i - j < 0)
				break;

			if (board[i - j][j] != '+')
			{
				if (board[i - j][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
					}
				}
				else if (board[i - j][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
					}
				}
			}
			else if (board[i - j][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i << "번째 /형 대각선의 경우 : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}

	// /모양 아래쪽
	for (int i = 1; i < 19; ++i) {
		for (int j = 18; j >= 0; --j) {
			if (i + (18 - j) > 18)
				break;

			if (board[i + (18 - j)][j] != '+')
			{
				if (board[i + (18 - j)][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
					}
				}
				else if (board[i + (18 - j)][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
					}
				}
			}
			else if (board[i + (18 - j)][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i + 18 << "번째 /형 대각선의 경우 : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}


	// \모양 위쪽
	for (int i = 0; i < 19; ++i) {
		for (int j = 18; j >= 0; --j) {
			if (i - (18 - j) < 0)
				break;

			if (board[i - (18 - j)][j] != '+')
			{
				if (board[i - (18 - j)][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
					}
				}
				else if (board[i - (18 - j)][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
					}
				}
			}
			else if (board[i - (18 - j)][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i << "번째 \\형 대각선의 경우 : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}

	// \모양 아래쪽
	for (int i = 1; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (i + j > 18)
				break;

			if (board[i + j][j] != '+')
			{
				if (board[i + j][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
					}
				}
				else if (board[i + j][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
					}
				}
			}
			else if (board[i + j][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i + 18 << "번째 \\형 대각선의 경우 : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}
}

void CheckRowPosition()
{
	int MostCnt{};
	int bCnt{};
	int wCnt{};
	char* Color = new char[5] { " " };
	int x{ -1 }, y{ -1 };
	int x2{ -1 }, y2{ -1 };

	// 가로줄 확인
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] != '+')
			{
				if (board[i][j] == 'O')
				{
					bCnt++;
					wCnt = 0;
					if (MostCnt < bCnt)
					{
						MostCnt = bCnt;
						strcpy(Color, "검은돌");
						x = i;
						y = j;
					}

				}
				else if (board[i][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "흰돌");
						x = i;
						y = j;
					}
				}
			}
			else if (board[i][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}



		cout << i << "번째 가로줄의 경우 : " << Color << ", " << MostCnt << endl;

		// 돌이 착수된 위치
		for (int j = y; j >= 0; --j)
		{
			if (board[i][j] == '+')
			{
				break;
			}
			else if (board[i][j] == board[x][y]) {
				y2 = j;
				cout << "돌이 착수된 위치는 (" << x << " " << y2 << ") 입니다." << endl;
			}
		}


		x = -1;
		y = -1;
		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}
}
