#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
int main()
{
	FILE* inp = fopen("bowling.inp", "rt");
	FILE* out = fopen("bowling.out", "wt");

	int test;
	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++)
	{
		int sum[10] = { 0 };
		int bowl1, bowl2, bowl3;
		int bowl[3][10] = { 0 };
		int result = 0;

		for (int i = 0; i < 10; i++)
		{
			if (i == 9)
			{
				fscanf(inp, "%d", &bowl1);
				bowl[0][i] = bowl1;

				fscanf(inp, "%d", &bowl2);
				bowl[1][i] = bowl2;

				if (bowl[0][i] + bowl[1][i] == 10 || bowl[0][i] == 10)
				{
					fscanf(inp, "%d", &bowl3);
					bowl[2][i] = bowl3;
				}
			}
			else {
				fscanf(inp, "%d", &bowl1);
				bowl[0][i] = bowl1;
				if (bowl1 == 10)
				{
					bowl[1][i] = 0;
					continue;
				}
				fscanf(inp, "%d", &bowl2);
				bowl[1][i] = bowl2;
			}

		}//�Է�

		for (int i = 0; i < 10; i++)
		{
			if (i == 9)//����������
			{
				sum[i] = sum[i] + bowl[0][i] + bowl[1][i] + bowl[2][i];
				break;
			}
			if (bowl[0][i] == 10 && bowl[0][i + 1] == 10 && bowl[0][i + 2] == 10)//3��Ʈ����ũ�϶�
				sum[i] += 30;

			else if (bowl[0][i] == 10 && bowl[0][i + 1] == 10)//2��Ʈ����ũ�϶�
			{
				if (i == 8) sum[i] = sum[i] + 20 + bowl[1][i + 1];
				else	sum[i] = sum[i] + 20 + bowl[0][i + 2];
			}
			else if (bowl[0][i] == 10)//ù��°�� ��Ʈ����ũ�϶�
				sum[i] = sum[i] + 10 + bowl[0][i + 1] + bowl[1][i + 1];

			else if (bowl[0][i] + bowl[1][i] == 10)//������϶�
				sum[i] = sum[i] + 10 + bowl[0][i + 1];

			else //�Ѵ� �ƴҶ�
				sum[i] = sum[i] + bowl[0][i] + bowl[1][i];

		}

		for (int i = 0; i < 10; i++)
			result += sum[i];

		fprintf(out, "%d\n", result);

	}//testcase
	return 0;
}