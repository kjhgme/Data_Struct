#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

void FirstBoard();
void ShowBoard();
void PlaceStone(int x, int y);
void CheckRow();
void Check�밢();
void CheckRowPosition();

void SaveFile();
void LoadFile();
void U();	// ������
void R();	// ������ ���

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
		cout << "3. Check�밢" << endl;
		cout << "4. CheckRowPosition" << endl;
		cout << "5. SaveFile" << endl;
		cout << "6. LoadFile" << endl;
		cout << "U. ������" << endl;
		cout << "R. ������ ���" << endl;
		cout << "��� �Է� : ";
		cin >> command;

		switch (command)
		{
		case '0':
			ShowBoard();
			break;
		case '1':
			printf("��ǥ�� �Է����ּ���. : ");
			cin >> x >> y;
			PlaceStone(x, y);
			break;
		case '2':
			cout << "-CheckRow-" << endl;
			CheckRow();
			break;
		case '3':
			cout << "-Check�밢-" << endl;
			Check�밢();
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
		printf("�ش� ��ġ�� ���� �� �� �����ϴ�.\n");
		return;
	}
	else {
		// ������ ��� �ʱ�ȭ.
		redoStack.top = NULL;

		// ����.
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

		cout << "�ش� ��ġ�� ���� �����߽��ϴ�." << endl;
	}

	printf("���� ���� ���� : %d, �� ���� ���� : %d\n", blackCnt, whiteCnt);
}

void CheckRow()
{
	int MostCnt{};
	int bCnt{};
	int wCnt{};
	char* Color = new char[5] {" "};

	// ������ Ȯ��
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
						strcpy(Color, "������");
					}
				}
				else if (board[i][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "��");
					}
				}
			}
			else if (board[i][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i << "��° �������� ��� : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}

	// ������ Ȯ��
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
						strcpy(Color, "������");
					}
				}
				else if (board[i][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "��");
					}
				}
			}
		}

		cout << j << "��° �������� ��� : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}
}

void Check�밢()
{
	int MostCnt{};
	int bCnt{};
	int wCnt{};
	char* Color = new char[5] { " " };

	// /��� ����
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
						strcpy(Color, "������");
					}
				}
				else if (board[i - j][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "��");
					}
				}
			}
			else if (board[i - j][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i << "��° /�� �밢���� ��� : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}

	// /��� �Ʒ���
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
						strcpy(Color, "������");
					}
				}
				else if (board[i + (18 - j)][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "��");
					}
				}
			}
			else if (board[i + (18 - j)][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i + 18 << "��° /�� �밢���� ��� : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}


	// \��� ����
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
						strcpy(Color, "������");
					}
				}
				else if (board[i - (18 - j)][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "��");
					}
				}
			}
			else if (board[i - (18 - j)][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i << "��° \\�� �밢���� ��� : " << Color << ", " << MostCnt << endl;

		bCnt = 0;
		wCnt = 0;
		MostCnt = 0;
		strcpy(Color, " ");
	}

	// \��� �Ʒ���
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
						strcpy(Color, "������");
					}
				}
				else if (board[i + j][j] == 'X')
				{
					wCnt++;
					bCnt = 0;
					if (MostCnt < wCnt)
					{
						MostCnt = wCnt;
						strcpy(Color, "��");
					}
				}
			}
			else if (board[i + j][j] == '+')
			{
				bCnt = 0;
				wCnt = 0;
			}
		}

		cout << i + 18 << "��° \\�� �밢���� ��� : " << Color << ", " << MostCnt << endl;

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

	// ������ Ȯ��
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
						strcpy(Color, "������");
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
						strcpy(Color, "��");
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



		cout << i << "��° �������� ��� : " << Color << ", " << MostCnt << endl;

		// ���� ������ ��ġ
		for (int j = y; j >= 0; --j)
		{
			if (board[i][j] == '+')
			{
				break;
			}
			else if (board[i][j] == board[x][y]) {
				y2 = j;
				cout << "���� ������ ��ġ�� (" << x << " " << y2 << ") �Դϴ�." << endl;
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
		cout << "���� ���� ���� �ʾҽ��ϴ�." << endl;
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
		cout << "����� �����Ⱑ �����ϴ�." << endl;
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