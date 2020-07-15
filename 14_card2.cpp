#include<stdio.h>
#include <stdlib.h> 
#pragma warning(disable:4996)

int MIN(int a, int b)
{
	int min;
	if (a < b) min = a;
	else min = b;
	return min;
}
int MAX(int a, int b) {
	int max;
	if (a > b)max = a;
	else max = b;
	return max;
}
int num;
int Alice[10001][10001];
int computer[10001][10001];
int card[10001];
int result;

int main() {
	FILE* inp = fopen("card.inp", "rt");
	FILE* out = fopen("card.out", "wt");

	int test;
	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++) {
		fscanf(inp, "%d", &num);
		for (int i = 0; i < num; i++) { fscanf(inp, "%d", &card[i]); } //입력 

		for (int i = 0; i < num; i++) Alice[i][i] = card[i]; //배열 복사

		/*
		for (int i = 0, j = 1; i < num - 1; i++, j++) {
				Alice[i][j] = MAX(Alice[i][i], Alice[j][j]);
			}

		for (int i = 0, j = 1; i < num - 1; i++, j++) {
			computer[i][j] = MIN(Alice[i][j - 1], Alice[i + 1][j]);
		}

		*/
		for (int i = 0; i < num; i++) {
			for (int j = 0; i + j < num; j++) { //대각선으로 내려감
				if (i == 0)continue;

				computer[j][i + j] = MIN(Alice[j][i + j - 1], Alice[j + 1][i + j]);
				Alice[j][i + j] = MAX(Alice[j][j + i - i] + computer[j + 1][i + j], Alice[j + i][j + i] + computer[j][i + j - 1]);

			}
		}
		result = Alice[0][num - 1];

		fprintf(out, "%d\n", result);
	}

	return 0;
}
