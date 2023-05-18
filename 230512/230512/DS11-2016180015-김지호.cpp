#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

struct Players {
	char* position;
	char* name;
	int HP;
	int ATK;
	int DEF;
};

struct Players_SL {
	Players playerdata;
	Players_SL* next = nullptr;
};

Players_SL* head = nullptr;

void Make_SL();
void PrintAll_SL();
void SortByName_SL();
void FindTarget_SL(char*);
struct Players* binarySearch(Players_SL* head, char* target, int start, int end);
struct Players_SL* getNodeAtPosition(struct Players_SL* head, int position);

int main()
{
	int command{};
	char* name = new char[20];

	while (true)
	{
		cout << "1. Make_SL()" << endl;
		cout << "2. PrintAll_SL()" << endl;
		cout << "3. SortByName_SL()" << endl;
		cout << "4. FindTarget_SL()" << endl;
		cout << "command : ";
		cin >> command;

		switch (command)
		{
		case 1:
			Make_SL();
			break;
		case 2:
			PrintAll_SL();
			break;
		case 3:
			SortByName_SL();
			break;
		case 4:
			cout << "검색하는 이름을 입력하세요 : ";
			cin >> name;
			FindTarget_SL(name);
			break;
		default:
			break;
		}
	}
}

void Make_SL()
{
	// time 변수
	clock_t start, end;
	double cpu_time_used;

	FILE* fp;
	Players* newPlayer = new Players;
	int hp{};
	int atk{};
	int def{};

	start = clock();

	fp = fopen("DS_Large.txt", "r");
	if (fp == NULL)
		return;


	while (!feof(fp))
	{
		Players_SL* newNode = new Players_SL;
		char* pos = new char[100];
		char* name = new char[100];

		fscanf(fp, "%s", pos);
		fscanf(fp, "%s", name); 
		fscanf(fp, "%d", &hp);
		fscanf(fp, "%d", &atk); 
		fscanf(fp, "%d", &def);

		newPlayer->position = pos;
		newPlayer->name = name;
		newPlayer->HP = hp;
		newPlayer->ATK = atk;
		newPlayer->DEF = def;

		newNode->playerdata = *newPlayer;
		newNode->next = head;
		head = newNode;
	}
	
	fclose(fp);

	end = clock();

	cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);

	cout << "단방향 선형 연결리스트 생성 완료!" << endl;
	cout << "실행 시간: " << cpu_time_used << "초!" << endl;

	delete newPlayer;
}

void PrintAll_SL()
{
	// time 변수
	clock_t start, end;
	double cpu_time_used;

	int i = 1;

	start = clock();
	for (Players_SL* p = head; p != nullptr; p = p->next)
	{
		if (i % 1000 == 0)
		{
			cout << p->playerdata.position << " " <<
				p->playerdata.name << " " <<
				p->playerdata.HP << " " <<
				p->playerdata.ATK << " " <<
				p->playerdata.DEF << endl;
		}
		
		i++;
	}
	end = clock();

	cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);

	cout << "실행 시간: " << cpu_time_used << "초!" << endl;
}

void SortByName_SL()
{	
	// time 변수
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	if (head == NULL || head->next == NULL)
	{
		return;
	}
	else {
		Players_SL* sorted = NULL;
		Players_SL* current = head;

		while (current != NULL) {
			Players_SL* nextNode = current->next;

			if (sorted == NULL || strcmp(current->playerdata.name, sorted->playerdata.name) < 0) {
				current->next = sorted;
				sorted = current;
			}
			else {
				Players_SL* temp = sorted;
				while (temp->next != NULL && strcmp(current->playerdata.name, temp->next->playerdata.name) > 0) {
					temp = temp->next;
				}
				current->next = temp->next;
				temp->next = current;
			}

			current = nextNode;
		}

		head = sorted;
	}
	
	end = clock();

	cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);

	cout << "실행 시간: " << cpu_time_used << "초!" << endl;
}

void FindTarget_SL(char* Searchname)
{
	char* name = new char[20];
	strcpy(name, Searchname);

	// time 변수
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	int length{};

	// 이진탐색을 위한 연결리스트 길이 확인
	for (Players_SL* p = head; p != nullptr; p = p->next)
	{
		length++;
		if (p->next == nullptr)
		{
			break;
		}
	}

	Players* target = binarySearch(head, name, 0, length-1);

	if (target == NULL)
		cout << "해당 타겟은 존재하지 않습니다." << endl;
	else {
		cout << target->position << " " <<
			target->name << " " <<
			target->HP << " " <<
			target->ATK << " " <<
			target->DEF << endl;
	}
	end = clock();

	cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);

	cout << "실행 시간: " << cpu_time_used << "초!" << endl;
}

struct Players* binarySearch(Players_SL* head, char* target, int start, int end)
{
	char* name = new char[20];
	strcpy(name, target);

	if (start > end)
		return NULL;

	int mid = start + (end - start) / 2;
	Players_SL* Node = getNodeAtPosition(head, mid);
	
	if (strcmp(Node->playerdata.name, name) == 0)
	{
		return &Node->playerdata;
	}
	else if (strcmp(Node->playerdata.name, name) > 0)
	{
		binarySearch(head, name, start, mid - 1);
	}
	else if (strcmp(Node->playerdata.name, name) < 0)
	{
		binarySearch(head, name, mid + 1, end);
	}
}

// 연결 리스트에서 주어진 위치의 노드를 반환하는 함수
struct Players_SL* getNodeAtPosition(struct Players_SL* head, int position) {
	Players_SL* current = new Players_SL;
	current = head;

	for (int i = 0; i < position; i++) {
		current = current->next;
	}

	return current;
}
