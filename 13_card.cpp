#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int MAX2(int a, int b) {
	int max;
	if (a > b) max = a;
	else max = b;
	return max;
}
int MAX3(int a, int b, int c) {
	int max;
	if (a < b) {
		if (b < c) max = c;
		else max = b;
	}
	else // b > a
	{
		if (a < c) max = c;
		else max = a;
	}
	return max;
}

int card_num;
int card[1003];
int result;

int add[1003][3] = { 0 };

int main() {
	FILE* inp = fopen("card.inp", "rt");
	FILE* out = fopen("card.out", "wt");

	int test;
	fscanf(inp, "%d", &test);

	for (int t = 0; t < test; t++) {
		fscanf(inp, "%d", &card_num);
		add[1003][3] = { 0 };

		for (int i = 0; i < card_num; i++) fscanf(inp, "%d", &card[i]);
		if (card_num == 4) {
			result = MAX2(card[0] + card[3], card[1] + card[3]);//4개 입력받았을 때
		}
		add[0][0] = card[0], add[0][1] = card[0], add[0][2] = card[0];
		add[1][0] = card[1], add[1][1] = card[1], add[1][2] = card[1];
		add[2][0] = card[2], add[2][1] = card[2], add[2][2] = card[2];
		// a1, a2, a3 중 한 개 선택
		for (int i = 3; i < card_num; i++) {

			if (i != 3)add[i][2] = MAX3(add[i - 4][0] + card[i], add[i - 4][1] + card[i], add[i - 4][2] + card[i]);
			else add[3][2] = -9999;
			add[i][1] = MAX3(add[i - 3][0] + card[i], add[i - 3][1] + card[i], add[i - 3][2] + card[i]);
			add[i][0] = MAX2(add[i - 2][1] + card[i], add[i - 2][2] + card[i]); //add[i-2][0] 을 더하면 a1 a2 a3중 두개가 더해질 수 있음 ex 인덱스 5라면 3 2 1 중 하나 골라야.


		}
		if (card_num != 4)	result = MAX3(add[card_num - 1][0], add[card_num - 1][1], add[card_num - 1][2]);
		fprintf(out, "%d\n", result);

	}

	return 0;
}