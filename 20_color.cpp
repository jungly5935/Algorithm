#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int MIN(int a, int b)
{
	if (a < b) {
		return a;
	}
	else return b;
}

char str[2][5010]; //str[0]�� ù��° ���ڿ�, str[1]�� �� ��° ���ڿ�
int result[5003][5003];
int len1_result[5003][27] = { 0 }; //���ĺ� ���� 26��
int len2_result[5003][27] = { 0 };

FILE* out = fopen("color.out", "wt");
FILE* inp = fopen("color.inp", "rt");

int main() {
	int test;
	int str1_len, str2_len;

	fscanf(inp, "%d", &test);

	for (int t = 0; t < test; t++) {
		fscanf(inp, "%s%s", str[0] + 1, str[1] + 1);

		str[0][0] = 'x'; //ù��° ���ڿ� �ε���0�ʱ�ȭ
		str[1][0] = 'x'; //�ι�° ���ڿ� �ε���0�ʱ�ȭ

		str1_len = strlen(str[0]);
		str2_len = strlen(str[1]);

		for (int i = 0; i <= str1_len; i++) {
			for (int j = 0; j <= str2_len; j++) {
				len1_result[i][j] = 0;
				len2_result[i][j] = 0;
				result[i][j] = 9999999;
				result[0][0] = 0;
			}
		}
		//�ʱ�ȭ


		for (int i = 1; i < str1_len; i++) {
			for (int j = 0; j < 5003; j++)
			{
				len1_result[i][j] = len1_result[i - 1][j];
			}
			len1_result[i][str[0][i] - 65] += 1; //�ش��ϴ� ���� A->0�ε����� +1;
		}
		for (int i = 1; i < str2_len; i++) {
			for (int j = 0; j < 5003; j++)
			{
				len2_result[i][j] = len2_result[i - 1][j];
			}
			len2_result[i][str[1][i] - 65] += 1;
		}


		int result1;
		int result2;
		int a = 0, b = 0;
		int c = 0, d = 0;
		for (int i = 1; i <= str1_len; i++) {
			for (int j = 1; j <= str2_len; j++) {
				a = 0, b = 0, c = 0, d = 0;
				if (len1_result[i][str[0][i] - 65] + len2_result[j - 1][str[0][i] - 65] == len1_result[str1_len - 1][str[0][i] - 65] + len2_result[str2_len - 1][str[0][i] - 65])
				{
					a = i + j - 1;
				}
				if (len1_result[i - 1][str[1][j] - 65] + len2_result[j][str[1][j] - 65] == len1_result[str1_len - 1][str[1][j] - 65] + len2_result[str2_len - 1][str[1][j] - 65])
				{
					c = i - 1 + j;
				}

				if (len1_result[i][str[0][i] - 65] + len2_result[j - 1][str[0][i] - 65] == 1)
				{
					b = i + j - 1;
				}
				if (len1_result[i - 1][str[1][j] - 65] + len2_result[j][str[1][j] - 65] == 1)
				{
					d = i - 1 + j;
				}

				result1 = a - b;
				result2 = c - d;

				result[i - 1][j] = MIN(result[i - 1][j], result[i - 1][j - 1] + result2); // �ٷ� ���� ��, �밢�� �� �ε��� + result2 �� �ּ�
				result[i][j - 1] = MIN(result[i][j - 1], result[i - 1][j - 1] + result1); // �ٷ� ���� �� , �밢�� �� �ε��� + result1 �� �ּ�
			}
		}
		fprintf(out, "%d\n", result[str1_len - 1][str2_len - 1]);
	}

	fclose(out);
	fclose(inp);
	return 0;

}