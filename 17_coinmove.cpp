#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define max 999999
int main()
{
	FILE* out = fopen("coinmove.out", "wt");
	FILE* inp = fopen("coinmove.inp", "rt");

	int p, k, s;
	int test;
	int x, z;
	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++) {
		fscanf(inp, "%d %d %d", &p, &k, &s);
		int* X = (int*)malloc(sizeof(int) * 999999);
		int** coin;
		coin = (int**)malloc(sizeof(int*) * 999999);
		for (int i = 0; i < 999999; i++)coin[i] = (int*)malloc(sizeof(int) * 7);

		for (int i = 0; i < max; i++)X[i] = 1;
		//k������ �� �ʱ�ȭ ��Ű��
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) coin[i][j] = -1;
		}

		for (int i = 1; i < max; i++) {
			x = 1;
			for (int j = 0; j < k; j++, x++) {
				int flag = -1;
				for (z = 0; z < k; z++) { // k������ŭ (���°)�� �ε��� Ȯ��
					//�ϳ��� 1�̸� ������ -1
					//��� -1�̾�� 1
					if (i - x < 0) 	break;
					if (x - 1 == z) continue;
					//�ʱ�ȭ ����

					if (coin[i - x][z] == 1) flag = 1;
				}
				if (i - x < 0) break;
				//�ʱ�ȭ ����

				if (flag == 1) coin[i][j] = -1;
				else 	coin[i][j] = 1;
				//����1. p�� ����϶�(xǥ�����ִ°�) ��� -1�̾ coin[i][j]�� -1��

				if ((i - x != 0) && (i - x) % p == 0 && X[i - x] == 1) coin[i][j] = -1;
			}
			for (int a = 0;a < k;a++) {
				if (x - 1 == z)continue;
				if (coin[i][a] == 1) X[i] = -1; //�ϳ��� 1�������� -1, ��� -1�̸� 1
			}

		}

		//���
		int result = -1;
		for (int i = 0; i < k; i++) {
			if (coin[s][i] == 1) {
				result = s - (i + 1);
				break;
			}
		}

		fprintf(out, "%d\n", result);
	}//test

	return 0;
}