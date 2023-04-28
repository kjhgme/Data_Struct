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

void SaveFile();
void LoadFile();
void U();	// 무르기
void R();	// 무르기 취소

char board[19][19];
int cnt{};
int blackCnt{}, whiteCnt{};


struct Stone {
	char color;
	int x;
	int y;
	struct Stone* next;
};

struct StoneStack {
	struct Stone* top;
};

StoneStack stack;
StoneStack redoStack;
StoneStack tempStack;

int main()
{
	char command{};
	int x{}, y{};
	stack.top = NULL;
	redoStack.top = NULL;

	FirstBoard();

	while (true)
	{
		ShowBoard();

		cout << "0. ShowBoard" << endl;
		cout << "1. PlaceBoard" << endl;
		cout << "2. CheckRow" << endl;
		cout << "3. Check대각" << endl;
		cout << "4. CheckRowPosition" << endl;
		cout << "5. SaveFile" << endl;
		cout << "6. LoadFile" << endl;
		cout << "U. 무르기" << endl;
		cout << "R. 무르기 취소" << endl;
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
		case '5':
			SaveFile();
			break;
		case '6':
			LoadFile();
			break;
		case 'U':
			U();
			break;
		case 'R':
			R();
			break;
		default:
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
	Stone* newStone = new Stone;

	if (board[x][y] != '+')
	{
		printf("해당 위치에 돌을 둘 수 없습니다.\n");
		return;
	}
	else {
		// 무르기 취소 초기화.
		redoStack.top = NULL;

		// 착수.
		if (cnt % 2 == 0)
		{
			newStone->color = 'O';
			newStone->x = x;
			newStone->y = y;
			newStone->next = stack.top;
			stack.top = newStone;

			board[x][y] = 'O';
			cnt++;
			blackCnt++;
		}
		else
		{
			newStone->color = 'X';
			newStone->x = x;
			newStone->y = y;
			newStone->next = stack.top;
			stack.top = newStone;

			board[x][y] = 'X';
			cnt++;
			whiteCnt++;
		}

		cout << "해당 위치에 돌을 착수했습니다." << endl;
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

void SaveFile()
{
	FILE* fp;
	// save board
	fp = fopen("board.txt", "w");

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j) 
		{
			fputc(board[i][j], fp);
		}
	}
	
	fclose(fp);

	// save stack
	fp = fopen("stack.txt", "w");

	for (Stone* p = stack.top; p != nullptr; p = p->next)
	{
		fputc(p->color, fp);
		fprintf(fp, "%d", p->x);
		fprintf(fp, "%d", p->y);
	}
	
	fclose(fp);

	// save redoStack
	fp = fopen("redoStack.txt", "w");

	for (Stone* p = redoStack.top; p != nullptr; p = p->next)
	{
		fputc(p->color, fp);
		fprintf(fp, "%d", p->x);
		fprintf(fp, "%d", p->y);
	}

	fclose(fp);

	cout << "Saved!!!" << endl;
}

void LoadFile()
{
	FILE* fp;
	char c{};
	cnt = 0;
	blackCnt = 0;
	whiteCnt = 0;

	// load board
	fp = fopen("board.txt", "r");
	
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			c = fgetc(fp);
			board[i][j] = c;
			if (board[i][j] != '+')
				cnt++;
			if (board[i][j] == 'O')
				blackCnt++;
			if (board[i][j] == 'X')
				whiteCnt++;
		}
	}

	fclose(fp);

	// load "stack"
	fp = fopen("stack.txt", "r");

	stack.top = NULL;
	tempStack.top = NULL;

	while (true)
	{
		char str[4];
		char* pStr = fgets(str, 4, fp);
		if (pStr == NULL)
		{
			break;
		}

		Stone* newStone = new Stone;
		newStone->color = str[0];
		newStone->x = str[1] - '0';
		newStone->y = str[2] - '0';
		newStone->next = tempStack.top;
		tempStack.top = newStone;
	}

	while(true)
	{
		if (tempStack.top == NULL)
		{
			break;
		}

		Stone* newStone = new Stone;
		newStone->color = tempStack.top->color;
		newStone->x = tempStack.top->x;
		newStone->y = tempStack.top->y;
		newStone->next = stack.top;
		stack.top = newStone;

		tempStack.top = tempStack.top->next;
	}
	
	fclose(fp);

	// load "redoStack"
	fp = fopen("redoStack.txt", "r");

	redoStack.top = NULL;
	tempStack.top = NULL;

	while (true)
	{
		char str[4];
		char* pStr = fgets(str, 4, fp);
		if (pStr == NULL)
		{
			break;
		}

		Stone* newStone = new Stone;
		newStone->color = str[0];
		newStone->x = str[1] - '0';
		newStone->y = str[2] - '0';
		newStone->next = tempStack.top;
		tempStack.top = newStone;
	}

	while (true)
	{
		if (tempStack.top == NULL)
		{
			break;
		}

		Stone* newStone = new Stone;
		newStone->color = tempStack.top->color;
		newStone->x = tempStack.top->x;
		newStone->y = tempStack.top->y;
		newStone->next = redoStack.top;
		redoStack.top = newStone;

		tempStack.top = tempStack.top->next;
	}

	fclose(fp);

	cout << "Loaded!!!" << endl;
}

void U()
{
	if (stack.top == NULL)
	{
		cout << "아직 돌을 두지 않았습니다." << endl;
		return;
	}

	Stone* newStone = new Stone;
	newStone->color = stack.top->color;
	newStone->x = stack.top->x;
	newStone->y = stack.top->y;
	newStone->next = redoStack.top;
	redoStack.top = newStone;

	board[stack.top->x][stack.top->y] = '+';
	cnt--;

	if (stack.top->color == 'O')
		blackCnt--;
	else
		whiteCnt--;

	stack.top = stack.top->next;
}

void R()
{
	if (redoStack.top == NULL)
	{
		cout << "취소할 무르기가 없습니다." << endl;
		return;
	}

	board[redoStack.top->x][redoStack.top->y] = redoStack.top->color;
	cnt++;

	if (redoStack.top->color == 'O')
		blackCnt++;
	else
		whiteCnt++;

	Stone* newStone = new Stone;
	newStone->color = redoStack.top->color;
	newStone->x = redoStack.top->x;
	newStone->y = redoStack.top->y;
	newStone->next = stack.top;
	stack.top = newStone;

	redoStack.top = redoStack.top->next;
}