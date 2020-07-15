#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int coin[105][105][105];

int main() {
	FILE* inp = fopen("coin.inp", "rt");
	FILE* out = fopen("coin.out", "wt");

	int test;
	fscanf(inp, "%d", &test);

	int game[3];

	for (int t = 0; t < test; t++) {
		for (int i = 0;i < 3;i++)	fscanf(inp, "%d", &game[i]);
		//�Է¿� ������� ��� ��츦 ��� �� ���� ��, ���
		if (t != 0)	goto label;
		for (int i = 4; i < 105; i++) {
			for (int j = 4; j < 105; j++) {
				for (int k = 4; k < 105; k++) { // 3���� �� �ϳ��� �������� -1�̾����� 1���� ����
					coin[4][4][4] = 1; //�ʱ�ȭ
					if (coin[i - 1][j][k] == -1 || coin[i][j - 1][k] == -1 || coin[i][j][k - 1] == -1) coin[i][j][k] = 1;
					else  if (coin[i - 2][j][k] == -1 || coin[i][j - 2][k] == -1 || coin[i][j][k - 2] == -1) coin[i][j][k] = 1;
					else if (coin[i - 3][j][k] == -1 || coin[i][j - 3][k] == -1 || coin[i][j][k - 3] == -1) coin[i][j][k] = 1;
					else coin[i][j][k] = -1; // 1�̸� -1����

				}//k
			}//j
		}//i

	label:
		int result = coin[game[0] + 4][game[1] + 4][game[2] + 4];
		fprintf(out, "(%d %d %d) : %d\n", game[0], game[1], game[2], result); //i, j, k= 4���� �����ϹǷ�
	}
	return 0;
}