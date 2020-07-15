#include<iostream>
#include<stdio.h>
#pragma warning(disable:4996)

#define MAX 9
using namespace std;

FILE* out = fopen("sudoku.out", "wt");
FILE* inp = fopen("sudoku.inp", "rt");

int MAP[MAX][MAX];
char position[MAX][MAX];
bool Row[MAX][MAX]; //가로
bool Col[MAX][MAX]; //세로
bool Square[MAX][MAX]; //사각형 범위.. aaa bb등 범위
int memory[MAX][MAX]; //원래자리기억
int t;
int test;
void Input()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			fscanf(inp, "%d", &MAP[i][j]);
			if (MAP[i][j] != 0)memory[i][j] = 1;
		}
	}
	fgetc(inp);
	fgetc(inp);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			fscanf(inp, "%c ", &position[i][j]);
		}
	}
	//aaaa .. 는 0번째사각형, i는 8번째 사각형
	int index;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (MAP[i][j] != 0)
			{
				if (position[i][j] == 'a') index = 0;
				if (position[i][j] == 'b') index = 1;
				if (position[i][j] == 'c') index = 2;
				if (position[i][j] == 'd') index = 3;
				if (position[i][j] == 'e') index = 4;
				if (position[i][j] == 'f') index = 5;
				if (position[i][j] == 'g') index = 6;
				if (position[i][j] == 'h') index = 7;
				if (position[i][j] == 'i') index = 8;

				Row[i][MAP[i][j] - 1] = true; //i번째 가로줄에 MAP[i][j]가 이미 존재
				Col[j][MAP[i][j] - 1] = true; //j번째 세로줄에 MAP[i][j]가 이미 존재
				Square[index][MAP[i][j] - 1] = true; // index번째 사각형에 MAP[i][j]가 이미 존재
			}
		}
	}
}
int flag = 0;
int T = false;
void DFS(int Cnt)
{
	int x = Cnt / MAX;    // x 좌표
	int y = Cnt % MAX;    // y 좌표

	if (Cnt == 81)
	{
		if (flag == 1)return;
		fprintf(out, "Test Case No: %d\n", t + 1);

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (memory[i][j] == 1) MAP[i][j]--;
				fprintf(out, "%d ", MAP[i][j] + 1);
			}
			fprintf(out, "\n");

		}
		fprintf(out, "\n");
		flag = 1;
		return;
	}
	int index;
	if (MAP[x][y] == 0)
	{
		if (position[x][y] == 'a')index = 0;
		if (position[x][y] == 'b')index = 1;
		if (position[x][y] == 'c')index = 2;
		if (position[x][y] == 'd')index = 3;
		if (position[x][y] == 'e')index = 4;
		if (position[x][y] == 'f')index = 5;
		if (position[x][y] == 'g')index = 6;
		if (position[x][y] == 'h')index = 7;
		if (position[x][y] == 'i')index = 8;


		for (int i = 0; i < 9; i++)
		{
			if (Row[x][i] == false && Col[y][i] == false && Square[index][i] == false)
			{
				MAP[x][y] = i;
				Row[x][i] = true;
				Col[y][i] = true;
				Square[index][i] = true;
				DFS(Cnt + 1);
				MAP[x][y] = 0;
				Row[x][i] = false;
				Col[y][i] = false;
				Square[index][i] = false;
			}
		}
	}
	else DFS(Cnt + 1);

}


int main(void)
{

	fscanf(inp, "%d", &test);

	for (t = 0; t < test; t++) {

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++)Row[i][j] = 0, Col[i][j] = 0, Square[i][j] = 0, position[i][j] = 0, MAP[i][j] = 0, memory[i][j] = 0, flag = 0;
		}//초기화
		Input();
		DFS(0);
	}


	return 0;
}