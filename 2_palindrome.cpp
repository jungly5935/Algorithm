#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
#pragma warning (disable:4996)
int main()
{
	FILE* inp = fopen("palindrome.inp", "rt");
	FILE* out = fopen("palindrome.out", "wt");

	int test;
	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++)
	{

		char* text = (char*)malloc(sizeof(char) * 1003);
		char* text2 = (char*)malloc(sizeof(char) * 1003);
		char* txt = (char*)malloc(sizeof(char) * 1003);
		char* updown = (char*)malloc(sizeof(char) * 1003);
		int** lcs = (int**)malloc(sizeof(int*) * 1003);
		int flag = -1;
		int j;

		for (int i = 0; i < 1003; ++i)
		{
			lcs[i] = (int*)malloc(1003 * sizeof(int));
			for (int j = 0; j < 1003; ++j) lcs[i][j] = 0;
		}

		fgetc(inp);
		fscanf(inp, "%s", text);
		int k = strlen(text);//문자열길이

		updown[0] = '0';
		text2[0] = '0';
		for (int i = k - 1, j = 0; i >= 0; i--, j++)
		{
			updown[j + 1] = text[i]; //text문자 거꾸로
			txt[j] = text[i];
		}
		for (int i = 0; i < k; i++) {
			text2[i + 1] = text[i];
		}
		k++;
		int len1 = k, len2 = k;
		updown[k] = '\0';
		text2[k] = '\0';
		//lcs
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (i == 0 || j == 0) {
					lcs[i][j] = 0;
					continue;
				}
				if (text2[i] == updown[j])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else {
					if (lcs[i - 1][j] > lcs[i][j - 1])
						lcs[i][j] = lcs[i - 1][j];
					else
						lcs[i][j] = lcs[i][j - 1];
				}
			}
		}
		if ((len2 - 1) - lcs[len1 - 1][len2 - 1] <= 2)
			fprintf(out, "%d\n", (len2 - 1) - lcs[len1 - 1][len2 - 1]);
		else
			fprintf(out, "-1\n");

		free(lcs);
		free(text);
		free(text2);
		free(updown);
	}//testcase
	return 0;
}